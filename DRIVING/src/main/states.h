#ifndef STATES_H
#define STATES_H

typedef enum {
  Off,
  DrivingForward,
  LoweringPump,
  RaisingPump,
  DrivingBackwards, 
  RaisingBucket,
  Pouring,
  LoweringBucket
} State;

void drive(bool);
void raisePump();
void lowerPump();
void raiseBucket();
void lowerBucket();

#endif
