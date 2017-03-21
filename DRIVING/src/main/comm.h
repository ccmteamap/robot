#ifndef COMM_H
#define COMM_H

#include<stdint.h>

void startComm();
void send(const void*, uint8_t);
bool read(Command*);

#endif