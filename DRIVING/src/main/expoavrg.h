#ifndef EXPO_AVRG
#define EXPO_AVRG

#include<stdint.h>

typedef struct {
  double value; //current value of average.
  uint16_t size; //number of elements this exponential moving average encompasses.
} ExpoAvrg;

double calcExpoAvrg(double, ExpoAvrg);

#endif
