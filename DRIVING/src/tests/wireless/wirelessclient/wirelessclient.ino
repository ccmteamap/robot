#include"comm.h"

char test[10];
char test2[10] = "supppp";

void setup(){
  Serial.begin(9600);
  startComm();
}

void loop(){
  Serial.println(sizeof test);
  Serial.println(test);
  Serial.println(test2);
  
  if(read(test, sizeof test)){
    //Serial.print(test2);
  }
  else {
    //Serial.println("niets");
  }

  delay(500);
}
