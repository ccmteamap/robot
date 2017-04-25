typedef enum {
  Off,
  DrivingForward,
  LoweringPump,
  RaisingPump,
  DrivingBackwards, 
  RaisingBucket,
  LoweringBucket
} State;

#define ELOOPEMMER 0x01
#define ELOOPPOMP 0x02
#define POMP1 0x04
#define POMP2 0x08
#define EMMER1 0x10
#define EMMER2 0x20


State currentState = Off;
bool running = true;
int sensorMask = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("<START>");
  Serial.print("START: running: ");
  Serial.println(running);
  Serial.print("currentState: ");
  Serial.println(currentState);
  Serial.print("sensorMask: ");
  Serial.println(sensorMask);
  Serial.println("</START>");
  Serial.println("");

  Serial.println("METHODES AANGEROEPEN:");
  updateState();
  Serial.println("");

  Serial.println("<RUN>");
  Serial.print("currentState: ");
  Serial.println(currentState);
  Serial.print("sensorMask: ");
  Serial.println(sensorMask);
  Serial.println("</RUN>");
}

void loop() {

}


void updateState() {
  switch (currentState) {
    case Off:   //ok
      if(running){
        currentState = DrivingForward;
      }

    //Als 'aan' en eindeloopschakelaar pompzijde ingedrukt
    case DrivingForward:    //ok
      if (sensorMask & ELOOPPOMP && running) {
  stopDriving();
        currentState = LoweringPump;
      }
      break;

    //Als 'aan' en pompsensor emmer zijn ingedrukt (dus emmer is vol)
    case LoweringPump:    //ok
      if (sensorMask & POMP1 && running) {
  stopLowerPump();
        currentState = RaisingPump;
      }
      break;

    //Als 'aan' en pompsensor bassin zijn ingedrukt (dus pomp is opgehaald)
    case RaisingPump:   //ok
      if (sensorMask & POMP2 && running){
  stopRaisePump();
        currentState = DrivingBackwards;
      }
      break;

    //Als 'aan' en eindeloopschakelaar emmer zijde ingedrukt (robot tegen vuur zijde)
    case DrivingBackwards:    //ok
      if (sensorMask & ELOOPEMMER && running) {
  stopDriving();
        currentState = RaisingBucket;
      }
      break;

    //Als 'aan' en emmer sensor bovenaan ingedrukt (emmer is dus opgehoffen)
    case RaisingBucket:   //ok
      if (sensorMask & EMMER1 && running) {
  stopRaiseBucket();
        currentState = LoweringBucket;
      }
      break;

    //Als 'aan' en emmer sensor onderaan ingedrukt (emmer terug gedaald)
    case LoweringBucket:    //ok
      if (sensorMask & EMMER2 && running) {
  stopLowerBucket();
        currentState = DrivingForward;
      }
      break;

    //something went wrong.
    default:
      //send state
      break;
  }
}

void stopDriving(){
  Serial.println("stopDriving aangeroepen");
}
void stopLowerPump(){
  Serial.println("stopLowerPump aangeroepen");
}
void stopRaisePump(){
  Serial.println("stopRaisePump aangeroepen");
}
void stopRaiseBucket(){
  Serial.println("stopRaiseBucket aangeroepen");
}
void stopLowerBucket(){
  Serial.println("stopLowerBucket aangeroepen");
}

