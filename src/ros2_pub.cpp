#include <utility>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class Ros2Pub:public rclcpp::Node{
public:
    Ros2Pub():Node("ROS2_PUB"){
        Pub_ = this->create_publisher<std_msgs::msg::String>("Chatter", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&Ros2Pub::pub_function, this));

    }

private:
    void pub_function(){
        auto msg = std_msgs::msg::String();
        msg.data = "HII";
        RCLCPP_INFO(this->get_logger(), "PUBLISHING");
        Pub_->publish(msg);
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr Pub_;
    rclcpp::TimerBase::SharedPtr timer_;

};

auto main(int argc, char* argv[]) -> int{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Ros2Pub>());
    rclcpp::shutdown();
    return 0;
}