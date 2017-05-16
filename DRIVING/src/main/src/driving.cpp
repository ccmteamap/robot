#include"../sensors.h"
#include"../motor.h"
#include"math.h"

double acceleration(double);

void drive(bool forward){
  /*double x = ultraPAvrg.value <= ultraEAvrg.value ? ultraPAvrg.value : ultraEAvrg.value;
  double y = acceleration(x);

  int speed = (int)(y + 0.5);
  speed %= 255;

  if(!forward){
    speed *= -1;
  }

  mainMotor.SetSpeed(speed);*/

  /*
  if(forward){
    mainMotor.SetSpeed(255);
  }
  else {
    mainMotor.SetSpeed(-255);
  }
  */

  
  static double tresholdDistance = 20; //afstand waarbinnen hij afremt en optrekt.
  double distancePump = ultraPAvrg.value;
  double distanceBucket = ultraEAvrg.value;

  if(forward && distancePump <= tresholdDistance){
    mainMotor.SetSpeed(150);
  }
  else if(!forward && distanceBucket <= tresholdDistance) {
    mainMotor.SetSpeed(-150);
  }
  else if (forward){
    mainMotor.SetSpeed(255);
  }
  else {
    mainMotor.SetSpeed(-255);
  }
}

void stopDriving(){
  mainMotor.SetSpeed(0);
}

//GETEST
double acceleration(double x){
  return (127.5 * sin(-0.041888 * x + 4.7124) + 127.5);
}

