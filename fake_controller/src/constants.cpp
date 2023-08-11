#include "constants.hpp"
Constants::Constants(): 
    odom_frame_id_(ODOM_FRAME_ID),
    child_frame_id_(CHILD_FRAME_ID),
    pub_odom_name_(PUB_ODOM_NAME),
    fake_move_(FAKE_MOVE),
    pub_odom_queue_size_(PUB_ODOM_QUEUE_SIZE),
    pub_odom_time_(PUB_ODOM_TIME)
{

}