#ifndef DATASET_H
#define DATASET_H

#include "common.h"
#include "slam_core/frame.h"
#include "slam_core/camera.h"
#include <opencv2/imgcodecs.hpp> // 读取图像用
#include <opencv2/imgproc.hpp>
#include <boost/format.hpp> // 规定路径格式用
#include <sys/stat.h> // 用于文件存在性检查

// 数据集类，用以实现图像数据队列的读取
class Dataset {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        typedef std::shared_ptr<Dataset> Ptr;
        Dataset(const std::string& dataset_path);

        // 初始化，返回是否成功
        bool Init();
        
        // 加载下一帧图像
        Frame::Ptr loadNextFrame(cv::Mat image_left, cv::Mat image_right); // 因为是两张图像，所以用frame的智能指针
    
        // get camera by id
        Camera::Ptr GetCamera(int camera_id) const {
            return cameras_.at(camera_id);
        }

    private:
        int current_index_ = 0;
        std::string dataset_path_; // 注意下划线位置要和.cpp中声明:后的变量一致

        std::vector<Camera::Ptr> cameras_;

};

#endif
