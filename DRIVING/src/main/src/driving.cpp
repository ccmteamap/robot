#include"../sensors.h"
#include"../motor.h"

void drive(bool forward){
  extern Motor mainMotor;
  extern ExpoAvrg ultraPAvrg;
  extern ExpoAvrg ultraEAvrg;

  double x = ultraPAvrg <= ultraEAvrg ? ultraPAvrg : ultraEAvrg;
  double y = function(x);

  int speed = (int)(y + 0.5);

  if(!forward){
    speed *= -1;
  }

  mainMotor.SetSpeed(speed);
}

void stopDriving(){
  extern Motor mainMotor;
  mainMotor.SetSpeed(0);
}

void function(double x){

  return y;
}

