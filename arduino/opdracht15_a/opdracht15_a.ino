#include <CapacitiveSensor.h>

  CapacitiveSensor touchSwitch = CapacitiveSensor(4, 2);
  int LEDpin = 11;
  
void setup(){
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  long val = touchSwitch.capacitiveSensor(100);
  if (val > 100) {
    digitalWrite(LEDpin, HIGH);
  } else {
    digitalWrite(LEDpin, LOW);
  }

  Serial.println(val); // print sensor output
}
