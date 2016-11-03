#include<math.h>

#define SIBLINGDISTANCE 4.7 //afstand tussen sensoren zelfde zijde.
#define TWINDISTANCE    60.0 //afstand tussen sensoren weerszijden.

void setup(){
}

void loop(){
}

//geeft terug, in radialen, hoeveel de robot gedraaid is ten opzichte van de rechte lijn hij moet volgen.
float calcDeviation(float distFront, float distBack){
  float opposite = distFront - distBack;
  float adjacent = SIBLINGDISTANCE;
  float ratio = opposite / adjacent;

  return atan(ratio);
}
