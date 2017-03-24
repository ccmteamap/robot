#ifndef SENSORS_H
#define SENSORS_H

#include"expoavrg.h"

<<<<<<< HEAD
#define ON 0x01
#define ELOOPEMMER 0x02
#define ELOOPPOMP 0x04
#define POMP1 0x08
#define POMP2 0x10
#define EMMER1 0x20
#define EMMER2 0x40

#define ULTRA_E_TRIGGER 2 //Ultrasone afstandssensor emmer zijde
#define ULTRA_E_ECHO 1
#define ULTRA_P_TRIGGER 4 //Ultrasone afstandssensor pomp zijde
#define ULTRA_P_ECHO 3
#define MAXDISTANCE 900
=======
#define ELOOPEMMER 0x01
#define ELOOPPOMP 0x02
#define POMP1 0x04
#define POMP2 0x08
#define EMMER1 0x10
#define EMMER2 0x20
>>>>>>> 77163eb4901195b965d146436eef2aa833819187

void initSensorPins();
int getSensorMask(); //returns a mask indicating which sensors are
void measureDistances();

extern ExpoAvrg ultraPAvrg;
extern ExpoAvrg ultraEAvrg;

#endif
