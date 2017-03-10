void setup() {
  initPins(); //set pins as INPUT or OUTPUT
  connect(); //connect to home.
  testSensors(); //see if all sensors are able to measure.
  callHome(); //send debugging information (about state of sensors)
}

void loop() {
  checkInputs(); //update status of sensors.
  updateState(); //check to see if status should be changed according to updated sensor states.
  callHome(); //send debugging information.
}

void initPins(){
  
}

void connect(){
  
}

void testSensors(){
  
}

void callHome(){
  
}

void checkInputs(){
  
}

void updateState(){
  
}
