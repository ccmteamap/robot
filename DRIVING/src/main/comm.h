#ifndef COMM_H
#define COMM_H

#include<stdint.h>

#define PAYLOAD_SIZE 32

void startComm();
void send(const void*, uint8_t);
bool read(void*);

#endif
