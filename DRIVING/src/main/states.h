#ifndef STATES_H
#define STATES_H

typedef enum {
  Off,
  DrivingForward,
  LoweringPump,
  Pumping,
  RaisingPump,
  DrivingBackwards, 
  RaisingBucket,
  Pouring,
  LoweringBucket
} State;

void drive(bool);
void raisePump();
void lowerPump();
void pump();
void raiseBucket();
void lowerBucket();

#endif
