#include"debug.h"
#include"motor.h"
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
  Motor motors[] = {
    mainMotor,
    emmerMotor,
    pompMotor
  };

  Motor_Info mInfos[3];

  for(int i = 0; i < 3; ++i){
    mInfos[i] = getMotorInfo(motors[i]);
  }
}

Motor_Info getMotorInfo(Motor motor){
  return { motor.GetSpeed(), motor.GetPower() };
}

void sendDistanceInfo(){
}

void sendStateInfo(){
  
}

void sendSensorsInfo(){
  
}
