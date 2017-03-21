 #ifndef STATES_H
#define STATES_H

#include"states/driving.h"
#include"states/loweringbucket.h"
#include"states/loweringpump.h"
#include"states/raisingbucket.h"
#include"states/raisingpump.h"

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
