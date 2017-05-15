#include"../motor.h"
#include"Arduino.h"

bool stopped = true;

void lowerPump(){
  unsigned long currentTime = millis();
  static unsigned long startTime;
  static unsigned long duration = 1000;

  if(stopped){
    startTime = currentTime;
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
