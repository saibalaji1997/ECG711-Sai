**Assignment 2 - Inverse Kinematics of DDMWR**                                          Sai Balaji Jai Kumar

**Description of the Problem and Solution**  

Problem Description: In this assignment, the goal is to develop two C++ files, mydriver and mycontroller, that control a mobile robot using ROS. The mydriver constantly publishes the goal_pose (x, y, θ), and the mycontroller implements a simple differential drive inverse kinematics to determine the robot's path.

**Brief Description of Each Code**
mydriver.cpp
Description: The mydriver node publishes the goal pose of the robot (x, y, θ) at a constant rate. This code generates random goal poses and publishes them to the "goal_pose" topic.

Link to Code: mydriver.cpp- (https://github.com/saibalaji1997/ECG711-Sai/blob/8336c5abcc77ec96cf0cc79c491ea949ecaa6b87/Assignment_02/src/mydriver.cpp)   

mycontroller.cpp
Description: The mycontroller node subscribes to the "goal_pose" topic to receive the desired goal pose and implements a PID controller to move the robot to the goal. It publishes velocity commands to the "cmd_vel" topic and publishes the current pose to the "gpose_pub" topic.

Link to Code: mycontroller.cpp- (https://github.com/saibalaji1997/ECG711-Sai/blob/c5a753aaf0cbd08117b5d9e64d1f136f155de18d/Assignment_02/src/mycontroller.cpp) 

**Execution Instructions** 

Start Ros: 

`roscore`

Source ROS workspace: 

`source devel/setup.bash` 

Launch the file: 

`roslaunch assignment02.launch` 

The two nodes, mydriver and mycontroller, will start running. The mydriver node will publish random goal poses, and the mycontroller node will control the robot to reach these goals using a PID controller.

Terminal output: 
