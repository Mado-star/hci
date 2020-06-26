#include <CapacitiveSensor.h>

CapacitiveSensor touchSwitchA = CapacitiveSensor(13, 12); //1 megohm resistor between pins 13 & 12, pin 12 is sensor pin

CapacitiveSensor touchSwitchB = CapacitiveSensor(11, 10); //1 megohm resistor between pins 11 & 10, pin 10 is sensor pin

CapacitiveSensor touchSwitchC = CapacitiveSensor(9, 8); //1 megohm resistor between pins 9 & 8, pin 8 is sensor pin

CapacitiveSensor touchSwitchD = CapacitiveSensor(7, 6); //1 megohm resistor between pins 7 & 6, pin 6 is sensor pin

CapacitiveSensor touchSwitchE = CapacitiveSensor(5, 4); //1 megohm resistor between pins 5 & 4, pin 4 is sensor pin

CapacitiveSensor touchSwitchF = CapacitiveSensor(3, 2); //1 megohm resistor between pins 3 & 2, pin 2 is sensor pin

int speakerPin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  //read sensor A
  long valueA = touchSwitchA.capacitiveSensor(30);
  valueA = constrain(valueA, 150, 3000);
  valueA = map(valueA, 150, 3000, 0, 255);
  Serial.println(valueA);
  
  if (valueA>100){ //if sensor value is above threshold, play tone
    tone(speakerPin, 440, 200); // plays a tone of 440Hz for 200ms
  }

  //read sensor B
  long valueB = touchSwitchB.capacitiveSensor(30);
  valueB = constrain(valueB, 150, 3000);
  valueB = map(valueB, 150, 3000, 0, 255);
  Serial.println(valueB);
  if(valueB>100){ //if sensor B value is above threshold, play tone
    tone(speakerPin, 493, 200); // plays a tone of 493Hz for 200ms
  }
  
  //read sensor C
  long valueC = touchSwitchC.capacitiveSensor(30);
  valueC = constrain(valueC, 150, 3000);
  valueC = map(valueC, 150, 3000, 0, 255);
  Serial.println(valueC);
  if (valueC>100){ //if sensor value is above threshold, play tone
    tone(speakerPin, 262, 200); // plays a tone of 262Hz for 200ms
  }
  
  //read sensor D
  long valueD = touchSwitchD.capacitiveSensor(30);
  valueD = constrain(valueD, 150, 3000);
  valueD = map(valueD, 150, 3000, 0, 255);
  Serial.println(valueD);
  if (valueD>100){ //if sensor value is above threshold, play tone
    tone(speakerPin, 330, 200); // plays a tone of 330Hz for 200ms
  }
  
  //read sensor E
  long valueE = touchSwitchE.capacitiveSensor(30);
  valueE = constrain(valueE, 150, 3000);
  valueE = map(valueE, 150, 3000, 0, 255);
  Serial.println(valueE);
  if (valueE>100){ //if sensor value is above threshold, play tone
    tone(speakerPin, 330, 200); // plays a tone of 262Hz for 200ms
  }
  
  //read sensor F
  long valueF = touchSwitchF.capacitiveSensor(30);
  valueF = constrain(valueF, 150, 3000);
  valueF = map(valueF, 150, 3000, 0, 255);
  Serial.println(valueF);
  if (valueF>100){ //if sensor value is above threshold, play tone
    tone(speakerPin, 349, 200); // plays a tone of 262Hz for 200ms
  }
}
