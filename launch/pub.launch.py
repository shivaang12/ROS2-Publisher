import launch
import launch.actions
import launch.substitutions
import launch_ros.actions


def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='ros2_publisher', node_executable='ros2_pub', output='screen',
            node_name=['talker']),
    ])
