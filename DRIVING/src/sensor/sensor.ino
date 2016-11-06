#include"queue.h"

#define TRIGGER 0
#define ECHO 0
#define VALIDSIZE 5
#define INVALIDSIZE 5

Queue validResults;
Queue invalidResults;
unsigned long validAvrg;

void setup(){
  Serial.begin(9600);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, OUTPUT);

  validResults = newQueue(VALIDSIZE);
  invalidResults = newQueue(INVALIDSIZE);
  
  return;
}

void loop(){
  unsigned long result = measure();
  if(isValid(result)){
    handleValid(result);
  }
  else {
    handleInvalid(result);
  }
}

void handleValid(QueueType value){
  shiftQueue(&validResults, value);
  freeQueue(&invalidResults);
  validAvrg = getAverage(validResults);
  send(validAvrg);
  return;
}

void handleInvalid(QueueType value){
  if(invalidResults.size == INVALIDSIZE){
    shiftQueue(&invalidResults, value);
    validResults = invalidResults;
    freeQueue(&invalidResults);
    validAvrg = getAverage(validResults);
    send(validAvrg);
  }
  else{
    enqueue(&invalidResults, value);
  }
}

void send(QueueType value){
  //send value to master arduino using serial communication
}

void shiftQueue(Queue* q, QueueType value){
  enqueue(&q, value);
  dequeue(&q);
}

QueueType getAverage(queue){
  //get average of values in queue;
}

unsigned long measure(){
  pulse(TRIGGER, 10);
  return pulseIn(ECHO, HIGH);
}

void pulse(int pin, int duration){
  digitalWrite(pin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(pin, LOW);

  return;
}

bool isValid(unsigned long measurement){
  //see if measured distance is within margin of average.
}