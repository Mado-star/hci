#include <CapacitiveSensor.h>
CapacitiveSensor touchSwitch = CapacitiveSensor(4, 2);
int LEDpin = 11;

void setup(){
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  long val = touchSwitch.capacitiveSensor(30);
  Serial.println(val); // print sensor output
  val = map(val, 0, 20000, 0, 255);
  val = constrain(val, 0, 255);
  analogWrite(LEDpin, val);
}
