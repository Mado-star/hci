

int speakerPin = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  tone(speakerPin, 262, 200);
  delay(250); // plays a tone of 262Hz for 200ms
  
  // wait 250 ms
  tone(speakerPin, 294, 200);
  delay(250); // plays a tone of 294Hz for 200ms

  // wait 250 ms
  tone(speakerPin, 330, 200);
  delay(250); // plays a tone of 330Hz for 200ms

  // wait 250 ms
  tone(speakerPin, 262, 200);
  delay(500);
  // plays a tone of 262Hz for 200ms
  // wait 500 ms
}
