#include"debug.h"
#include"motor.h"

void setup() {
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
}

void parseMotorCommand(uint8_t *buffer){
  Motor *motor = NULL;
  int value;

  selectMotor(buffer, motor);
  value = atoi(buffer + 3);

  switch(*(buffer + 2)){
  case 'S':
    motor->SetSpeed(value);

  case 'P':
    motor->SetPower((unsigned int)value);
  }
}
