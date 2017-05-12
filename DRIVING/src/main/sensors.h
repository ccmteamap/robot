#ifndef SENSORS_H
#define SENSORS_H

#include"expoavrg.h"

#define ELOOPEMMER 0x01
#define ELOOPPOMP 0x02
#define POMP1 0x04 //POMP ONDER
#define POMP2 0x08 //POMP BOVEN
#define EMMER1 0x10 //EMMER BOVEN
#define EMMER2 0x20 //EMMER ONDER

void initSensorPins();
int getSensorMask(); //returns a mask indicating which sensors are
void measureDistances();

extern ExpoAvrg ultraPAvrg;
extern ExpoAvrg ultraEAvrg;

#endif
