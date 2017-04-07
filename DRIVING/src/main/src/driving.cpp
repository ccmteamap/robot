#include"../sensors.h"
#include"../motor.h"

void drive(bool forward){
  extern Motor mainMotor;
}

void stopDriving(){
  extern Motor mainMotor;
  mainMotor.SetSpeed(0);
}
