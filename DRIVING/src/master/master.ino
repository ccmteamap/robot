#include<math.h>
#include"queue.h"

#define SIBLINGDISTANCE 0 //afstand tussen sensoren zelfde zijde.
#define TWINDISTANCE //afstand tussen sensoren weerszijden.

#define FRONTTRIGGER 0
#define FRONTECHO 0
#define BACKTRIGGER 0
#define BACKECHO 0

Queue validResults = newQueue();
Queue invalidResult = newQueue();

void setup(){
  Serial.begin(9600);
  
  pinMode(FRONTTRIGGER, OUTPUT);
  pinMode(FRONTECHO, INPUT);
  pinMode(BACKTRIGGER, OUTPUT);
  pinMode(BACKECHO, INPUT);
  
  return;
}

void loop(){
  pulse(FRONTTRIGGER, 10);
  float frontDistance = pulseIn(FRONTECHO, HIGH) / 58.0;

  pulse(BACKTRIGGER, 10);
  float backDistance = pulseIn(BACKECHO, HIGH) / 58.0;

  float rad = calcDeviation(frontDistance, backDistance);
  float degree = radToDegree(rad);

  dMsg("Front: ", frontDistance);
  dMsg("Back: ", backDistance);
  dMsg("Rad: ", rad);
  dMsg("Degrees: ", degree);
  Serial.println("+++++++++++++++++++++++");

  return;
}

//geeft terug, in radialen, hoeveel de robot gedraaid is ten opzichte van de rechte lijn hij moet volgen.
float calcDeviation(float distFront, float distBack){
  float opposite = distFront - distBack;
  float adjacent = SIBLINGDISTANCE;

  return atan(opposite / adjacent);
}

float radToDegree(float rad){
  return (rad * 180) / PI;
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

