#include<Arduino.h>
#include<NewPing.h>
#include"sensors.h"
#include"expoavrg.h"

#define NUM_PINS 6

ExpoAvrg ultraPAvrg(0, AVRGSIZE);
ExpoAvrg ultraEAvrg(0, AVRGSIZE);

int sensorPins[NUM_PINS] = {
  7, //EL1 eindeloop emmer zijde
  8, //EL2 eindeloop pomp zije
  9, //P1 pomp sensor die checkt of emmer vol is
  10, //P2 pomp sensor die checkt of pomp laag hangt
  11, //E1 emmer sensor bovenaan
  12, //E2 emmer sensor onderaan
};

void initSensorPins(){
  for(int i = 0; i < NUM_PINS; ++i){
    pinMode(i, INPUT);
  }

  pinMode(ULTRA_E_TRIGGER, OUTPUT);
  pinMode(ULTRA_E_ECHO, INPUT);
  pinMode(ULTRA_P_TRIGGER, OUTPUT);
  pinMode(ULTRA_P_ECHO, INPUT);
}

int getSensorMask(){
  int mask = 0;

  for(int i = 0; i < NUM_PINS; ++i){
    if(digitalRead(i)){
      mask |= 0x01 << (i + 1); //+ 1 want 0x01 is voorbehouden voor 'ON'
    }
  }

  return mask;
}

void measureDistances(){
  static NewPing ultraPSensor(ULTRA_P_TRIGGER, ULTRA_P_ECHO, MAXDISTANCE);
  static NewPing ultraESensor(ULTRA_E_TRIGGER, ULTRA_E_ECHO, MAXDISTANCE);

  unsigned int pompDistance = ultraPSensor.ping();
  unsigned int emmerDistance = ultraESensor.ping();

  ultraPAvrg.Update((double) pompDistance);
  ultraEAvrg.Update((double) emmerDistance);
}
