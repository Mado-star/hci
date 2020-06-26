const int echoPin = 6;
const int trigPin = 7;
int ledRedPin = 8;
int ledYellowPin = 9;
int ledGreenPin = 10;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  // wait for the echo
  long duration = pulseIn(echoPin, HIGH); 
  
  
  // convert the time into a distance, the speed of sound is 29 microseconds percentimeter,
  //the pulse traveled forth and back, so we divided the distance by 2
  int cm = duration / 29 / 2;

  Serial.println(cm);


  //if the measured distance is lower than 50 cm, turn on LED
  if(cm<140) {
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledYellowPin, LOW);
    digitalWrite(ledGreenPin, LOW);
  
  }
  else if(cm > 140 && cm < 160) {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledYellowPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
  }
  else {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledYellowPin, LOW);
    digitalWrite(ledGreenPin, HIGH);
  }
  
  delay(100);
}
