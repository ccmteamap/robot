int trigPinU1 = 12;
int echoPinU1 = 13;
int ledU1 = 22; 
int trigPinU2 = 10;
int echoPinU2 = 11;
int ledU2 = 23;
long duration, distance, U1, U2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPinU1, OUTPUT);
  pinMode(echoPinU1, INPUT);
  pinMode(trigPinU2, OUTPUT);
  pinMode(echoPinU2, INPUT);
  pinMode(ledU1, OUTPUT);
  pinMode(ledU2, OUTPUT);
}

void loop() {
  digitalWrite(ledU1, LOW);
  digitalWrite(ledU2, LOW);
  
  SonarSensor(trigPinU2, echoPinU2, ledU2);
  U2 = distance;
  SonarSensor(trigPinU1, echoPinU1, ledU1);
  U1 = distance;

  Serial.print("U1: ");
  Serial.print(U1);
  Serial.print("cm & U2: ");
  Serial.print(U2);
  Serial.println("cm");

  delay(100);

}

void SonarSensor(int trigPin, int echoPin, int ledPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / (2*29.1));
  if(distance < 20) digitalWrite(ledPin, HIGH);
  else  digitalWrite(ledPin, LOW);
}


