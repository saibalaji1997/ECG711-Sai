**Assignment 1 - ROS - Forward Kinematics of a DDMWR**                                  Sai Balaji Jai Kumar 

Description of problem: 
The problem involves using the provided minimal nodes to develop two ROS nodes, a simulator, and a driver, without controlling velocity as demonstrated. The driver should publish the cmd_vel topic with left and right velocities, while the simulator should consume these velocities and publish the robot's pose using differential drive forward kinematics. Additionally, a launch file needs to be implemented to execute both nodes simultaneously. 

Steps Taken: 
Setup Workspace- 
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_init_workspace 

Clone GitHub Repo: 
git clone https://github.com/venki666/CpE476_demos.git ~/catkin_ws/src/minimal_nodes 

Build Workspace: 
cd ~/catkin_ws
catkin_make
source devel/setup.bash 

Driver Node: 
This node generates random linear and angular velocities, and publishes them on the cmd_vel topic. 
https://github.com/saibalaji1997/ECG711-Sai/blob/d33fc5e07ce78f42ccc469bdbe5db372097d86d7/Assignment01/test001/images/driver%20code.png


Simulator Node: 
  In simulator.cpp, the simulator node subscribes to the cmd_vel topic and simulates the robot's movement. The simulator calculates the new position of the robot based on the received velocity commands, implementing the differential drive kinematics. It publishes the simulated pose on the Pose topic. 
  https://github.com/saibalaji1997/ECG711-Sai/blob/d33fc5e07ce78f42ccc469bdbe5db372097d86d7/Assignment01/test001/images/simulator_1.png 
  https://github.com/saibalaji1997/ECG711-Sai/blob/d33fc5e07ce78f42ccc469bdbe5db372097d86d7/Assignment01/test001/images/simulator_2.png

  
Launch File: Create a launch file, minimal_nodes.launch, to launch both the driver and simulator nodes. 
<launch>
  <node name="driver_node" pkg="your_package_name" type="driver" output="screen" />
  <node name="simulator_node" pkg="your_package_name" type="simulator" output="screen" />
</launch>

Begin the ROS Master by using this code: 
roscore 

then run the nodes using the launch file: 
roslaunch test001.launch  

we can see the topics by running this command simultaneously: 
rostopic list 

Terminal output: 
https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/e5b8fda3-05d8-4cea-b1bb-a31466dd9b67

Terminal YouTube Link: https://youtu.be/7-PACuAInic?

