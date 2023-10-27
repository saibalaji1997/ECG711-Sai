#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"

using namespace std;


geometry_msgs::Pose2D current_pose, gpose;

//global variables declaration
ros::Publisher vel_pub;
ros::Publisher pose_pub;
ros::Subscriber pose;
ros::Time ptime;

double tolerance = 0.01;
// function declarations
double degreesToRadians(double);
double radiansToDegrees(double);

geometry_msgs :: Twist returnVelocity(double, double);

float getDistance();
float getAngle();
void moveToGoalPID();

// called whenever there is a new message on the pose topic
void PoseCallback(const geometry_msgs::Pose2D &pose){
	gpose.x = pose.x;
	gpose.y = pose.y;
	gpose.theta=pose.theta;
	 ROS_INFO_STREAM("Current Pose :"
      << " x = " << gpose.x
      << " y = " << gpose.y
      << " theta = " << gpose.theta); 
}


int main(int argc, char **argv){
	ros::init(argc, argv, "controller_node");
	ros::NodeHandle nh;

	pose = nh.subscribe("goal_pose", 1000, PoseCallback);
	vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
	pose_pub = nh.advertise<geometry_msgs::Pose2D>("gpose_pub", 1000);

	moveToGoalPID();

    return 0;
} 

// returns angle (in degrees) converted to radians
double degreesToRadians(double theta)
{
     return(theta * (M_PI / 180));
}

// returns angle (in radians) converted to degrees
double radiansToDegrees(double theta)
{
     return(theta * (180 / M_PI));
}

// returns distance between 2 points (x, y) and (x2, y2) in the Cartesian plane
float getDistance() {
    return sqrt(pow((current_pose.x - gpose.x), 2) + pow((current_pose.y - gpose.y), 2));
}

float getAngle() {
    return ((atan2(gpose.y - current_pose.y, gpose.x - current_pose.x)) - current_pose.theta);
}

// returns a Twist variable with desired velocity parameters
geometry_msgs::Twist returnVelocity(double speed, double angular_speed)
{
     geometry_msgs :: Twist vel;
     vel.linear.x = speed;
     vel.linear.y = 0;
     vel.linear.z = 0;
     vel.angular.x = 0;
     vel.angular.y = 0;
     vel.angular.z = angular_speed;
     return vel;
}

// move to desired position using PID controller
void moveToGoalPID()
{	
	geometry_msgs::Twist vel_msg;

	float e_theta = 0;
	float integral_theta = 0;
	float diff_theta = 0;
	float e_dist = 0;
	float integral_dist = 0;
	float diff_dist = 0;
	float kp = 7.5, ki = 0.000001, kd = 0.0001;
	double speed = 0;
	double angular_speed = 0;
	ros::Rate loop_rate(10);
	e_theta = getAngle();
	e_dist = getDistance();

	while(ros::ok())
	{
	 do {
		ros::Time ctime = ros::Time::now();
        ros::Duration dt = ctime - ptime;

        current_pose.x = current_pose.x + speed * cos(current_pose.theta) * dt.toSec();
        current_pose.y = current_pose.y + speed * sin(current_pose.theta) * dt.toSec();
        current_pose.theta = current_pose.theta + angular_speed * dt.toSec();    
        e_theta = getAngle();
        e_dist = getDistance();
		integral_theta = integral_theta + e_theta;
		integral_dist = integral_dist + e_dist;
		diff_dist = e_dist - diff_dist;
		diff_theta = e_theta - diff_theta;

		//linear velocity
		speed = (kp *e_dist / 20.0) + (ki *integral_dist) + (kd *diff_dist);
		//angular velocity
		angular_speed = (kp *e_theta) + (ki *integral_theta) + (kd *diff_theta);
		geometry_msgs :: Twist vel_msg = returnVelocity(speed, angular_speed);

		vel_pub.publish(vel_msg);
		pose_pub.publish(current_pose);
		ros::spinOnce();
		loop_rate.sleep();
		ptime = ctime;
		
	}  while (e_dist > tolerance);

    angular_speed = 0;

    // turtle rotates to goal angle using PID controller
     do {
     	ros::Time ctime = ros::Time::now();
        ros::Duration dt = ctime - ptime;

        current_pose.theta = current_pose.theta + angular_speed * dt.toSec(); 
        e_theta = gpose.theta - current_pose.theta;
        integral_theta = integral_theta + e_theta;
        diff_theta = e_theta - diff_theta;

        //angular velocity
        angular_speed = (kp *e_theta) + (ki *integral_theta) + (kd *diff_theta);
        geometry_msgs :: Twist vel_msg = returnVelocity(0,angular_speed);

        vel_pub.publish(vel_msg);
		pose_pub.publish(current_pose);
		ros::spinOnce();
		loop_rate.sleep();
		ptime = ctime;
     } while (abs((gpose.theta - current_pose.theta)) > tolerance);

    std::cout << "end move goal" <<  std::endl;
	ROS_INFO_STREAM("Reached goal position using PID:"
      << " x = " << current_pose.x
      << " y = " << current_pose.y
      << " theta = " << current_pose.theta);
	vel_pub.publish(vel_msg);
	}
}

