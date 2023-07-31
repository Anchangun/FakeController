#ifndef FAKE_CONTROLLER__HPP_
#define FAKE_CONTROLLER__HPP_

// cpp header
#include <iostream>
#include <functional>
#include <memory>

// ros2 header
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2_ros/transform_broadcaster.h"

class FakeController : public rclcpp::Node{
    private :
        // rclcpp / timer 
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::TimerBase::SharedPtr tf_timer_;
        rclcpp::CallbackGroup::SharedPtr cb_group_odom_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pub_odom_;
        bool check_;
        float lo_x_;
        /**
         * @brief 
         * 
         */
        void pub_odometry();
        void update_transform();
    public :
        FakeController();
        virtual ~FakeController();
};

#endif