int ledPin = 13;
int sensorPin = A0;

int threshold = 36;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sensorValue = analogRead(sensorPin); // read sensorpin
  Serial.println(sensorValue); // print to serial monitor

  delay(500); // wait
}
