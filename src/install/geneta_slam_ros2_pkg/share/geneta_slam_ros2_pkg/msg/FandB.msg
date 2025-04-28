# 基础信息头（时间戳+坐标系）
std_msgs/Header header

# 特征点信息
# int32[] frame_ids         # 当前帧的ID
# int32[] feature_ids       # 特征点ID数组
# int32[] belong_landmark_ids      # 持有该特征点的路标点ID数组
float32[] u       # 特征点图像坐标X
float32[] v       # 图像坐标Y

# 对应路标点信息（世界坐标系）
int32[] landmark_ids       # 路标点ID
float64[] x                # 三维坐标X
float64[] y                # Y
float64[] z                # Z

# 里程计数据（位置+方向）
geometry_msgs/Pose pose

# uint32 seq_id