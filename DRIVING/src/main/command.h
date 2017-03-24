#ifndef COMMAND_H
#define COMMAND_H

#include<stdint.h>

//command types
#define MOTOR_COMMAND 1
#define RUN_COMMAND 2 //run program
#define HALT_COMMAND 3 //pause/halt program
#define STOP_COMMAND 4 //stop program

//motor selector
#define MAIN_MOTOR 1
#define EMMER_MOTOR 2
#define 


typedef struct {
	uint8_t type;
	uint8_t modifier;
	uint8_t value;
} Command;

#endif // !COMMAND_H
