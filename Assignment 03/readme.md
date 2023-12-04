### ASSIGNMENT_3:  URDF                                                                                                         Sai Balaji Jai Kumar_Prathibha Sobha

**Youtube link:** 
https://youtu.be/p50WlanG2mI 





https://youtu.be/mDARpHEyeRA
                             
Steps Taken:

•	Make appropriate changes to codes mainly,mobile_robot.urdf, mobile_robot.urdf.bak and mobilr_robot.urdf.xacro.
•	For chasis, length, width, and height is determined as 0.3048m,0.2032m and 0.127m and wheel dimensions is .1024m,0.1270m, and 0.724m.
•	Implemented Jetson Nano on chassis and Lidar on Jetson Nano.
•	Jetson nano with box sizes of 0.2m,0.16m, and 0.06m
•	Lidar with box sizes of 0.17m,0.1m, and 0.06m 
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/282c1d58-ddd0-4301-b40c-ff520b7b97af)
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/31c37718-5bbb-42d3-acc5-1bf182647754)
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/e649e0f7-8eba-4187-ad2c-8b82d80dd6e6)

•	Run mobile_robot.launch ,thus robot 3D visualization will be obtained. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/9a4f31fd-d8f3-4bd9-9b31-479c994095a8)

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/7c359b21-0950-4edb-8a94-35dcb334a84e) 
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/16de2223-b12f-41e3-8b4d-6c9f6b3bf09c) 

•	Running the drive launch file will lead to the gazebo tool. Gazebo is a powerful open-source simulation tool commonly used in conjunction with ROS for simulating robotic systems and environments. It provides a 3D simulation environment where you can model and simulate robots, sensors, and other objects.
•	Steering a robot usually involves controlling its motion and trajectory is obtained.

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/0639dc85-6aed-4beb-a869-5bfb22201254) 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/c0ef8e9f-70e0-4266-a461-0aeda6c11dcb)

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/0c3864fc-34f2-42a9-a695-a0b1a761d87c)

•	In ROS, the TF (Transform) system is a core component used to manage and broadcast the relationships between coordinate frames in a robot or robotic system. The TF system helps to keep track of the positions and orientations of different components and sensors for a common reference frame. The relationships between frames are represented as a tree, known as the TF tree. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/1048b22b-1603-4bff-9c56-aebd6cc48ff2)

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/102afcf4-c8c4-4ed0-a86c-e1c0ebcc836f)
