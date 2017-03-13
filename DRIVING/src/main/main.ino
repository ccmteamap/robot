/*
 * Team Poembak Delco
 * AP Hogeschool
 * 2017
 */

//TODO: Change pin numbers

#include <NewPing.h>
#include"expoavrg.h"
#include"motor.h"
#include"states.h"

#define FRONTTRIGGER 4
#define FRONTECHO 3
#define BACKTRIGGER 5
#define BACKECHO 6
#define MAXDISTANCE 900

#define AVRGSIZE 33

Motor motor(7);
ExpoAvrg frontAvrg(0, AVRGSIZE);
ExpoAvrg backAvrg(0, AVRGSIZE);

State currentState = Off;
int sensorMask = 0;

void setup() {
}

void loop() {
  checkInputs(); //update status of sensors.
  updateState(); //check to see if status should be changed according to updated sensor states.
  stateAction(); //perform action.
  callHome(); //send debugging information.
}

void callHome() {

}

void checkInputs() {
  measureDistances();
  updateSensorMask();
}

void updateSensorMask(){
  sensorMask = 0;
}

void updateState() {
  switch(currentState){
    //Als 'aan' en eindeloopschakelaar pompzijde ingedrukt
    case DrivingForward:
      if(sensorMask & (ON | ELOOPPOMP)){
        currentState = LoweringPump;
      }
      break;
      
    case LoweringPump:
      //TODO
      if(true){
        currentState = Pumping;
      }
      break;

    //Als 'aan' en pompsensor emmer zijde ingedrukt (dus emmer vol)
    case Pumping:
      if(sensorMask & (ON | POMP1)){
        currentState = RaisingPump;
      }
      break;

    //Als 'aan' en pompsensor bassin zijn ingedrukt (dus pomp is opgehaald)
    case RaisingPump:
      if(sensorMask & (ON | POMP2)){
        currentState = DrivingBackwards;
      }
      break;

    //Als 'aan' en eindeloopschakelaar emmer zijde ingedrukt (robot tegen vuur zijde)
    case DrivingBackwards:
      if(sensorMask & (ON | ELOOPEMMER)){
        currentState = RaisingBucket;
      }
      break;

    //Als 'aan' en emmer sensor bovenaan ingedrukt (emmer is dus opgehoffen)
    case RaisingBucket:
      if(sensorMask & (ON | EMMER1)){
        currentState = Pouring;
      }
      break;

    case Pouring:
      //TODO
      break;

    //Als 'aan' en emmer sensor onderaan ingedrukt (emmer terug gedaald)
    case LoweringBucket:
      if(sensorMask & (ON | EMMER2)){
        currentState = DrivingForward;
      }
      break;

    //something went wrong.
    default:
      //send state
      break;
  }
}

void measureDistances() {
  static NewPing frontSensor(FRONTTRIGGER, FRONTECHO, MAXDISTANCE);
  static NewPing backSensor(BACKTRIGGER, BACKECHO, MAXDISTANCE);

  unsigned int frontDistance = frontSensor.ping();
  unsigned int backDistance = backSensor.ping();

  frontAvrg.Update((double) frontDistance);
  backAvrg.Update((double) backDistance);
}

void stateAction(){
  switch(currentState){
    case DrivingForward:
      drive(true);
      break;
    
    case LoweringPump:
      lowerPump();
      break;
    
    case Pumping:
      pump();
      break;

    case RaisingPump:
      raisePump();
      break;
    
    case DrivingBackwards:
      drive(false);
      break;

    case RaisingBucket:
      raiseBucket();
      break;

    case Pouring:
      //TODO
      break;

    case LoweringBucket:
      lowerBucket();
      break;
  }
}

