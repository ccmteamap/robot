/*
 * Team Poembak Delco
 * AP Hogeschool
 * 2017
 */

#include"states.h"
#include"sensors.h"
//#include"comm.h"

#define CE 9 //nodig voor nRF24
#define CSN 10 //nodig voor nRF24

State currentState = Off;
int sensorMask = 0;

void setup() {
  initSensorPins();
  //startComm();
  Serial.begin(9600);
}

void loop() {
  inputScan(); //update status of sensors.
  executeProgram(); //update state and perform action
  callHome(); //send debugging information.
  listenHome(); //see if we got instructions.
}

void listenHome(){
  
}

void callHome() {
//TODO
Serial.print(sensorMask);
Serial.print(currentState);

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

    //Als 'aan' en pompsensor emmer zijn ingedrukt (dus emmer is vol)  
    case LoweringPump:
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
        currentState = LoweringBucket;
      }
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

    case RaisingPump:
      raisePump();
      break;
    
    case DrivingBackwards:
      drive(false);
      break;

    case RaisingBucket:
      raiseBucket();
      break;

    case LoweringBucket:
      lowerBucket();
      break;
  }
}

