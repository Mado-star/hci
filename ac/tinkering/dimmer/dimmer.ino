
#include "LedControl.h"

int buttonPin = 2;
int ledPin    = 3;

int dimValue  = 0;

void setup(){

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);


  Serial.begin(9600); // serial communication initialize

}


void loop(){

  int button_pressed = 0;
  if (digitalRead(buttonPin) == HIGH) {
    dimValue +=32;
  }
  while (digitalRead(buttonPin) == HIGH);
  delay(20);

  analogWrite(ledPin, dimValue);

}
