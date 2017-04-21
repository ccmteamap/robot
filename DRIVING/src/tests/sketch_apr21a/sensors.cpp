#include<Arduino.h>
#include<NewPing.h>
#include"sensors.h"
#include"expoavrg.h"

#define ULTRA_E_TRIGGER 2 //Ultrasone afstandssensor emmer zijde
#define ULTRA_E_ECHO 1
#define ULTRA_P_TRIGGER 7 //Ultrasone afstandssensor pomp zijde
#define ULTRA_P_ECHO 4

#define MAXDISTANCE 900
#define NUM_PINS 6

ExpoAvrg ultraPAvrg(0, AVRGSIZE);
ExpoAvrg ultraEAvrg(0, AVRGSIZE);

int sensorPins[NUM_PINS] = {  
  0, //eindeloop emmer zijde
  0, //eindeloop pomp zije
  0, //pomp sensor die checkt of emmer vol is
  0, //pomp sensor die checkt of pomp laag hangt
  0, //emmer sensor bovenaan
  0, //emmer sensor onderaan
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
    if(digitalRead(sensorPins[i])){
      mask |= 0x01 << i;
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
