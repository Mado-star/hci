

int speakerPin = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
  
}

void loop() {

  tone(speakerPin, 440, 500); // A
  delay(250);

  
  tone(speakerPin, 440, 500); // A
  delay(250);


  tone(speakerPin, 440, 500); // A
  delay(250);


  tone(speakerPin, 493, 500); // B
  delay(250);

  tone(speakerPin, 523, 500); // C
  delay(500);

}
