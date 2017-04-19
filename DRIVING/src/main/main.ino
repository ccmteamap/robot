/*
   Team Poembak Delco
   AP Hogeschool
   2017
*/

#include"main.h" //interface om robot aan/uit/pauze te zetten
#include"sensors.h" //nodig om de sensormask te krijgen
#include"comm.h" //kijken of er instructie zijn ontvangen.
#include"parser.h" //nodig om ontvangen instructies te ontleden
#include"debug.h"//nodig om debug informatie door te laten sturen
#include"motor.h"
#include<stdint.h>

bool running;
State currentState = Off;
int sensorMask = 0;

void setup() {
  initSensorPins();
  startComm();
}

void loop() {
  inputScan(); //update status of sensors.
  executeProgram(); //update state and perform action
  callHome(); //send debugging information.
  listenHome(); //see if we got instructions.
}

void listenHome() {
  uint8_t buffer[PAYLOAD_SIZE];

  if(read(buffer)){
    parse(buffer);
  }
}

void callHome() {
  debug();
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
    case Off:
      if(running){
        currentState = DrivingForward;
      }

    //Als 'aan' en eindeloopschakelaar pompzijde ingedrukt
    case DrivingForward:
      if (sensorMask & ELOOPPOMP && running) {
	stopDriving();
        currentState = LoweringPump;
      }
      break;

    //Als 'aan' en pompsensor emmer zijn ingedrukt (dus emmer is vol)
    case LoweringPump:
      if (sensorMask & POMP1 && running) {
	stopLowerPump();
        currentState = RaisingPump;
      }
      break;

    //Als 'aan' en pompsensor bassin zijn ingedrukt (dus pomp is opgehaald)
    case RaisingPump:
      if (sensorMask & POMP2 && running){
	stopRaisePump();
        currentState = DrivingBackwards;
      }
      break;

    //Als 'aan' en eindeloopschakelaar emmer zijde ingedrukt (robot tegen vuur zijde)
    case DrivingBackwards:
      if (sensorMask & ELOOPEMMER && running) {
	stopDriving();
        currentState = RaisingBucket;
      }
      break;

    //Als 'aan' en emmer sensor bovenaan ingedrukt (emmer is dus opgehoffen)
    case RaisingBucket:
      if (sensorMask & EMMER1 && running) {
	stopRaiseBucket();
        currentState = LoweringBucket;
      }
      break;

    //Als 'aan' en emmer sensor onderaan ingedrukt (emmer terug gedaald)
    case LoweringBucket:
      if (sensorMask & EMMER2 && running) {
	stopLowerBucket();
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

void pause(){
  running = false;
  stopMotors();
}

void run(){
  running = true;
}

void stop(){
  running = false;
  currentState = Off;
  stopMotors();
}

State getState(){
  return currentState;
}

void stopMotors(){
  mainMotor.SetSpeed(0);
  emmerMotor.SetSpeed(0);
  pompMotor.SetSpeed(0);
}