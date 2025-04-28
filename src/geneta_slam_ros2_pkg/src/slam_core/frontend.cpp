#include "slam_core/frontend.h"

Frontend::Frontend() : Node("geneta_frontend") {
     std::cout << "Frontend running" << std::endl;
     // 订阅图像话题（需与发布者一致，话题名称一致）
     left_sub_.subscribe(this, "Geneta_Image_left");
     right_sub_.subscribe(this, "Geneta_Image_right");

     // 同步器初始化（ROS2必须显式构造）
     sync_.reset(new message_filters::Synchronizer<SyncPolicy>(
          SyncPolicy(10),  // 队列长度参数
          left_sub_, 
          right_sub_));

     // 注册回调（使用std::placeholders占位符）
     sync_->registerCallback(
          std::bind(&Frontend::frontend_callback, this,
               std::placeholders::_1, 
               std::placeholders::_2));

     // 发布位姿及地图点话题（需与发布者一致，话题名称一致），tf2广播
     pose_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("fontend_odom", 10);
     map_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("frontend_map", 10);
     path_pub_ = this->create_publisher<nav_msgs::msg::Path>("frontend_path", 10);
     tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

     // 自定义消息
     FandB_pub_ = this->create_publisher<geneta_slam_ros2_pkg::msg::FandB>("FandB", 10);
}

bool Frontend::NodeInit() {
     // 设置数据集的config文件路径
     dataset_ = Dataset::Ptr(new Dataset("/home/geneta/Project/00"));
     if(!dataset_->Init()) {
          return false;
     }

     SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1));
     SetMap(map_);
     return true;
}

void Frontend::frontend_callback(const sensor_msgs::msg::Image::ConstSharedPtr& left_msg,
     const sensor_msgs::msg::Image::ConstSharedPtr& right_msg) {
     if(frontend_cnt==0) {
          // 初始化
          if (!NodeInit()) {
               RCLCPP_ERROR(get_logger(), "SLAM_CORE节点初始化失败,关闭节点");
               rclcpp::shutdown();
          }
          frontend_cnt++;
     }

     // 时间戳一致性检查
     if (abs(left_msg->header.stamp.sec - right_msg->header.stamp.sec) > 0.001) {
          RCLCPP_WARN(get_logger(), "双目时间戳差异超过1ms");
          return;
     }
     
     // 双图像转换
     cv_bridge::CvImagePtr left_cv = cv_bridge::toCvCopy(left_msg, "bgr8");
     cv_bridge::CvImagePtr right_cv = cv_bridge::toCvCopy(right_msg, "bgr8");

     // 灰度化处理
     cv::Mat left_gray, right_gray;
     cv::cvtColor(left_cv->image, left_gray, cv::COLOR_BGR2GRAY);
     cv::cvtColor(right_cv->image, right_gray, cv::COLOR_BGR2GRAY);

     // 帧数据加载
     Frame::Ptr frame = dataset_->loadNextFrame(left_gray, right_gray);
     auto t1 = std::chrono::steady_clock::now(); // 算法计时 
     Calculate(frame);
     auto t2 = std::chrono::steady_clock::now();
     auto time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
     std::cout << "GenetaSLAM Frontend cost time: " << time_used.count() << " seconds." << std::endl;

     // 只有当当前帧为关键帧时，才封装为rviz2消息并发布给后端
     if(current_frame_->is_keyframe_) {
          odom_msg_->header.stamp = this->get_clock()->now(); // 转换为Odometry消息
          odom_msg_->header.frame_id = "odom";
          odom_msg_->child_frame_id = "base_link";
          pose_pub_->publish(*odom_msg_); // 发布odom

          transform.header.stamp = this->now();     // tf2
          transform.header.frame_id = "odom";       // 父坐标系
          transform.child_frame_id = "base_link";    // 子坐标系
          tf_broadcaster_->sendTransform(transform); // 发布tf2
     
          path_msg_->header.stamp = this->now(); // 自定义消息
          path_msg_->header.frame_id = "odom";
          path_pub_->publish(*path_msg_); // 发布path

          FandB_msg_.header.stamp = this->get_clock()->now();
          FandB_msg_.header.frame_id = "odom";
          FandB_pub_->publish(FandB_msg_); // 发布自定义消息
     }
}

