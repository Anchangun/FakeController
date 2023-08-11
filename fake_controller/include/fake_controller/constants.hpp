#ifndef FAKE_CONTROLLER__CONSTANTS__HPP_
#define FAKE_CONTROLLER__CONSTANTS__HPP_
#include "df_ros_topic.hpp"
#include <string>

class Constants{
    public :
        const std::string odom_frame_id_;
        const std::string child_frame_id_;
        const std::string pub_odom_name_;
        const float fake_move_;
        const int pub_odom_queue_size_;
        const int pub_odom_time_;
        Constants();
};

#endif 