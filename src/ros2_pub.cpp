/**
 * @file    ros2_pub.cpp
 * @author  Shivang Patel
 * @copyright   MIT License (c) 2019 Shivang Patel
 * 
 * @brief DESCRIPTION
 * This file contains implementation of Ros2Pub class.
 * 
 * Copyright 2019 Shivang Patel
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#include <utility>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <ros2_publisher/ros2_pub.hpp>

using namespace std::chrono_literals;

Ros2Pub::Ros2Pub(void):Node("ROS2_PUB"){
    Pub_ = this->create_publisher<std_msgs::msg::String>("Chatter", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&Ros2Pub::pub_function, this));
}

void Ros2Pub::pub_function() {
    auto msg = std_msgs::msg::String();
    msg.data = "HII";
    RCLCPP_INFO(this->get_logger(), "PUBLISHING");
    Pub_->publish(msg);
}