bool Frontend::Calculate(Frame::Ptr frame) { // 输入接口为自定义的Frame类   
     current_frame_ = frame; // 当前帧
     switch (status_) {
         case FrontendStatus::INIT:
             Init(); // 进行数据初始化
             break;
         case FrontendStatus::TRACK:
             Track(); // 进行光流追踪、位姿估计（必要时刻插入关键帧）
             break;
     }

     insert_key_flag = !insert_key_flag; // 隔一帧插入

     // if(current_frame_->is_keyframe_) { // 若为关键帧则进行插入
     //      backend_->InsertNewKeyFrame(current_frame_); // 后端地图插入关键帧
     //      backend_->Wake(); // 激活后端更新，后端只优化关键帧 
     //  }

     // 封装位姿信息
     PosePublishPack();

     last_frame_ = current_frame_; // 变为过去帧
     return true;
 }
 
 bool Frontend::Init() {
     // loop_->SetBackend(backend_);
     // backend_->SetLoopclosing(loop_); // 回环和后端线程相互连接，方便传输回环数据

     camera_left_->fx_ = 517.3; // 设置左相机内参
     camera_left_->fy_ = 516.5;
     camera_left_->cx_ = 325.1;
     camera_left_->cy_ = 249.7;

     camera_right_->fx_ = 517.3; // 设置右相机内参
     camera_right_->fy_ = 516.5;
     camera_right_->cx_ = 325.1;
     camera_right_->cy_ = 249.7;

     SE3 init_left_pose = Sophus::SE3d();
     Sophus::SE3d translation_transform(
         Sophus::SO3d(), 
         Eigen::Vector3d(0.54, 0.0, 0.0) // 左右目距离为0.54m
     );
     Sophus::SE3d init_right_pose = init_left_pose * translation_transform;

     DetectLeftFeatures(); // 进行左图中特征点检测
     FindRightFeatures(); // 进行右图中特征点的光流追踪

     camera_left_->pose_ = init_left_pose; // 设置初始帧左目图像的位姿为单位阵
     camera_right_->pose_ = init_right_pose;
     current_frame_->SetPose(init_left_pose);

     if (MapInit()) { // 地图初始化并且成功
         status_ = FrontendStatus::TRACK; // 切换前端工作状态码

         current_frame_->SetKeyFrame(); // 设第一帧为关键帧
         
         // loop_->SetMap(map_); // 将地图传输给回环
         // loop_->Wake(); // 激活回环检测

         // backend_->SetCameras(camera_left_, camera_right_); // 将相机左右的位姿（实际上只要左右相对的位姿即可）赋给空指针

         // 给viewer和backend提供初始地图信息，进行一次即可
         // backend_->SetMap(map_);
         
         return true;
     }

     return false;
 }

 int Frontend::DetectLeftFeatures() {
     // 使用GFTT描述子进行图像特征检测,特征点数量参数从yaml文件中加载      
     // cv::Ptr<cv::GFTTDetector> gftt = cv::GFTTDetector::create(Config::Get<int>("num_features"), 0.01, 30); // 质量阈值，特征点最小间距，参数需要进行适当调整

     // 这个是FAST检测
     // cv::Ptr<cv::FastFeatureDetector> fast = cv::FastFeatureDetector::create(80); 
     // fast->setNonmaxSuppression(true);

     // 这个是ORB检测
     cv::Ptr<cv::ORB> orb = cv::ORB::create(num_features_, 1.2, 8);

     std::vector<cv::KeyPoint> keypoints;
     cv::Mat descriptors; // ORB

     int cnt_detected = 0;
     // gftt->detect(current_frame_->left_img_, keypoints); // 将提取到的特征点注入到对应帧的类参数当中去
     // fast->detect(current_frame_->left_img_, keypoints); // FAST
     orb->detectAndCompute(current_frame_->left_img_, cv::Mat(), keypoints, descriptors); // ORB
     current_frame_->SetDescriptors(descriptors); // 将ORB特征描述子进行传递

     for(auto &kp: keypoints){
         current_frame_->features_left_.push_back(
             Feature::Ptr(new Feature(current_frame_, kp)));
         cnt_detected ++;
     }
     // std::cout << "Detect " << cnt_detected << " new features" << std::endl; // 输出检测的特征点数量
     return cnt_detected;
 }

 int Frontend::FindRightFeatures() {
     std::vector<cv::Point2f> kps_left, kps_right;
     for(auto &kp : current_frame_->features_left_) {  // 在非关键帧过程中这里的features_left_由上一帧追踪而来，所以有可能是空指针，注意判断
         if (kp) {
             kps_left.push_back(kp->position_.pt); // 注意指针形式，kp是一个feature类，要注入的是feature类中特征点的2D位置数据         
             auto mp = kp->map_point_.lock();
             if (mp) {
                 auto px = camera_right_->world2pixel(mp->pos_, current_frame_->Pose());
                 kps_right.push_back(cv::Point2f(px[0], px[1])); // 使用投影点作为初始值
             } else {   
                 kps_right.push_back(kp->position_.pt); // 使用左图中相同的坐标作为初始值
             }  
         }
     }

     std::vector<uchar> status;
     std::vector<float> err;
     cv::calcOpticalFlowPyrLK(
         current_frame_->left_img_, current_frame_->right_img_,      // 利用光流法检测匹配左图的右图特征点,注意两张图必须灰度图,不能在之前显示彩点啥的
         kps_left, kps_right,    // 输入/输出特征点
         status, err,            // 跟踪状态，追到为1，没追到为0，和误差
         cv::Size(11, 11),       // 搜索窗口尺寸
         3,                      // 金字塔层数
         cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01),
         cv::OPTFLOW_USE_INITIAL_FLOW // 使用初始值是否会更好？
     );
     
     int num_good_kps = 0;
     for(size_t i = 0;i < status.size(); i++) {
         if(status[i]) {
             cv::KeyPoint kp(kps_right[i], 7); // 创建一个大小为7的关键点
             Feature::Ptr feat(new Feature(current_frame_, kp));
             feat->is_on_left_image_ = false; // 标记特征点提在右图
             current_frame_->features_right_.push_back(feat);
             num_good_kps++;
         }
         else {
             current_frame_->features_right_.push_back(nullptr); // 若不能匹配，则为空，保持左右匹配点的vector对齐，方便查找匹配
         }
     }

     // std::cout << "Detect " << num_good_kps << " good features in right frame" << std::endl; // 输出在右目图像中可追踪到的特征点数量
     return num_good_kps;
 }

