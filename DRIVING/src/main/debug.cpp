#include"debug.h"
#include"motor.h"
#include"sensors.h"
#include"main.h"
#include"comm.h"

static int debugMask;
void sendMotorInfo();
void sendDistanceInfo();
void sendStateInfo();
void sendSensorsInfo();

void setDebugMask(int mask){
  debugMask = mask;
}

void sendDebugInfo(){
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

void sendMotorInfo(){
  
}

char* getMotorInfo(Motor motor){
  
}

void sendDistanceInfo(){
  
}

void sendStateInfo(){
  
}

void sendSensorsInfo(){
  
}
