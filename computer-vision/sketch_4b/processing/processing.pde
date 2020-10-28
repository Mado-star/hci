import processing.serial.*; 
 
Serial myPort;  // Create object from Serial class int val;
 
void setup()  {   
  size(200, 200); 
  String portName = Serial.list()[1];   
  myPort = new Serial(this, portName, 9600); 
} 
 
int r = 255;
int g = 0;
int b = 0;

int val = 0;
 
void draw() {   

  background(255);   

  fill(r, g, b);
  rect(50, 50, 100, 100);      
} 
 
boolean mouseOverRect() { // Test if mouse is over square   
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150)); 
} 


void mouseClicked() {
  if(mouseOverRect()) {
    if (val == 0) {
        myPort.write('H');       // send an H to indicate mouse is over square  
        r = 0;
        g = 255;
        b = 0;
        val = 1;      
    }
    else {
        myPort.write('L');       // send an H to indicate mouse is over square  
        r = 255;
        g = 0;
        b = 0;
        val = 0;        
    }

  }
}