int Frontend::LKDetectLastFeatures() {
     std::vector<cv::Point2f> kps_last, kps_current;
     for (auto &kp : last_frame_->features_left_) {
          if (kp) {
               if (kp->map_point_.lock()) {
                    auto mp = kp->map_point_.lock();
                    auto px = camera_left_->world2pixel(mp->pos_, current_frame_->Pose()); // 使用投影坐标
                    kps_last.push_back(kp->position_.pt);  // 上一帧左图的特征点
                    kps_current.push_back(cv::Point2f(px[0], px[1]));
               } else {
                    kps_last.push_back(kp->position_.pt); 
                    kps_current.push_back(kp->position_.pt);
               }
          }
     }

     std::vector<uchar> status;
     std::vector<float> err;
     cv::calcOpticalFlowPyrLK(
          last_frame_->left_img_, current_frame_->left_img_, // 根据上一帧来追踪现在这一帧特征点
          kps_last, kps_current,   
          status, err,            
          cv::Size(11, 11),       
          3,                     
          cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01),
          cv::OPTFLOW_USE_INITIAL_FLOW // 使用初始值是否会更好？
     );

     int num_good_kps = 0;
     for(size_t i = 0;i < status.size(); i++) {
          if(status[i]) {
               cv::KeyPoint kp(kps_current[i], 7); // 创建一个大小为7的关键点
               Feature::Ptr feature(new Feature(current_frame_, kp));
               current_frame_->features_left_.push_back(feature); // 将光流追踪后的特征点注入当前左图特征点
                                                                 // 很有深意，当光流法追丢时，需要重新进行GFTT检测
               feature->map_point_ = last_frame_->features_left_[i]->map_point_; // 将上一帧特征点对应地图点插入对应下一帧地图点
               num_good_kps++;
          }  // 注意追踪上一帧得到结果没有填充nullptr
     }
     // std::cout << "Detect " << num_good_kps << " good features in last frame" << std::endl; // 输出在右目图像中可追踪到的特征点数量
     return num_good_kps;
}

