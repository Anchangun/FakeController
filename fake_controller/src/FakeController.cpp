#include"FakeController.hpp"

FakeController::FakeController():Node("FakeControllerNode"){
    rclcpp::PublisherOptions pub_odom_options;
    check_ = false;
    
    constants_ = std::make_unique<Constants>();
    
    cb_group_odom_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    
    pub_odom_options.callback_group = cb_group_odom_;
    pub_odom_ = this->create_publisher<nav_msgs::msg::Odometry>(constants_->pub_odom_name_, constants_->pub_odom_queue_size_,pub_odom_options);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(constants_->pub_odom_time_),std::bind(&FakeController::pub_odometry,this));
    tf_timer_ = this->create_wall_timer(std::chrono::milliseconds(100),std::bind(&FakeController::update_transform,this));

}

void FakeController::pub_odometry(){
	nav_msgs::msg::Odometry odom;
    odom.header.frame_id = constants_->odom_frame_id_;
    odom.child_frame_id = constants_->child_frame_id_;
    odom.header.stamp = this->now();
    if(check_){
        check_= false;
        odom.pose.pose.position.x+=constants_->fake_move_;
        lo_x_= odom.pose.pose.position.x;
    }
    else {
        check_= true;
        odom.pose.pose.position.x-=constants_->fake_move_;
        lo_x_= odom.pose.pose.position.x;
    }
    	pub_odom_->publish(odom);

}

FakeController::~FakeController(){

}

void FakeController::update_transform(){
	geometry_msgs::msg::TransformStamped odom_trans;
	odom_trans.header.frame_id = constants_->odom_frame_id_;
	odom_trans.child_frame_id = constants_->child_frame_id_;
	std::unique_ptr<tf2_ros::TransformBroadcaster> broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(this);
	odom_trans.header.stamp = this->now();	
    
	odom_trans.transform.translation.x = lo_x_;
	broadcaster->sendTransform(odom_trans); 
}