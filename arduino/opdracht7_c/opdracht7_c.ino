#include "LedControl.h"
/*
DIN connects to pin 12
CLK connects to pin 11
CS connects to pin 10
*/

LedControl lc = LedControl(12,11,10,1);

void setup() {
  lc.shutdown(0,false); // Turn matrix on, no power saving
  lc.setIntensity(0,8); // Set brightness to a medium value
  lc.clearDisplay(0);
  // Clear the display
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0); // read sensor, 0-1023
  Serial.println(sensorValue);
  sensorValue = map(sensorValue, 0, 800, 0, 7);
  // remap the value 0-7. (800 eliminates noise)
  lc.clearDisplay(0);
  //lc.setRow(0, sensorValue, B11111111);
  
  for(int i = 0; i < sensorValue; i++) {
    lc.setRow(0, i, B11111111);
  }
  // Clear the display
  // Turn one line on
  delay(20);
}
