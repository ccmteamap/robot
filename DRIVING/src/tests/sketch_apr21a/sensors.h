#ifndef SENSORS_H
#define SENSORS_H

#include"expoavrg.h"

#define ELOOPEMMER 0x01
#define ELOOPPOMP 0x02
#define POMP1 0x04
#define POMP2 0x08
#define EMMER1 0x10
#define EMMER2 0x20

void initSensorPins();
int getSensorMask(); //returns a mask indicating which sensors are
void measureDistances();

extern ExpoAvrg ultraPAvrg;
extern ExpoAvrg ultraEAvrg;

#endif
