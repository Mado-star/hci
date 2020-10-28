#include <CapacitiveSensor.h>
#include <MaxMatrix.h>
#include <avr/pgmspace.h>


CapacitiveSensor touchSwitch = CapacitiveSensor(5, 4);
int speakerPin = 7;

void setup(){

  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop(){

  long val = touchSwitch.capacitiveSensor(30);
  Serial.println(val); // print sensor output

  //val = map(val, 0, 20000, 0, 255);
  //val = constrain(val, 0, 255);

  //Serial.println(val);
  
  if(val > 50) {
    //delay(3000);
    tone(speakerPin, 1000, 200);
  }

  //delay(500);
}
