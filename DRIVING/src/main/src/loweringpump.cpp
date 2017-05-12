#include"../motor.h"
#include"Arduino.h"

static unsigned long duration = 1000;
static bool stopped = true;

void lowerPump(){
  unsigned long currentTime = millis();
  static unsigned long startTime;

  if(stopped()){
    startTime = currentTime();
    stopped = false;
  }

  if(currentTime - startTime >= duration){
    pompMotor.SetSpeed(0);
  }
  else {
    pompMotor.SetSpeed(255);
  }
}

void stopLowerPump(){
  pompMotor.SetSpeed(0);
  stopped = true;
}
