#include"parser.h"
#include"main.h"
#include"motor.h"
#include"stdlib.h"
#include"debug.h"
#include"Arduino.h"

void parseMotorCommand(uint8_t*);
void selectMotor(uint8_t*, Motor**);
void parseDebugCommand(uint8_t*);

//GETEST
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

  case 'D':
    parseDebugCommand(buffer);
    break;
  }
}

//GETEST
void parseDebugCommand(uint8_t *buffer){
  int debugMask = 0;

  while(*++buffer){
    switch(*buffer){
    case 'M':
      debugMask |= DEBUG_MOTOR;
      break;

    case 'A':
      debugMask |= DEBUG_DISTANCE;
      break;

    case 'T':
      debugMask |= DEBUG_STATE;
      break;

    case 'S':
      debugMask |= DEBUG_SENSORS;
      break;
    }
  }

  setDebugMask(debugMask);
}

//GETEST
void parseMotorCommand(uint8_t *buffer){
  Motor *motor = NULL;
  int value;

  selectMotor(buffer, &motor);
  value = atoi(buffer + 3);

  switch(*(buffer + 2)){
  case 'S':
    motor->SetSpeed(value);

  case 'P':
    motor->SetPower((unsigned int)value);
  }
}

//GETEST
void selectMotor(uint8_t *buffer, Motor **motor){
  switch(*(buffer + 1)){
  case '0':
    *motor = &mainMotor;
    break;

  case '1':
    *motor = &emmerMotor;
    break;

  case '2':
    *motor = &pompMotor;
    break;
  }
}
