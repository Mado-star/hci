int sensorValue = 0; // variable for sensor value
int sensorPin = A0; // variable for sensor pin
void setup() {
 pinMode(sensorPin, INPUT);
 Serial.begin(9600);
}
void loop() {
 sensorValue = analogRead(sensorPin); // read the value/voltage on the sensor pin and
 // store that value in the variable sensorValue
 Serial.println(sensorValue); // print out sensorValue to the Serial Monitor
 delay(200); // delay for 0.2 seconds
}
