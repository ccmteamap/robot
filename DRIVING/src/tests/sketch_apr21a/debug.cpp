
#include"debug.h" 
#include"motor.h" //motoren
#include"main.h" //state van robot
#include"comm.h" //opsturen debug bericht
#include"Arduino.h"

static int debugMask;
void sendMotorInfo();
void sendDistanceInfo();
void sendStateInfo();
void sendSensorsInfo();

void setDebugMask(int mask){
  Serial.println("mask set");
  debugMask = mask;
}

void debug(){
  Serial.println("debug");
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


void sendDebugMessage(Debug_Message message){
  Serial.println("sending message");
  send(&message, sizeof message);
}

void sendMotorInfo(){
  Serial.println("sendmotorinfo");
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


void sendDistanceInfo(){
  Debug_Message distanceMessage = { DEBUG_DISTANCE };
  Debug_Body body;

  body.distanceInfo = { ultraEAvrg.value, ultraPAvrg.value  };
  distanceMessage.body = body;

  sendDebugMessage(distanceMessage);
}

void sendStateInfo(){
  Debug_Message stateMessage = { DEBUG_STATE };
  Debug_Body body;

  //body.stateInfo = { getState() };
  stateMessage.body = body;

  sendDebugMessage(stateMessage);
}

void sendSensorsInfo(){
  Debug_Message sensorsMessage = { DEBUG_SENSORS };
  Debug_Body body;

  body.sensorsInfo = { getSensorMask() };
  sensorsMessage.body = body;

  sendDebugMessage(sensorsMessage);
}

