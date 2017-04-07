#include"../motor.h"

void raisePump(){
  extern Motor pompMotor;
  pompMotor.SetSpeed(-255);
}

void stopRaisePump(){
  extern Motor pompMotor;
  pompMotor.SetSpeed(0);
}
