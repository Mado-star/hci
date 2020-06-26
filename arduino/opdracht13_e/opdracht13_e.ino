int ledPin = 13;
int buttonPinL = 3;
int buttonPinR = 2;
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPinL, INPUT);
pinMode(buttonPinR, INPUT);
}
void loop(){

  digitalWrite(ledPin, !digitalRead(buttonPinR) | !digitalRead(buttonPinL));

}
