#include <DynamixelShield.h>
// ************************ Motor Settings and Variables ******************************* //
#define DEBUG_SERIAL Serial1
const uint8_t DXL_ID_1 = 101;
const uint8_t DXL_ID_2 = 102;
const uint8_t DXL_ID_3 = 103;
const uint8_t DXL_ID_4 = 104;
const uint8_t DXL_ID_5 = 105;
const uint8_t DXL_ID_all[5] = {DXL_ID_1, DXL_ID_2, DXL_ID_3, DXL_ID_4, DXL_ID_5};
const float DXL_PROTOCOL_VERSION = 2.0;
const int32_t BAUD_RATE_MOTOR = 1000000;
DynamixelShield dxl;
char input;
boolean newData = false;

void motor_setup() {
  DEBUG_SERIAL.begin(115200);
  dxl.begin(BAUD_RATE_MOTOR);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  DEBUG_SERIAL.println("getting dynamixel info");
  for (int i = 0; i<5; i++) {
    // Get DYNAMIXEL information
    dxl.ping(DXL_ID_all[i]);
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID_all[i]);
    dxl.setOperatingMode(DXL_ID_all[i], OP_POSITION);
    dxl.torqueOn(DXL_ID_all[i]);
  }
}

void readSerial() {
  if(DEBUG_SERIAL.available() > 0){
    input = DEBUG_SERIAL.read();
    newData = true;
  }
}

void setup() {
  motor_setup();
  DEBUG_SERIAL.println("void setup");
}

//define function to decrease individual motor position
void moveDecrease(int motorID, char key) {
  int initialPosition = dxl.getPresentPosition(motorID);
  int finalPosition = dxl.getPresentPosition(motorID);
  int i = 15;

  //print out data
  DEBUG_SERIAL.print("Input: ");
  DEBUG_SERIAL.println(key);
  DEBUG_SERIAL.print("Decreasing: ");
  DEBUG_SERIAL.println(motorID);

  //subtracts an increased amount if DYNAMIXEL motor cannot supply enough power initally
  while (initialPosition == finalPosition){
    dxl.setGoalPosition(motorID, dxl.getPresentPosition(motorID) - i);
    finalPosition = dxl.getPresentPosition(motorID);
    i = i - 50;
  }
  DEBUG_SERIAL.println(dxl.getPresentPosition(motorID));
  newData = false;
}

//define function to increase individual motor position
void moveIncrease(int motorID, char key) {
  int initialPosition = dxl.getPresentPosition(motorID);
  int finalPosition = dxl.getPresentPosition(motorID);
  int i = 15;

  //print out data
  DEBUG_SERIAL.print("Input: ");
  DEBUG_SERIAL.println(key);
  DEBUG_SERIAL.print("Increasing: ");
  DEBUG_SERIAL.println(motorID);
  
  //adds additional position increases if DYNAMIXEL motor cannot supply enough power initally
  while (initialPosition == finalPosition){
    dxl.setGoalPosition(motorID, dxl.getPresentPosition(motorID) - i);
    finalPosition = dxl.getPresentPosition(motorID);
    i = i + 50;
  }
  DEBUG_SERIAL.println(dxl.getPresentPosition(motorID));
  newData = false;
}


void loop() {
  // readSerial function uses Serial input to run the following switch case
  readSerial();
  if(newData == true){
    //case inputs can be changed to any key
    switch(input){
      // Motor 1 controlling manipulator base
      case ' ':
        moveIncrease(DXL_ID_1, ' ');
        break;
      case '.':
        moveDecrease(DXL_ID_1, '.');
        break;
        
      // Motor 2 controlling joint 1
      case 'a':
        moveIncrease(DXL_ID_2, 'a');
        break;
      case 'd':
        moveDecrease(DXL_ID_2, 'd');
        break;
        
      // Motor 3 controlling joint 2
      case 'w':
        moveDecrease(DXL_ID_3, 'w');
        break;
      case 's':
        moveIncrease(DXL_ID_3, 's');
        break;
        
      // Motor 4 controlling joint 3
      case 'j':
        moveIncrease(DXL_ID_4, 'j');
        break;
      case 'l':
        moveDecrease(DXL_ID_4, 'l');
        break;
        
      // Motor 5 controlling gripper 
      case 'i':
        moveIncrease(DXL_ID_5, 'i');
        break;
      case 'k':
        moveDecrease(DXL_ID_5, 'k');
        break;
        
      // Enter any other key to stop the motors
      default:
        newData = false;
        break;
    }
  }
}
