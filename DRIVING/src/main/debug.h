#ifndef DEBUG_H
#define DEBUG

#include<stdint.h>
#include"states.h"
#include"sensors.h"

#define DEBUG_MOTOR 0x01
#define DEBUG_DISTANCE 0x02
#define DEBUG_STATE 0x03
#define DEBUG_SENSORS 0x04

void setDebugMask(int);
void debug();

typedef struct {
  int speed;
  unsigned int power;
} Motor_Info;

typedef struct {
  double emmerDistance;
  double pompDistance;
} Distance_Info;

typedef struct {
  State state;
} State_Info;

typedef struct {
  int sensorMask;
} Sensors_Info;

typedef union {
  Motor_Info motorInfo;
  Distance_Info distanceInfo;
  State_Info stateInfo;
  Sensors_Info sensorsInfo;
} Debug_Body;

typedef struct {
  uint8_t type;
  Debug_Body body;
} Debug_Message;

#endif
