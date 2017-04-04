#ifndef STATES_H
#define STATES_H

#include"src/driving.h"
#include"src/loweringbucket.h"
#include"src/loweringpump.h"
#include"src/raisingbucket.h"
#include"src/raisingpump.h"

typedef enum {
  Off,
  DrivingForward,
  LoweringPump,
  RaisingPump,
  DrivingBackwards, 
  RaisingBucket,
  LoweringBucket,
  Manual
} State;

#endif
