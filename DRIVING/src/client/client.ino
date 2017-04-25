#include"comm.h"
#include"debug.h"
#include"sensors.h"
#include"states.h"
#include<string.h>
#include<stdlib.h>

void setup(){
  Serial.begin(9600);
  startComm();
}

void loop(){
  checkSerial(); //see if we received data on the serial connection
  checkRF(); //see if we received data on the wireless connection
}

void checkSerial(){
  if(Serial.available()){
    handleInput();
  }
}

//GETEST
void handleInput(){
  static char buffer[PAYLOAD_SIZE];
  static int index;
  
  while(Serial.available()){
    char symbol = Serial.read();
    if(symbol == '\n'){
      buffer[index] = '\0';

      if(isValidInstruction(buffer)){
	      if(!send(buffer, sizeof buffer)){
	        Serial.println("COMMUNICATION ERROR: could not send instruction.");
	      }
      }
      
      else {
	      Serial.println("SYNTAX ERROR: not a valid instruction.");
      }

      index = 0;
    }
    
    else if(index < PAYLOAD_SIZE - 1){ //- 1 want laatste plaats in buffer is voor newline
      if(symbol != ' ' && symbol != '\t'){
	      buffer[index++] = symbol;
      }
    }

    else {
      Serial.println("SYNTAX ERROR: instruction too long.");
      index = 0;
    }
  }
}

//GETEST
bool isValidInstruction(char *instruction){
  if(containsChar("RPS", *instruction) ||
     isValidDebugInstruction(instruction) ||
     isValidMotorInstruction(instruction)){
    return true;
  }
  else {
    return false;
  }
}

//GETEST
bool isValidDebugInstruction(char *instruction){
  if(*instruction == 'D'){ 
    while(*++instruction){
      if(!containsChar("STAM", *instruction)){
	      return false;
      }
    }
    
    return true;
  }
  
  else {
    return false;
  }
}

//GETEST
bool isValidMotorInstruction(char *instruction){
  if(*instruction == 'M' && *(instruction + 1) - '0' >= 0 && *(instruction + 1) - '0' <= 2){
    instruction += 2;
    
    if(containsChar("SP", *instruction)){
      int value = atoi(instruction + 1);
      
      if(*instruction == 'S'){
	      return value <= 255 && value >= -255;
      }
      
      else if(*instruction == 'P'){
	      return value <= 100 && value >= 0;
      }
    }
    
    else {
      return false;
    }
  }
  
  else {
    return false;
  }
}

//GETEST
void checkRF(){
  Debug_Message message;
  if(read(&message, sizeof message)){
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

    Serial.println("-");
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
