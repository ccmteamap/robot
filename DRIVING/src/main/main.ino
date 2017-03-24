/*
   Team Poembak Delco
   AP Hogeschool
   2017
*/

#include"states.h"
#include"sensors.h"
//#include"comm.h"

bool running;
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

void listenHome() {

}

void callHome() {
  send(&sensorMask, sizeof sensorMask);
  send(&currentState, sizeof currentState);
}

void inputScan() {
  sensorMask = getSensorMask();
  measureDistances();
}

void executeProgram() {
  updateState();
  stateAction();
}

void updateState() {
  switch (currentState) {
    //Als 'aan' en eindeloopschakelaar pompzijde ingedrukt
    case Off:
      if(running){
        currentState = DrivingForward;
      }
    case DrivingForward:
      if (sensorMask & ELOOPPOMP && running) {
        currentState = LoweringPump;
      }
      break;

    //Als 'aan' en pompsensor emmer zijn ingedrukt (dus emmer is vol)
    case LoweringPump:
      if (sensorMask & POMP1 && running) {
        currentState = RaisingPump;
      }
      break;

    //Als 'aan' en pompsensor bassin zijn ingedrukt (dus pomp is opgehaald)
    case RaisingPump:
      if (sensorMask & POMP2 && running){
        currentState = DrivingBackwards;
      }
      break;

    //Als 'aan' en eindeloopschakelaar emmer zijde ingedrukt (robot tegen vuur zijde)
    case DrivingBackwards:
      if (sensorMask & ELOOPEMMER && running) {
        currentState = RaisingBucket;
      }
      break;

    //Als 'aan' en emmer sensor bovenaan ingedrukt (emmer is dus opgehoffen)
    case RaisingBucket:
      if (sensorMask & EMMER1 && running) {
        currentState = LoweringBucket;
      }
      break;

    //Als 'aan' en emmer sensor onderaan ingedrukt (emmer terug gedaald)
    case LoweringBucket:
      if (sensorMask & EMMER2 && running) {
        currentState = DrivingForward;
      }
      break;

    //something went wrong.
    default:
      //send state
      break;
  }
}

void stateAction() {
  switch (currentState) {
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
      drive(true);
      break;
  }
}



