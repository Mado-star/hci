
int ledPin        = 3;
int tempPin       = A0; // Temp sensor pin
int potPin        = A1; // Potmeter pin

void setup(){

  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600); // serial communication initialize
  
}

void loop(){

  //int tempValue = analogRead(tempSensorPin); // read temperature
  int potValue = analogRead(potPin);
  potValue = map(potValue, 0, 1023, 12, 26);   // map to values between 12 and 26 degrees

  //Serial.println(potValue);

  int tempValue = analogRead(tempPin);
  tempValue = map(tempValue, 525, 630, 22, 37);   // calibrate temperature sensor

  Serial.println(potValue);
  Serial.println(tempValue);

  if(potValue > tempValue) { // turn on heater (LED)
     digitalWrite(ledPin, HIGH);
  }
  else {
     digitalWrite(ledPin, LOW);
  }

}
