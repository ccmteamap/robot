/*
   Team Poembak Delco
   AP Hogeschool
   2017
*/

#include"states.h"
#include"sensors.h"
//#include"comm.h"

<<<<<<< HEAD
#define CE 9 //nodig voor nRF24
#define CSN 10 //nodig voor nRF24

State currentState = DrivingForward;
=======
bool running;
State currentState = Off;
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
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
<<<<<<< HEAD
//TODO
Serial.print("Sensormask: "); Serial.println(sensorMask);
Serial.print("currentState: "); Serial.println(currentState);
Serial.println(digitalRead(7)); Serial.println(digitalRead(8));
delay(500);
=======
  send(&sensorMask, sizeof sensorMask);
  send(&currentState, sizeof currentState);
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
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
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & ELOOPPOMP){
=======
      if (sensorMask & ELOOPPOMP && running) {
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
        currentState = LoweringPump;
      }
      break;

    //Als 'aan' en pompsensor emmer zijn ingedrukt (dus emmer is vol)
    case LoweringPump:
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & POMP1){
=======
      if (sensorMask & POMP1 && running) {
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
        currentState = RaisingPump;
      }
      break;

    //Als 'aan' en pompsensor bassin zijn ingedrukt (dus pomp is opgehaald)
    case RaisingPump:
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & POMP2){
=======
      if (sensorMask & POMP2 && running){
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
        currentState = DrivingBackwards;
      }
      break;

    //Als 'aan' en eindeloopschakelaar emmer zijde ingedrukt (robot tegen vuur zijde)
    case DrivingBackwards:
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & ELOOPEMMER){
=======
      if (sensorMask & ELOOPEMMER && running) {
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
        currentState = RaisingBucket;
      }
      break;

    //Als 'aan' en emmer sensor bovenaan ingedrukt (emmer is dus opgehoffen)
    case RaisingBucket:
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & EMMER1){
=======
      if (sensorMask & EMMER1 && running) {
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
        currentState = LoweringBucket;
      }
      break;

    //Als 'aan' en emmer sensor onderaan ingedrukt (emmer terug gedaald)
    case LoweringBucket:
<<<<<<< HEAD
      if(sensorMask & ON && sensorMask & EMMER2){
=======
      if (sensorMask & EMMER2 && running) {
>>>>>>> 77163eb4901195b965d146436eef2aa833819187
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



