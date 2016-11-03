#include<math.h>

#define SIBLINGDISTANCE 4.7 //afstand tussen sensoren zelfde zijde.
#define TWINDISTANCE    60.0 //afstand tussen sensoren weerszijden.

#define S1TRIGGER 12
#define S1ECHO 13
#define S2TRIGGER 0
#define S2ECHO 1

void setup(){
  Serial.begin(9600);

  pinMode(S1TRIGGER, OUTPUT);
  pinMode(S2TRIGGER, OUTPUT);
  pinMode(S1ECHO, INPUT);
  pinMode(S2ECHO, INPUT);

  Serial.println("einde setup");
}

void loop(){
  pulse(S1TRIGGER, 20);
  long frontDist = pulseIn(S1ECHO, HIGH);
  delay(10);
  pulse(S2TRIGGER, 20);
  long backDist = pulseIn(S2ECHO, HIGH);

  //Serial.println(frontDist);

  printDist("First: ", frontDist / 58.0);
  printDist("Second: ", backDist / 58.0);
  Serial.println(" ");
  float test = calcDeviation(frontDist / 58.0, backDist / 58.0);
  printDist("Deviation in rad: ", test);
  //printDist("test ", calcDeviation(75.0, 50.0));

  Serial.print("++++++++++++++++++++++++++++++++");
  Serial.println(" ");
  delay(2000);
}

//geeft terug, in radialen, hoeveel de robot gedraaid is ten opzichte van de rechte lijn hij moet volgen.
float calcDeviation(float distFront, float distBack){
  float opposite = distFront - distBack;
  float adjacent = SIBLINGDISTANCE;
  float ratio = opposite / adjacent;

  return atan(ratio);
}

void pulse(int outputPin, int duration){
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(outputPin, LOW);
}

void printDist(char* message, float dist){
  Serial.print(message);
  Serial.println(dist);
}

