#ifndef STATES_H
#define STATES_H

typedef enum {
  Off,
  DrivingForward,
  LoweringPump,
  RaisingPump,
  DrivingBackwards, 
  RaisingBucket,
  LoweringBucket
} State;

#endif

