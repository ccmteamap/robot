#include"expoavrg.h"

double calcExpoAvrg(double newValue, ExpoAvrg average) {
  double smoothingFactor = 2.0 / (average.size + 1.0);
  return (newValue * smoothingFactor) + (average.value * (1 - smoothingFactor));
}
