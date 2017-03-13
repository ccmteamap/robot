/*
 * Team Poembak Delco
 * AP Hogeschool
 * 2017
 */

//TODO: Change pin numbers

#include <NewPing.h>
#include"expoavrg.h"
#include"motor.h"

#define FRONTTRIGGER 4
#define FRONTECHO 3
#define BACKTRIGGER 5
#define BACKECHO 6
#define MAXDISTANCE 900

#define AVRGSIZE 33

Motor motor(7
ExpoAvrg frontAvrg = { 0, AVRGSIZE }, backAvrg = { 0, AVRGSIZE };

void setup() {
}

void loop() {
  checkInputs(); //update status of sensors.
  updateState(); //check to see if status should be changed according to updated sensor states.
  callHome(); //send debugging information.
}

void callHome() {

}

void checkInputs() {
  measureDistances();
}

void updateState() {

}

void measureDistances() {
  static NewPing frontSensor(FRONTTRIGGER, FRONTECHO, MAXDISTANCE);
  static NewPing backSensor(BACKTRIGGER, BACKECHO, MAXDISTANCE);

  unsigned int frontDistance = frontSensor.ping();
  unsigned int backDistance = backSensor.ping();

  frontAvrg.value = calcExpoAvrg((double) frontDistance, frontAvrg);
  backAvrg.value = calcExpoAvrg((double) backDistance, frontAvrg);
}

