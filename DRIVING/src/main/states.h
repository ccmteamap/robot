#ifndef STATES
#define STATES

#define ON 0x01
#define ELOOPEMMER 0x02
#define ELOOPPOMP 0x04
#define POMP1 0x08
#define POMP2 0x10
#define EMMER1 0x20
#define EMMER2 0x40

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
