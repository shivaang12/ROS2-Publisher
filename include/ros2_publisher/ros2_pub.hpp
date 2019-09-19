/**
 * @file    ros2_pub.hpp
 * @author  Shivang Patel
 * @copyright   MIT License (c) 2019 Shivang Patel
 * 
 * @brief DESCRIPTION
 * This header file contains simple class definition of ROS2 Publisher in a new 
 * recommended style. It can also be used as boilerplate for ROS2 publisher.
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

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/**
 * @brief Class which implements ROS2 publisher. This method used inheritance
 * instead of composition. It inherits from rclcpp::Node class.
 * 
 */

class Ros2Pub:public rclcpp::Node{
public:
    /**
     * @brief Contructor of the class.
     * 
     * @param[in]   None
     * 
     * @return  None
     */
    Ros2Pub(void);   

private:
    /**
     * @brief Publisher Fuction.
     * 
     * @param[in]   None
     * 
     * @return  Void
     */
    auto pub_function() -> void;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr Pub_;   //> Pointer to
                                                                // Publisher
    rclcpp::TimerBase::SharedPtr timer_;    //> Pointer to time
};