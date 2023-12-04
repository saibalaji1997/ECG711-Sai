### ASSIGNMENT_4:  PRELIMINARY ROBOT SETUP                                                                       **_Sai Balaji Jai Kumar_Prathibha Shoba_** 

**Youtube links:**

Led_blink:  https://youtube.com/shorts/Lpelpt4QkIM

Validating the working: 

Motor:https://youtube.com/shorts/CgHgy1fG7cI

IMU:https://youtube.com/shorts/0M10gKvK07o

Encoder:https://youtube.com/shorts/fHN3GxYBdQQ

Robot Calibration: https://youtube.com/shorts/CgHgy1fG7cI

Lidar and mapping:

Echo scan: https://youtube.com/shorts/xQpI41YBHTM?si=iaVnVgTN80ecz0Jl 

Laser scan:https://youtube.com/shorts/cyn8fp6hWLs

Hector scan:https://youtu.be/Uyh9obMMYC0 

**LED blink for STM32**

STM32CubeIDE is an all-in-one multi-OS development tool, an advanced C/C++ development platform with peripheral configuration, code generation, code compilation, and debugging functions for STM32 microcontrollers and microprocessors.

Steps Followed

•	Download STMCube IDE and STM programmer for Linux.

•	Open STMCube IDE, then you need to select a workspace. Then save the path according to the actual path.

•	Click File->New->STM32 Project.
			
•	Search and select the chip STM32F103RCT6, then click Next in the lower right corner to enter the next step. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/2f584991-63a0-4c58-858a-b66cfc3a67f0)


•	Enter the project name,  I named it led_blink take LED and all parameters can default. Then, debug information, click SYS->Debug under Pinout Configuration, and select Serial Wire. Modify the system clock of STM32. The external crystal oscillator is 8M frequency. 

•	Select RCC->HSE in Pinout Configuration and select Crystal/Ceramic Resonator. The HSE is the external clock, and the LSE is the internal clock. Using the external clock can be more stable and efficient than the internal clock.
•	Switch to Clock Configuration to modify the frequency of HCLK to 72, and press Enter to confirm. 
•	Set the PC13 pin to GPIO_Output, and modify the Label to LED for convenience. 
•	Then press Ctrl+S to save, tick Remember my decision, and click Yes. This will automatically generate the code every time you save.
•	Find the main function in the main.c file, and add the content to control the LED light under while(1). The function is that the LED light flashes every 200 milliseconds. The code is as follows:

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/4a92bd87-1232-429c-adae-feb2fc9cc0ed) 

•	Add the function of generating HEX files. Click Project->Properties->C/C++ Build->Settings->MCU Post build outputs in turn, and then check the box before Convert to Intel Hex file(-O ihex). 
•	Click the hammer in the toolbar to start compiling the project. 
•	STM32CubeIDE will pop up the Console  and see 0 errors in compilation, and 0 warnings means the compilation is successful.
•	Next step is to burn the program, for that open the STM32cube  program. In the open file upload the led_blink.hex file.
•	Connect the device, Insert one end of the USB data cable into the USB port of the computer, and the other end into the Micro USB port of the Rosmaster expansion board.
•	Hold the boot and press Reset and set RTS=1.
•	Click connect on programmer software and click download. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/26e95c9b-7bd4-4cb4-acaa-c49f9f5cec49) 

Result:

https://youtube.com/shorts/Lpelpt4QkIM 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/c80ef701-e6da-41ce-9899-e5cd6c9905fc)
 
**Robot Setup**

Attached are the images of the Robot that was made by setting up the STM32 ROS Controller, Jetson Nano, Battery Pack with voltage regulator & Lidar.

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/60d7f52e-692a-473d-9242-35352f7a82c7) 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/0863a18f-af53-4cd4-8989-422050aead40) 

The working of the ROS-Controller for the motors, encoders, IMU


**Motor:**


The motor connecting line needs to be connected to the corresponding motor as shown in the figure below, otherwise, it may cause the problem that the program does not match the phenomenon. Motor 1 corresponds to the motor in the upper left corner of the body, Motor 2 corresponds to the motor in the lower left corner, Motor 3 corresponds to the motor in the upper right corner, and Motor 4 corresponds to the motor in the lower right corner. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/dd22de37-d7e7-4cf1-ada6-29c92e9b0f21) 

Its working was checked by considering the rosmaster_v3.3.4.hex file and the controlling by considering the keyboard. launch file. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/9f634905-b0df-4f73-aa01-446a1992d235) 

Youtube link:https://youtube.com/shorts/CgHgy1fG7cI


**IMU**

An IMU is a sensor device that typically combines multiple sensors to measure and report information about an object's acceleration, angular velocity, and sometimes magnetic field. In the context of robotics and ROS, IMUs are commonly used to provide information about a robot's orientation and motion. It is used for odometry and localization, sensor fusion motion planning, stabilization, and control and mapping. The IMU working on the robot is shown below.

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/9fc55c09-b0d9-419f-9f73-808f06686df8)
 
Youtubelink:https://youtube.com/shorts/0M10gKvK07o

**Encoder**

Encoders are essential components in robotics, providing information about the rotation and position of motors or wheels. Some key applications and uses of encoders in this robot are wheel odometry, closed-loop control, speed control, mapping and localization, and path planning. 

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/08d0c819-6d0a-4634-9639-ec941eb3eaf0) 

Youtube link:https://youtube.com/shorts/fHN3GxYBdQQ


**Jetson Nano with the SD-card image**

The Jetson Nano is designed for AI and deep learning applications. It's capable of running neural networks and is suitable for tasks such as image recognition, object detection, and classification. The Jetson Nano can be employed in autonomous vehicle projects, including drones and small-scale robotic vehicles. It can handle computer vision tasks essential for navigation and obstacle avoidance.

Downloaded the provided SD-card image and flashed it.
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/f7cb63f6-e362-40dc-a9e4-173e75151d71) 
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/de5a7086-170e-40e6-9006-5ebd51806131) 

**Robot Calibration:**

The mobile dictionary mainly stores the relevant characters of the direction control and the speed dictionary stores the relevant characters of the speed control


![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/658ec138-3058-4f53-bacf-6a03ccd1df19)
![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/ba9a9962-6753-4c1c-9060-3eb1e332ccaf)

The angular and linear velocities have a limit value, which cannot be increased all the time. When starting, the program will first obtain the speed limit value, and when increasing the speed, it will judge and process the increased value.

video link:https://youtube.com/shorts/CgHgy1fG7cI

**Lidar and Mapping:**

According to different radar models, it is necessary to declare the [RPLIDAR_TYPE] variable in advance in the [.bashrc] file. Open the [.bashrc] file. modify the radar model directly. After modification, refresh the environment variables. The lidar was used to map in the following types.

**Echo Scan:**

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/727ca79f-d9ba-4353-a6c4-395d6f3081d3) 
YouTube link: https://youtube.com/shorts/xQpI41YBHTM?si=iaVnVgTN80ecz0Jl 

**Laser Scan**

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/8cf432e9-a3b3-4666-850a-68e3b768f5e5)

Youtube video link:https://youtube.com/shorts/cyn8fp6hWLs 

**Hector Scan**

![image](https://github.com/saibalaji1997/ECG711-Sai/assets/114025759/5d2754da-4fe9-409c-920f-701ac4bfe82a) 

YouTube link: https://youtu.be/Uyh9obMMYC0
