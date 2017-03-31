#include"parser.h"
#include"main.h"
#include"motor.h"
#include"stdlib.h"

void parseMotorCommand(uint8_t*);
void selectMotor(uint8_t*, Motor*);

void parse(uint8_t *buffer){
  switch(*buffer){

  case 'P':
    pause();
    break;
    
  case 'S':
    stop();
    break;

  case 'R':
    run();
    break;

  case 'M':
    parseMotorCommand(buffer);
    break;
  }
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

void selectMotor(uint8_t *buffer, Motor *motor){
  extern Motor mainMotor;
  extern Motor emmerMotor;
  extern Motor pompMotor;
  
  switch(*(buffer + 1)){
  case '0':
    motor = &mainMotor;
    break;

  case '1':
    motor = &emmerMotor;
    break;

  case '2':
    motor = &emmerMotor;
    break;
  }
}