int Frontend::BACurrentPose() {
     // 构建图优化，先设定g2o
     // typedef g2o::BlockSolver_6_3 BlockSolverType;
     // typedef g2o::LinearSolverCSparse<BlockSolverType::PoseMatrixType> LinearSolverType; // 线性求解器类型

     // auto solver = new g2o::OptimizationAlgorithmLevenberg( // 设置优化算法，求解器
     //      std::make_unique<BlockSolverType>(std::make_unique<LinearSolverType>()));

     typedef g2o::BlockSolver_6_3 BlockSolverType;
     typedef g2o::LinearSolverCholmod<BlockSolverType::PoseMatrixType> LinearSolverType;  // 替换求解器类型

     auto solver = new g2o::OptimizationAlgorithmLevenberg(
          std::make_unique<BlockSolverType>(std::make_unique<LinearSolverType>()));      

     g2o::SparseOptimizer optimizer;
     optimizer.setAlgorithm(solver);

     // 顶点设置
     VertexPose *vertex_pose = new VertexPose();  // 相机位姿顶点
     vertex_pose->setId(0);
     vertex_pose->setEstimate(current_frame_->Pose()); // 设置顶点初始值为上一帧的位姿（不产生大机动）
     optimizer.addVertex(vertex_pose); // 加入顶点

     // 相机内参矩阵
     Mat33 K = camera_left_->K();

     // 边设置
     int index = 1;
     std::vector<EdgeProjectionPoseOnly *> edges; // 自带一元边，仅优化相机位姿，把3D点坐标作为固定参数
     std::vector<Feature::Ptr> features;

     for (size_t i = 0; i < current_frame_->features_left_.size(); ++i) {  // 有多少特征点就有多少条边，一个位姿顶点对n个特征点
          auto mp = current_frame_->features_left_[i]->map_point_.lock(); // 若存在三角化后的地图点
          
          if (mp) {
               features.push_back(current_frame_->features_left_[i]);
               EdgeProjectionPoseOnly *edge = new EdgeProjectionPoseOnly(mp->pos_, K); // 传入世界坐标以及内参矩阵 
               edge->setId(index); // 注意这里的index要和顶点id错开
               edge->setVertex(0, vertex_pose);
               edge->setMeasurement(
                    toVec2(current_frame_->features_left_[i]->position_.pt)); // 把特征点的两个坐标x\y转换为二维量测信息?
               edge->setInformation(Eigen::Matrix2d::Identity());
               edge->setRobustKernel(new g2o::RobustKernelHuber); // 使用Huber鲁棒核函数
               edges.push_back(edge);
               optimizer.addEdge(edge);
               index++;
          }
     }

     auto t1 = std::chrono::steady_clock::now(); // 算法计时 

     // 开始进行位姿的BA优化
     const double chi2_th = 5.991;
     int cnt_outlier = 0;
     for (int iteration = 0; iteration < 4; iteration++) {   // 进行4次迭代，每次迭代优化10次
          vertex_pose->setEstimate(current_frame_->Pose());
          optimizer.initializeOptimization();
          optimizer.optimize(10);
          cnt_outlier = 0;

          // 判定优化中的异常值
          for (size_t i = 0; i < edges.size(); ++i) {
               auto e = edges[i];
               if (features[i]->is_outlier_) {
                    e->computeError();
               }
               if (e->chi2() > chi2_th) { // 计算误差大于阈值，判断为异常值，采用分层机制，分层进行优化
                    features[i]->is_outlier_ = true;
                    e->setLevel(1); // 优化层级降为1
                    cnt_outlier++; // 异常值计数
               } else {
                    features[i]->is_outlier_ = false;
                    e->setLevel(0); // 优化层级保持为0，优先进行
               };

               if (iteration >= 2) { // 鲁棒核函数后期作用有限
                    e->setRobustKernel(nullptr);
               }
          }
     }

     auto t2 = std::chrono::steady_clock::now();
     auto time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
     std::cout << "GenetaSLAM BA cost time: " << time_used.count() << " seconds." << std::endl;

     // std::cout << "Outlier/Inlier in pose estimating: " << cnt_outlier << "/"
     //           << features.size() - cnt_outlier << std::endl;

     // 优化结果输出到当前帧的位姿
     current_frame_->SetPose(vertex_pose->estimate());

     // std::cout << "Current Pose = \n" << current_frame_->Pose().matrix() << std::endl  << std::endl;

     // for (auto &feat : features) {
     //     if (feat->is_outlier_) {
     //         feat->map_point_.reset();
     //         feat->is_outlier_ = false;  // maybe we can still use it in future
     //     }
     // }
     return features.size() - cnt_outlier; // 返回剔除异常点的计数
}

