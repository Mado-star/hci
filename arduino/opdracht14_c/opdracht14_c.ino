#include <Servo.h>
Servo myServo;
int servoPin = 9;
int pos = 0;
int sensorPin = A0; // variable for sensor pin

void setup() {
  myServo.attach(servoPin);
  pinMode(sensorPin, INPUT);

}

void loop() {
  int sensorValue = analogRead(sensorPin);

  int pos = map(sensorValue, 0, 1023, 0, 160);
  myServo.write(pos);


}
