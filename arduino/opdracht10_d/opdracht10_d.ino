int ledPin = 13;
int sensorPin = A0;

int threshold = 33;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sensorValue = analogRead(sensorPin); // read sensorpin
  Serial.println(sensorValue); // print to serial monitor

  if(sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); // wait
}
