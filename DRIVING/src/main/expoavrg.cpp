#include"expoavrg.h" //GETEST

ExpoAvrg::ExpoAvrg(double initVal, int size) : value(initVal), size(size){}

void ExpoAvrg::Update(double newValue){
  double smoothingFactor = 2.0 / (size + 1.0);
  value = (newValue * smoothingFactor) + (value * (1 - smoothingFactor));
}

