#ifndef DEBUG_H
#define DEBUG

#define DEBUG_MOTOR 0x01
#define DEBUG_DISTANCE 0x02
#define DEBUG_STATE 0x03
#define DEBUG_SENSORS 0x04

void setDebugMask(int);
void sendDebugInfo();

#endif
