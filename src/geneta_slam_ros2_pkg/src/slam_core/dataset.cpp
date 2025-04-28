#include "slam_core/dataset.h"

Dataset::Dataset(const std::string& dataset_path)
    : dataset_path_(dataset_path) {}

bool Dataset::Init() {
    // 读取数据集中的初始标定数据，并初始化camera，使其非空
    std::ifstream fin(dataset_path_ + "/calib.txt");
    if (!fin) {
        std::cout << "cannot find " << dataset_path_ << "/calib.txt!" << std::endl;
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        char camera_name[3];
        for (int k = 0; k < 3; ++k) {
            fin >> camera_name[k];
        }
        double projection_data[12];
        for (int k = 0; k < 12; ++k) {
            fin >> projection_data[k];
        }
        Mat33 K;
        K << projection_data[0], projection_data[1], projection_data[2],
            projection_data[4], projection_data[5], projection_data[6],
            projection_data[8], projection_data[9], projection_data[10];
        Vec3 t;
        t << projection_data[3], projection_data[7], projection_data[11];
        t = K.inverse() * t;
        K = K * 0.5;
        Camera::Ptr new_camera(new Camera(K(0, 0), K(1, 1), K(0, 2), K(1, 2),
                                          t.norm(), SE3(SO3(), t)));
        cameras_.push_back(new_camera);
        // LOG(INFO) << "Camera " << i << " extrinsics: " << t.transpose();
    }
    fin.close();
    current_index_ = 0;
    return true;
}

Frame::Ptr Dataset::loadNextFrame(cv::Mat image_left, cv::Mat image_right) {
    if (image_left.data == nullptr || image_right.data == nullptr) {   // 判断指定路径图片是否存在
        std::cout << "cannot load images:" << current_index_ << std::endl;
        return nullptr;
    }

    auto new_frame = Frame::CreateFrame();
    new_frame->left_img_ = image_left;
    new_frame->right_img_ = image_right;
    
    current_index_++; //图片读取完毕,id+1,这个id是私有变量不对外
    return new_frame;
}