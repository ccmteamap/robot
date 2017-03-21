#ifndef COMM_H
#define COMM_H

#include<stdint.h>

typedef struct {
  uint8_t command; //P: pause, R: running, H: halt, M: motor, S: state
  uint8_t modifier; // 0x01: 
} Packet;

void startComm();
void send(const void*, uint8_t);
bool read(Command*);

#endif