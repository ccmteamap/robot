#include"../motor.h"

void raiseBucket(){
  emmerMotor.SetSpeed(255);
}

void stopRaiseBucket(){
  emmerMotor.SetSpeed(0);
}
