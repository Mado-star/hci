
#include "LedControl.h"

/*
DIN connects to pin 12
CLK connects to pin 11
CS connects to pin 10
*/
LedControl lc = LedControl(8,10,9,1); // create a new LedControl object

int dice_value = 0;

byte one[8]   = { 0B00000000, 0B00000000, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B00000000, 0B00000000};
byte two[8]   = { 0B00000000, 0B01100000, 0B01100000, 0B00000000, 0B00000000, 0B00000110, 0B00000110, 0B00000000};
byte three[8] = { 0B11000000, 0B11000000, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B00000011, 0B00000011};
byte four[8]  = { 0B00000000, 0B01100110, 0B01100110, 0B00000000, 0B00000000, 0B01100110, 0B01100110, 0B00000000};
byte five[8]  = { 0B11000011, 0B11000011, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B11000011, 0B11000011};
byte six[8]   = { 0B01100110, 0B01100110, 0B00000000, 0B01100110, 0B01100110, 0B00000000, 0B01100110, 0B01100110};

byte dice_images[6][8] = {
  { 0B00000000, 0B00000000, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B00000000, 0B00000000},
  { 0B00000000, 0B01100000, 0B01100000, 0B00000000, 0B00000000, 0B00000110, 0B00000110, 0B00000000},
  { 0B11000000, 0B11000000, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B00000011, 0B00000011},
  { 0B00000000, 0B01100110, 0B01100110, 0B00000000, 0B00000000, 0B01100110, 0B01100110, 0B00000000},
  { 0B11000011, 0B11000011, 0B00000000, 0B00011000, 0B00011000, 0B00000000, 0B11000011, 0B11000011},
  { 0B01100110, 0B01100110, 0B00000000, 0B01100110, 0B01100110, 0B00000000, 0B01100110, 0B01100110}
};

int buttonPin = 2;

void setup(){
  lc.shutdown(0,false);       
  lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0);    

  pinMode(buttonPin, INPUT);


  Serial.begin(9600); // serial communication initialize

}


void loop(){

  int button_pressed = 0;
  while (digitalRead(buttonPin) == HIGH) {
    //dice_value = random(0,6);
    button_pressed = 1;
  }
  if (button_pressed) {
    for(int i = 0; i < 10; i++) {
      dice_value = random(0,6);
      showImage(dice_images[dice_value]);
      delay(300);
  
    }
  }
  
  showImage(dice_images[dice_value]);

  //Serial.println(distance);


}


void showImage(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
