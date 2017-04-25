#include"debug.h" 
#include"motor.h" //motoren
#include"main.h" //state van robot
#include"comm.h" //opsturen debug bericht
#include"Arduino.h"

static int debugMask = 0;
void sendMotorInfo();
void sendDistanceInfo();
void sendStateInfo();
void sendSensorsInfo();

void setDebugMask(int mask){
  debugMask = mask;
}

//GETEST
void debug(){
  static long startTime = millis();
  static int pause = 0;
  static long currentTime = 0;

  currentTime = millis();

  if(currentTime - startTime <= pause){
    return;
  }

  startTime = currentTime;
  
  if(debugMask & DEBUG_MOTOR){
    sendMotorInfo();
  }

  if(debugMask & DEBUG_DISTANCE){
    sendDistanceInfo();
  }

  if(debugMask & DEBUG_STATE){
    sendStateInfo();
  }

  if(debugMask & DEBUG_SENSORS){
    sendSensorsInfo();
  }
}

//GETEST
void sendDebugMessage(Debug_Message message){
  send(&message, sizeof message);
}

//GETEST
void sendMotorInfo(){
  Debug_Message motorMessage = { DEBUG_MOTOR };
  Debug_Body body;
  Motor motors[] = {
    mainMotor,
    emmerMotor,
    pompMotor
  };

  for(int i = 0; i < 3; ++i){
    body.motorInfo = { (uint8_t)i, motors[i].GetSpeed(), motors[i].GetPower() };
    motorMessage.body = body;

    sendDebugMessage(motorMessage);
  }
}

//GETEST
void sendDistanceInfo(){
  Debug_Message distanceMessage = { DEBUG_DISTANCE };
  Debug_Body body;

  body.distanceInfo = { ultraEAvrg.value, ultraPAvrg.value  };
  distanceMessage.body = body;

  sendDebugMessage(distanceMessage);
}

//GETEST
void sendStateInfo(){
  Debug_Message stateMessage = { DEBUG_STATE };
  Debug_Body body;

  body.stateInfo = { getState() };
  stateMessage.body = body;

  sendDebugMessage(stateMessage);
}

//GETEST
void sendSensorsInfo(){
  Debug_Message sensorsMessage = { DEBUG_SENSORS };
  Debug_Body body;

  body.sensorsInfo = { getSensorMask() };
  sensorsMessage.body = body;

  sendDebugMessage(sensorsMessage);
}
