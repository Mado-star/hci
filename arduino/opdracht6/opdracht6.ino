float sensorValue = 0; // variable for sensor value
int sensorPin = A0; // variable for sensor pin
int greenLedPin = 10;
int yellowLedPin = 9;

void setup() {
 pinMode(greenLedPin, OUTPUT);
 pinMode(yellowLedPin, OUTPUT);
 pinMode(sensorPin, INPUT);
 Serial.begin(9600);
}
void loop() {
 sensorValue = analogRead(sensorPin); // read the value/voltage on the sensor pin and
 sensorValue = (sensorValue/1023)*255;
 analogWrite(greenLedPin, sensorValue);
 analogWrite(yellowLedPin, sensorValue);
 // store that value in the variable sensorValue
 Serial.println(sensorValue); // print out sensorValue to the Serial Monitor
 delay(20); // delay for 0.2 seconds
}
