#include"../sensors.h"
#include"../motor.h"
#include"math.h"

void drive(bool forward){
  double x = ultraPAvrg <= ultraEAvrg ? ultraPAvrg : ultraEAvrg;
  double y = acceleration(x);

  int speed = (int)(y + 0.5);
  speed %= 255;

  if(!forward){
    speed *= -1;
  }

  mainMotor.SetSpeed(speed);
}

void stopDriving(){
  mainMotor.SetSpeed(0);
}

//GETEST
double acceleration(double x){
  return (127.5 * sin(-0.00071973 * x + 4.7124) + 127.5);
}

