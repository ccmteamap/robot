#include<Arduino.h>
#include<NewPing.h>
#include"sensors.h"
#include"expoavrg.h"
#include"pin.h"

#define MAXDISTANCE 900
#define NUM_PINS 6

ExpoAvrg ultraPAvrg(0, AVRGSIZE);
ExpoAvrg ultraEAvrg(0, AVRGSIZE);

int sensorPins[NUM_PINS] = {  
  EMMER_ZIJDE_PIN, //eindeloop emmer zijde
  POMP_ZIJDE_PIN, //eindeloop pomp zije
  POMP_ONDER_PIN, //pomp sensor die checkt of emmer vol is
  POMP_BOVEN_PIN, //pomp sensor die checkt of pomp laag hangt
  EMMER_BOVEN_PIN, //emmer sensor bovenaan
  EMMER_ONDER_PIN, //emmer sensor onderaan
};

void initSensorPins(){
  for(int i = 0; i < NUM_PINS; ++i){
    pinMode(sensorPins[i], INPUT);
  }


/*
  pinMode(EMMER_ZIJDE_PIN, INPUT);
  pinMode(POMP_ZIJDE_PIN, INPUT);
  pinMode(POMP_ONDER_PIN, INPUT);
  pinMode(POMP_BOVEN_PIN, INPUT);
  pinMode(EMMER_BOVEN_PIN, INPUT);
  pinMode(EMMER_ONDER_PIN, INPUT);
 */

  pinMode(EMMER_ULTRA_TRIGGER_PIN, OUTPUT);
  pinMode(EMMER_ULTRA_ECHO_PIN, INPUT);
  pinMode(POMP_ULTRA_TRIGGER_PIN, OUTPUT);
  pinMode(POMP_ULTRA_ECHO_PIN, INPUT);
}

int getSensorMask(){
  int mask = 0;

  for(int i = 0; i < NUM_PINS; ++i){
    if(digitalRead(sensorPins[i])){
      Serial.println(0x01 << i);
      mask |= 0x01 << i;
    }
  }

  return mask;
}

void measureDistances(){
  static NewPing ultraPSensor(POMP_ULTRA_TRIGGER_PIN, POMP_ULTRA_ECHO_PIN, MAXDISTANCE);
  static NewPing ultraESensor(EMMER_ULTRA_TRIGGER_PIN, EMMER_ULTRA_ECHO_PIN, MAXDISTANCE);

  unsigned int pompDistance = ultraPSensor.ping();
  unsigned int emmerDistance = ultraESensor.ping();

  ultraPAvrg.Update(((double) pompDistance) / 58.2);
  ultraEAvrg.Update(((double) emmerDistance) / 58.2);
}
