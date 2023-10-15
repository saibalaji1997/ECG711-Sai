//simulator
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>



// Initialize variables for the robot's position and orientation
double x = 0.0; // x-coordinate of the robot's position
double y = 0.0; // y-coordinate of the robot's position
double theta = 0.0; // Orientation (angle) of the robot
double del_time = 0.01;
double  L = 2.0; // Distance between the robot's wheels

double velocity= 0; // Linear velocity of the robot
double angular = 0; // Angular velocity of the robot

void cmdVelCallback(const geometry_msgs::Twist& cmd_vel) {
   
    velocity = cmd_vel.linear.x;
    angular = cmd_vel.angular.z;
}


int main(int argc, char** argv) {

    double ctime, ptime;

    ros::init(argc, argv, "simulator");
    ros::NodeHandle nh;

    ros::Subscriber cmd_vel_sub = nh.subscribe("cmd_vel", 1, cmdVelCallback);

    ros::Publisher pub = nh.advertise<geometry_msgs::Pose2D>("Pose", 1);

    ctime = ros::Time::now().toSec();
    ptime = ros::Time::now().toSec();
 
    double sample_rate = 1.0;
    ros::Rate naptime(sample_rate);

    // Main loop

    while (ros::ok()) {

        ros::spinOnce();

        ctime = ros::Time::now().toSec();
        del_time = ctime-ptime;

        double speed_right = (angular*L)/2+velocity;
        double speed_left = velocity*2 - speed_right;
        // Check if the robot is moving straight or turning

        if(speed_right == speed_left)
        {
            x = x + speed_right * del_time * cos(theta);
            y = y + speed_left * del_time * sin(theta);
            theta = theta;
        }

        else
        {
            double R = (L/2)* ((speed_right + speed_left) / (speed_right - speed_left));
            double ICC_x = x- R * sin(theta);
            double ICC_y = y - R * cos(theta);

            double w = (speed_right - speed_left) / L;
            double del_theta = w*del_time;
        
            x = (x - ICC_x)*cos(del_theta) + (y - ICC_y) * sin(del_theta) + ICC_x;
            y = (x - ICC_x)*sin(del_theta) + (y - ICC_y) * cos(del_theta) + ICC_y;
            theta += del_theta;

        }

        // Create a message for the current robot pose
        geometry_msgs::Pose2D pose;

        pose.x = x;
        pose.y = y;
        pose.theta = theta;

        // Publish the current pose to the "Pose" topic

        pub.publish(pose);

        // Print the current position for debugging
        ROS_INFO("pose.x = %f", pose.x);
        ROS_INFO("pose.y = %f", pose.y);
        ROS_INFO("pose.theta = %f", pose.theta);
        
        ptime = ctime;
        naptime.sleep();
    }
    return 0;
}