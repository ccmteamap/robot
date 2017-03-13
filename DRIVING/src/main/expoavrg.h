#ifndef EXPO_AVRG
#define EXPO_AVRG

struct ExpoAvrg {
  double value;
  int size;
  void Update(double);
  ExpoAvrg(double initVal, int size);
};

#endif
