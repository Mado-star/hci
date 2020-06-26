

int speakerPin = 8;
int minfreq = 500;
int maxfreq = 2000;
int freq = 100;
int plus = 1;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {

  if(plus) {
    freq++;
  }
  else {
     freq--;
  }

  tone(speakerPin, freq);

  if(freq == minfreq) {
    plus = 1;
  }
  else if(freq==maxfreq) {
    plus = 0;
  }

  delay(1);

  
}
