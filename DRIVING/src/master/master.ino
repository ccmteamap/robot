#include<math.h>

#define SIBLINGDISTANCE 0 //afstand tussen sensoren zelfde zijde.
#define TWINDISTANCE //afstand tussen sensoren weerszijden.

void setup(){
  Serial.begin(9600);
  
  return;
}

void loop(){

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

