float sensorValue = 0; // variable for sensor value
int sensorPin = A0; // variable for sensor pin
int greenLedPin = 10;
int yellowLedPin = 9;

/* Map an analog value to 8 bits (0 to 255) */
void setup() {}

void loop() {
  int val = analogRead(0);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(yellowLedPin, val);
  analogWrite(greenLedPin, 255-val);
}
