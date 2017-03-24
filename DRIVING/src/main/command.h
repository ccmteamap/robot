#ifndef COMMAND_H
#define COMMAND_H

#include<stdint.h>

//command types
#define MOTOR_COMMANDTYPE 1
#define POWER_COMMANDTYPE 2

//modifiers
//power command modifiers
#define RUN_MOD 1 //if you want to run the program
#define HALT_MOD 2 //if you want to pause/halt the program
#define STOP_MOD 3 //if you want to stop the program

//motor command modifiers
#define SPEED_MOD 1 //if you want to change the speed of a motor
#define POWER_MOD 2 //if you want to change the power of a motor


typedef struct {
	uint8_t type;
	uint8_t modifier;
	uint8_t value;
} Command;

#endif // !COMMAND_H
