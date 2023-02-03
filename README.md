# desk-robot-manipulator

## Open-Source Desk Robot Manipulator Design Project
This project is designed to cater towards the growing demand of more ubiquitous open-source robotics software and hardware. The files below provide the materials and resources necessary to recreate this desktop serial robot manipulator with a parallel gripper. 

## CAD Files
Included are individual SolidWorks CAD part files and an overall CAD assembly to help for 3D printing and assembling.
* Download documents as *.stl* files to print on any 3D printer
* This robot uses 5 Dynamixel XL430-W250-T servo motors which can be found [here](https://www.robotis.us/dynamixel-xl430-w250-t/)
* Screws can be found through these links below:
  * [6 - 16mm M2.5](https://www.mcmaster.com/screws/system-of-measurement~metric/thread-size~m2-5/metric-alloy-steel-hex-drive-flat-head-screws/length~16-mm/)
  * [4 - 10mm M2.5](https://www.mcmaster.com/screws/system-of-measurement~metric/thread-size~m2-5/metric-alloy-steel-hex-drive-flat-head-screws/length~10-mm/)
  * [8 - 12mm M2.5](https://www.mcmaster.com/screws/system-of-measurement~metric/thread-size~m2-5/metric-alloy-steel-hex-drive-flat-head-screws/length~12-mm/)
  * [12 - 8mm M2](https://www.mcmaster.com/screws/system-of-measurement~metric/metric-alloy-steel-hex-drive-flat-head-screws/thread-size~m2/length~8-mm)

## Arduino Program
This desk robot uses an [Arduino MEGA](https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?gclid=Cj0KCQiA2-2eBhClARIsAGLQ2RlWgyga7lHBjxjFDpbEGe1dLKO13caXmnDmHF0M2GgzdpYXbMqWACMaAopeEALw_wcB), [Dynamixel Motor Shield](https://www.robotis.us/dynamixel-shield/), and the Arduino software as the robot's control mechanisms.

Included in this package is the *move_all_motors.ino* Arduino program which takes in input keys *a, w, s, d, j, i, k, l* to control the position of each individual Dynamixel servo. 

Specifications:
* XL430 Dynamixel Servo Motor can be found [here](https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/)
* Dynamixel Motor Shield can be found [here](https://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/)

