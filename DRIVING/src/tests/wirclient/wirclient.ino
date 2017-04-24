#include"comm.h"
#include"debug.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  handleInput();
}

void handleInput(){
  static char buffer[PAYLOAD_SIZE];
  static int index;
  
  while(Serial.available()){
    char symbol = Serial.read();
    if(symbol == '\n'){
      buffer[index] = '\0';

      if(isValidInstruction(buffer)){
        if(true){
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
bool containsChar(char *string, char character){
  if(!(*string)){ //if string is empty
    return false;
  }

  else {
    return (*string == character || containsChar(string + 1, character));
  }
}

bool isValidMotorInstruction(char *instruction){
  if(*instruction == 'M' && *(instruction + 1) - '0' >= 0 && *(instruction + 1) - '0' <= 2){
    instruction += 2;
    
    if(containsChar("SP", *instruction)){
      int value = atoi(instruction + 1);
      
      if(*instruction == 'S'){
        return value < 255 && value > -255;
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
