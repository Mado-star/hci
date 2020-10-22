
#include "LedControl.h"

/*
DIN connects to pin 12
CLK connects to pin 11
CS connects to pin 10
*/
LedControl lc = LedControl(8,10,9,1); // create a new LedControl object

int sensorValue = 0; // variable for sensor value
int sensorPin = A0; // variable for sensor pin

int minVal = 235;
int maxVal = 493;

/* Map an analog value to 8 bits (0 to 255) */
void setup() {

  lc.shutdown(0,false);       
  lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0);    


  Serial.begin(9600); // serial communication initialize

}

void loop() {
  
  int val = analogRead(sensorPin);
  val = map(val, minVal, maxVal, 0, 255);

  Serial.print(val);
  Serial.print("\n");


  int rows = val/8;
  int cols = val - rows*8;

  for(int i = 0; i < 8; i++) {

    if(i < rows) {
          lc.setRow(0,i,0b11111111);
    }
    
    else if (i == rows) {
          lc.setRow(0,i,0b11111111);
          byte tmp = 0;
          for(int j = 0; j < cols; j++) {
            tmp |= 1 << j;
          }
          lc.setRow(0,i,tmp);
      
    }
    else {
      lc.setRow(0,i, 0b00000000);
    }
    
  }

  delay(10);

}