int Frontend::Triangulation() {
     std::vector<SE3> poses{camera_left_->pose(), camera_right_->pose()};
     int cnt_triangulated_pts = 0;
     SE3 current_pose_Twc = current_frame_->Pose().inverse(); // 相机坐标系转换为世界坐标系

     // std::cout << poses[0].matrix() << std::endl; // 测试用查看传入的位姿矩阵

     for (size_t i = 0; i < current_frame_->features_right_.size(); i++) { // 这里左右无所谓，因为size是一样的
          if (current_frame_->features_right_[i] == nullptr) continue;  // 保证右图匹配点存在
          std::vector<Vec3> points {                                        
               camera_left_->pixel2camera(                                   // 像素点转换为归一化平面（相机）点，便于三角化
                    Vec2(current_frame_->features_left_[i]->position_.pt.x,
                         current_frame_->features_left_[i]->position_.pt.y)),
               camera_right_->pixel2camera(
                    Vec2(current_frame_->features_right_[i]->position_.pt.x,
                         current_frame_->features_right_[i]->position_.pt.y))};

          Vec3 pt_world = Vec3::Zero();
          if (triangulation(poses, points, pt_world) && pt_world[2] > 0) { // 进行三角化，同时判断三角化后三维点数值的有效性
               auto new_map_point = MapPoint::CreateNewMappoint();
               pt_world = current_pose_Twc * pt_world; /// 不知道要不要加
               new_map_point->SetPos(pt_world);     // 设置地图点
               map_->InsertMapPoint(new_map_point); // 将地图点插入地图

	          // backend_->InsertNewMapPoint(new_map_point); // 将地图点插入后端地图

               current_frame_->features_left_[i]->map_point_ = new_map_point; // 地图点和左右图像特征点匹配
               current_frame_->features_right_[i]->map_point_ = new_map_point;

               cnt_triangulated_pts++; // 三角化成功
	        }

	    }
        
	    // std::cout << "Triangulated successful with " << cnt_triangulated_pts
	    //           << " map points" << std::endl;

	     return cnt_triangulated_pts;
}

bool Frontend::MapInit() {
     std::vector<SE3> poses{camera_left_->pose(), camera_right_->pose()};
     size_t cnt_init_landmarks = 0;
     for (size_t i = 0; i < current_frame_->features_left_.size(); ++i) {
          if (current_frame_->features_right_[i] == nullptr) continue; // 跳过不能追踪到右图特征点的情况

          // 三角化创建初始新地图
          std::vector<Vec3> points{           // 像素点转换为归一化平面（相机）点，便于三角化
               camera_left_->pixel2camera(
                    Vec2(current_frame_->features_left_[i]->position_.pt.x,
                         current_frame_->features_left_[i]->position_.pt.y)),
               camera_right_->pixel2camera(
                    Vec2(current_frame_->features_right_[i]->position_.pt.x,
                         current_frame_->features_right_[i]->position_.pt.y))};
            
            Vec3 pworld = Vec3::Zero();
    
            if (triangulation(poses, points, pworld) && pworld[2] > 0) { // 三角化并判断是否有效
               auto new_map_point = MapPoint::CreateNewMappoint();
               new_map_point->SetPos(pworld);
               new_map_point->AddObservation(current_frame_->features_left_[i]); // 将左图特征点存储到对应的地图点观测当中
               new_map_point->AddObservation(current_frame_->features_right_[i]);

               // backend_->InsertNewMapPoint(new_map_point); // 将地图点插入后端地图

               current_frame_->features_left_[i]->map_point_ = new_map_point;  // 地图点和左右图像特征点匹配
               current_frame_->features_right_[i]->map_point_ = new_map_point;
               cnt_init_landmarks++;
            }
        }
    
        // std::cout << "Initial map created with " << cnt_init_landmarks
        //           << " map points" << std::endl;
    
        return true;
    }

