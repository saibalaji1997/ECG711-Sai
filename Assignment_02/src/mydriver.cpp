#include <ros/ros.h>
//#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Pose2D.h>


int main(int argc, char **argv) {
  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "driver_node");
  ros::NodeHandle nh;

  // Create a publisher object.
  ros::Publisher pub = nh.advertise<geometry_msgs::Pose2D>(
    "goal_pose", 2);

  // Seed the random number generator.
  srand(time(0));

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);
  while(ros::ok()) {
    // Create and fill in the message.  The other four
    // fields, which are ignored by turtlesim, default to 0.
    geometry_msgs::Pose2D goalPose;

    goalPose.x = 5;
    goalPose.y = 5;
    goalPose.theta = 30;

    // Publish the message.
    pub.publish(goalPose);

    // Send a message to rosout with the details.
    ROS_INFO_STREAM("Goal position:"
      << " x =" << goalPose.x
      << " y =" << goalPose.y
      << " theta =" << goalPose.theta);

    // Wait until it's time for another iteration.
    rate.sleep();
  }
  return 0;
}