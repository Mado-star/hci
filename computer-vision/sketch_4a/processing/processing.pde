import processing.serial.*; 
 
Serial myPort;  // Create object from Serial class int val;
 
void setup()  {   
  size(200, 200); 
  String portName = Serial.list()[1];   
  myPort = new Serial(this, portName, 9600); 
} 
 
void draw() {   

  background(255);   

  if (mouseOverRect() == true) {  
    fill(204);                     
    myPort.write('H');       // send an H to indicate mouse is over square   
  }    
  else {                        // If mouse is not over square,     
    fill(0);                      // change color and
    myPort.write('L');              
  }   

  rect(50, 50, 100, 100);      
} 
 
boolean mouseOverRect() { // Test if mouse is over square   
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150)); 
} 
