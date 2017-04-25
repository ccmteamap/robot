#include"comm.h"

char test[] = "sup.";

void setup(){
  Serial.begin(9600);
  startComm();
}

void loop(){
  if(send(test, sizeof test)){
    Serial.println("verstuurd");
  }

  delay(300);
}

