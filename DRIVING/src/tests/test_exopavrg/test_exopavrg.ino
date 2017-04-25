#include"sensors.h"

void setup() {
  Serial.begin(9600);
  ultraPAvrg.size = 5;
  //no measure = 0
  Serial.println(ultraPAvrg.value);
  Serial.println("");
                     //size:should be new correct average
  //1. measure = 10 => 3:10 => 5:10
  ultraPAvrg.Update(10);
  Serial.println(ultraPAvrg.value);
  //2. measure = 20 => 3:15 => 5:15
  ultraPAvrg.Update(20);
  Serial.println(ultraPAvrg.value);
  //3. measure = 30 => 3:20 => 5:20
  ultraPAvrg.Update(30);
  Serial.println(ultraPAvrg.value);
  //4. measure = 40 => 3:30 => 5:25
  ultraPAvrg.Update(40);
  Serial.println(ultraPAvrg.value);
  //5. measure = 50 => 3:40 => 5:30
  ultraPAvrg.Update(50);
  Serial.println(ultraPAvrg.value);
  //6. measure = 60 => 3:50 => 5:40
  ultraPAvrg.Update(60);
  Serial.println(ultraPAvrg.value);
  //7. measure = 70 => 3:60 => 5:50
  ultraPAvrg.Update(70);
  Serial.println(ultraPAvrg.value);
  //8. measure = 80 => 3:70 => 5:60
  ultraPAvrg.Update(80);
  Serial.println(ultraPAvrg.value);
  //9. measure = 90 => 3:80 => 5:70
  ultraPAvrg.Update(90);
  Serial.println(ultraPAvrg.value);
  //10. measure = 100 => 3:90 => 5:80
  ultraPAvrg.Update(100);
  Serial.println(ultraPAvrg.value);
}

void loop() {
  
}
