#include <Servo.h>
Servo myServo;
int servoPin = 9;
int pos = 0;

void setup() {
  myServo.attach(servoPin);
}

void loop() {


  for(pos = 0; pos < 30; pos += 1){
    myServo.write(pos);
    delay(3);
  }


  for(pos = 30; pos >= 1; pos -= 1){
    myServo.write(pos);
    delay(3);
  }

  for(pos = 0; pos < 90; pos += 1){
    myServo.write(pos);
    delay(3);
  }


  for(pos = 90; pos >= 1; pos -= 1){
    myServo.write(pos);
    delay(3);
  }


}
