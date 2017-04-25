#include"../motor.h"

void raisePump(){
  pompMotor.SetSpeed(-255);
}

void stopRaisePump(){
  pompMotor.SetSpeed(0);
}
