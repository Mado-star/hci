#include <Servo.h>
Servo myServo; // Declare a servo object for us to control
int servoPin = 9; // Var for the pin the servo connects to
int pos = 90; // Var to keep track of the servo's position, neutral position

const int echoPin = 6;
const int trigPin = 7;

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


void setup() {
  myServo.attach(servoPin); // Tell the servo to what pin it's connected to
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  /*
  for(pos = 0; pos < 160; pos += 1){ // Loop, pos is added to (from 0 to 160)
    myServo.write(pos); // Turn the servo to the position in pos
    delay(15); // Wait 15ms
  }

  for(pos = 160; pos >= 1; pos -= 1){// Loop, pos is deducted from (from 160 to 1)
  myServo.write(pos); // Turn the servo to the position in pos
    delay(15); // Wait 15ms
  }
  *
   */


  myServo.write(pos);
  int distance = getDistanceCM();

  // track object
  if(distance < 10) {
  
    // check left distance
    myServo.write(pos-4);
    delay(200);
    int leftDistance = getDistance();
  
    // check right distance
    myServo.write(pos+4);
    delay(200);
    int rightDistance = getDistance();
    //int cm = getDistance();

    // now move to closest distance
    if(rightDistance < leftDistance) {
      pos = pos+8;
    }
    else if(leftDistance < rightDistance) {
      pos = pos-8;
    }

    /*
    Serial.print("l: ");
    Serial.print(leftDistance);
    Serial.print('\n');
  
    Serial.print("r: ");
    Serial.print(rightDistance);
    Serial.print('\n');
*/
    
  }




  //delay(100);

}
