#include"queue.h"

#define TRIGGER 0
#define ECHO 0

Queue validResults = newQueue();
Queue invalidResult = newQueue();

void setup(){
  Serial.begin(9600);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);;
  
  return;
}

void loop(){
  pulse(TRIGGER, 10);
  float distance = pulseIn(ECHO, HIGH) / 58.0;

  return;
}

void pulse(int pin, int duration){
  digitalWrite(pin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(pin, LOW);

  return;
}

void dMsg(char* msg, float amount){
  Serial.print(msg);
  Serial.println(amount);

  return;
}

bool isValid(float measurement){
  
  
  return 1;
}

