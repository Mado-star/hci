
#include "LedControl.h"

/*
DIN connects to pin 12
CLK connects to pin 11
CS connects to pin 10
*/
LedControl lc = LedControl(8,10,9,1); // create a new LedControl object


const int echoPin = 6;
const int trigPin = 7;

byte happy[8]   =   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte sad[8]     =   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};


int getDistance() {
  // send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);   // wait for the echo

  //int cm = duration / 29 / 2; // convert the time into a distance, the speed of sound is 29 microseconds per centimeter,

  return duration;
}


int getDistanceCM() {
  // send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);   // wait for the echo

  int cm = duration / 29 / 2; // convert the time into a distance, the speed of sound is 29 microseconds per centimeter,

  return cm;
}

void setup(){
  lc.shutdown(0,false);       
  lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0);    


  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600); // serial communication initialize

}


void loop(){

  int distance = getDistanceCM();

  if(distance > 30) {
    showImage(happy);
  }
  else {
    showImage(sad);    
  }


  Serial.println(distance);


}


void showImage(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
