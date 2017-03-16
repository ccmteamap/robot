/*
 * Team Poembak Delco
 * AP Hogeschool
 * 2017
 */

#include"states.h"
#include"sensors.h"
#include"comm.h"

#define CE 9 //nodig voor nRF24
#define CSN 10 //nodig voor nRF24

State currentState = Off;
int sensorMask = 0;

void setup() {
  initSensorPins();
  initCommPins();
}

void loop() {
  inputScan(); //update status of sensors.
  executeProgram(); //update state and perform action
  callHome(); //send debugging information.
}

void callHome() {
//TODO
}

void inputScan() {
  sensorMask = getSensorMask();
  measureDistances();
}

void executeProgram(){
  updateState();
  stateAction();
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

