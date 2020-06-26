

int speakerPin = 8;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(speakerPin, OUTPUT);
  
}

void loop() {

  int sensorValue = analogRead(A0); // read sensor, 0-1023


  int freq = map(sensorValue, 45, 130, 100, 2000);

  tone(speakerPin, freq); // A

}
