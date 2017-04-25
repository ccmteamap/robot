#include"sensors.h"
#include"debug.h"
#include"comm.h"

void setup() {
  Serial.begin(9600);
  startComm();
}

void loop() {
  // put your main code here, to run repeatedly:
  checkRF();
}

void checkRF(){
  Debug_Message message;
  if(read(&message, sizeof message)){
    //Serial.println("received");
    //Serial.println(message.type);
    switch(message.type){
    case DEBUG_MOTOR:
      printMotorInfo(message.body.motorInfo);
      break;

    case DEBUG_DISTANCE:
      printDistanceInfo(message.body.distanceInfo);
      break;

    case DEBUG_STATE:
      printStateInfo(message.body.stateInfo);
      break;

    case DEBUG_SENSORS:
      printSensorsInfo(message.body.sensorsInfo);
      break;
    }
  }
}

//GETEST
void printMotorInfo(Motor_Info info){
  static const char *motorIds[] = {
    "main",
    "emmer",
    "pomp"
  };
  
  Serial.print("Motor ");
  Serial.print(motorIds[info.id]);
  Serial.print(": ");

  Serial.print("speed: ");
  Serial.print(info.speed);
  Serial.print(" power: ");
  Serial.println(info.power);
}

//GETEST
void printDistanceInfo(Distance_Info info){
  Serial.print("Afstand emmer: ");
  Serial.print(info.emmerDistance / 59.0);
  Serial.print(", afstand pomp: ");
  Serial.println(info.pompDistance / 59.0);
}

//GETEST
void printStateInfo(State_Info info){
  Serial.print("Staat: ");
  switch(info.state){
  case Off:
    Serial.println("Off");
    break;
  case DrivingForward:
    Serial.println("DrivingForward");
    break;
  case LoweringPump:
    Serial.println("LoweringPump");
    break;
  case RaisingPump:
    Serial.println("RaisingPump");
    break;
  case DrivingBackwards:
    Serial.println("DrivingBackwards");
    break;
  case RaisingBucket:
    Serial.println("RaisingBucket");
    break;
  case LoweringBucket:
    Serial.println("LoweringBucket");
    break;
  }
}

//GETEST
void printSensorsInfo(Sensors_Info info){
  Serial.print("Sensormask: ");
  Serial.print(info.sensorMask);
  Serial.print(" (");

  if(info.sensorMask & ELOOPEMMER){
    Serial.print(" ELE");
  }

  if(info.sensorMask & ELOOPPOMP){
    Serial.print(" ELP");
  }

  if(info.sensorMask & POMP1){
    Serial.print(" PO");
  }

  if(info.sensorMask & POMP2){
    Serial.print(" PB");
  }

  if(info.sensorMask & EMMER1){
    Serial.print(" EB");
  }

  if(info.sensorMask & EMMER2){
    Serial.print(" EO");
  }

  Serial.println(" )");
}

//GETEST
bool containsChar(char *string, char character){
  if(!(*string)){ //if string is empty
    return false;
  }

  else {
    return (*string == character || containsChar(string + 1, character));
  }
}
