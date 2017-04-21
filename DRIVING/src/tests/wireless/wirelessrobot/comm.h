#ifndef COMM_H
#define COMM_H

#include<stdint.h>

#define PAYLOAD_SIZE 11

void startComm();
bool send(const void*, uint8_t);
bool read(void*, uint8_t);

#endif
