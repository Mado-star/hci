int greenLedPin = 10;
int yellowLedPin = 9;
int rood=0;
int geel=256;

void setup() {
 pinMode(greenLedPin, OUTPUT);
 pinMode(yellowLedPin, OUTPUT);
}
void loop() {
  rood++;
  geel--;
  
 analogWrite(greenLedPin, rood);
 analogWrite(yellowLedPin, geel);
 delay(10);
 }
