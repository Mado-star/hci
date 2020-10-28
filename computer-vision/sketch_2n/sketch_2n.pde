int diameter = 10;

void setup() {  
  size(200,200);
  smooth();
  background(200, 200, 200);
  frameRate(15);
}
 
void draw() {
  ellipse(mouseX, mouseY, diameter, diameter);
  diameter++;
}