int Frontend::Track() {
     current_frame_->SetPose(relative_motion_ * last_frame_->Pose()); // 用上一时刻的相对运动和世界坐标位姿来估计当前帧的世界位姿
     LKDetectLastFeatures(); // 光流法追踪上一帧检测位姿

     num_track_good_ = BACurrentPose(); // BA计算PnP问题，并返回正常优化的点数 current_frame_->Pose()值在这里更新


     if(num_track_good_ < num_features_tracking_) { // 正常优化点数小于允许值，重新检测特征子并三角化
          ReTrack();
     } 

     else {  
          if(insert_key_flag) { // 隔一普通帧帧插入一个关键帧        
               current_frame_->SetKeyFrame();   // 当前帧设置为关键帧
          }
          relative_motion_ = current_frame_->Pose() * last_frame_->Pose().inverse(); // 计算相对运动
     }

     return num_track_good_;
}

void Frontend::ReTrack() {
     relative_motion_ = current_frame_->Pose() * last_frame_->Pose().inverse();

     // 清空之前优化不好的特征点
     std::vector<std::shared_ptr<Feature>>().swap(current_frame_->features_left_);

     DetectLeftFeatures(); // 重新进行GFTT检测
     FindRightFeatures();
     Triangulation(); // 对关键帧特征点进行三角化

     // 插入关键帧
     current_frame_->SetKeyFrame();   // 当前帧设置为关键帧
     // std::cout << "keyframe id:" << current_frame_->keyframe_id_ << std::endl; // 测试用检查关键帧id
     // std::cout << "frame id:" << current_frame_->id_ << std::endl; // 测试用检查帧id

     // loop_->SetMap(map_); // 将地图传输给回环
     // loop_->Wake(); // 激活回环检测
}

void Frontend::PosePublishPack() {
     // 获取优化后的位姿
     Sophus::SE3d current_pose = current_frame_->Pose();
     
     // 位姿转换（Sophus到ROS消息）
     Eigen::Vector3d translation = current_pose.translation();
     Eigen::Quaterniond quat = current_pose.unit_quaternion();
     
     // odometry
     odom_msg_->pose.pose.position.x = translation.x();
     odom_msg_->pose.pose.position.y = translation.y();
     odom_msg_->pose.pose.position.z = translation.z();
     odom_msg_->pose.pose.orientation.x = quat.x();
     odom_msg_->pose.pose.orientation.y = quat.y();
     odom_msg_->pose.pose.orientation.z = quat.z();
     odom_msg_->pose.pose.orientation.w = quat.w();

     // tf2
     transform.transform.translation.x = translation.x();
     transform.transform.translation.y = translation.y();
     transform.transform.translation.z = translation.z();
     transform.transform.rotation.x = quat.x();
     transform.transform.rotation.y = quat.y();
     transform.transform.rotation.z = quat.z();
     transform.transform.rotation.w = quat.w();

     // path
     path_stamped.pose.position.x = odom_msg_->pose.pose.position.x;
     path_stamped.pose.position.y = odom_msg_->pose.pose.position.y;
     path_stamped.pose.position.z = odom_msg_->pose.pose.position.z;
     path_stamped.pose.orientation = odom_msg_->pose.pose.orientation;
     path_msg_->poses.push_back(path_stamped);

     // frontend and backend
     // 填充特征点数据
     for (auto &feat : current_frame_->features_left_) {
          if (feat && feat->map_point_.lock()) {
               auto mp = feat->map_point_.lock();
               // FandB_msg_.feature_ids.push_back(feat->id_);
               FandB_msg_.u.push_back(feat->position_.pt.x);
               FandB_msg_.v.push_back(feat->position_.pt.y);
               
               FandB_msg_.landmark_ids.push_back(mp->id_);
               FandB_msg_.x.push_back(mp->pos_.x());
               FandB_msg_.y.push_back(mp->pos_.y());
               FandB_msg_.z.push_back(mp->pos_.z());
          }
     }

     // 填充位姿（复用原PosePublishPack逻辑）
     FandB_msg_.pose.position.x = translation.x();
     FandB_msg_.pose.position.y = translation.y();
     FandB_msg_.pose.position.z = translation.z();
     FandB_msg_.pose.orientation.x = quat.x();
     FandB_msg_.pose.orientation.y = quat.y();
     FandB_msg_.pose.orientation.z = quat.z();
     FandB_msg_.pose.orientation.w = quat.w();
}

int main(int argc, char * argv[]) {
     rclcpp::init(argc, argv);
     rclcpp::spin(std::make_shared<Frontend>());
     rclcpp::shutdown();
     return 0;
 }