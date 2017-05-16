#ifndef EXPO_AVRG_H
#define EXPO_AVRG_H

#define AVRGSIZE 8

struct ExpoAvrg {
  double value;
  int size;
  void Update(double);
  ExpoAvrg(double initVal, int size);
};

#endif
