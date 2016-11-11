/*
Program to use the HC - SR04 Ultrasonic sensor.
Smoothens measurements using an exponential moving average.


AP CCM Team 2016
*/

#include <NewPing.h>
#include<math.h>

#define TRIGGER 7
#define ECHO 8
#define MAXDISTANCE 90 //in cm.

#define SAMPLESIZE 1000.0 //number of measurements in exponential moving average.
#define DEVIATIONMAX 28 //amount a new measurement can deviate from the average.
#define INVALIDMAX 5 //number of invalid measurements before further action required.

unsigned int validAverage;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  sensorCheck();
  
  return;
}

void loop() {
  unsigned int distance = measure();
  if (isValid(distance)) {
    handleValid(distance);
  }
  else {
    handleInvalid(distance);
  }
  
  delay(30);
}

unsigned int measure(){
  static NewPing sensor(TRIGGER, ECHO, MAXDISTANCE);
  return sensor.ping();
}

//returns true if result is within MAXDEVIATION of the average of valid results.
bool isValid(unsigned int distance) {
  unsigned int deviation;
  if (distance <= validAverage) {
    deviation = validAverage - distance;
  }
  else {
    deviation = distance - validAverage;
  }

  if (deviation > DEVIATIONMAX) {
    return false;
  }

  return true;
}

void handleValid(unsigned int distance) {
  validAverage = calcAverage(distance, validAverage); 
  send(validAverage);
}

void handleInvalid(unsigned int distance){
  static int invalidMeasurements = 0;
  
  if(invalidMeasurements >= INVALIDMAX){
    validAverage = distance;
    invalidMeasurements = 0;
    send(validAverage);
  }
  else{
    invalidMeasurements++;
  }

  return;
}

//sends value to master Arduino
void send(unsigned long value){
  return;
}

//calculates a new exponential moving average.
unsigned int calcAverage(unsigned int distance, unsigned long average) {
  static float smoothingFactor = 2.0 / (SAMPLESIZE + 1.0);
  double newAverage = (distance * smoothingFactor) + (average * (1 - smoothingFactor));
  return round(newAverage);
}

void sensorCheck() {
  validAverage = measure(); //Gets the first average for use in exponential moving average calculation.
  if (validAverage == 0) {
    //Sensor isn't working. Action required.
  }

  return;
}


