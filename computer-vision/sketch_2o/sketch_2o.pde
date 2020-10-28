int diameter = 10;

void setup() {  
  size(200,200);
  smooth();
  background(200, 200, 200);
  frameRate(15);
}
 
void draw() {
  background(200, 200, 200);
  line(100, 100, mouseX, mouseY);
  
  fill(mouseX, mouseY, mouseX);
  ellipse(100,100, mouseY, mouseX);
  //ellipse(mouseX, mouseY, diameter, diameter);
  diameter++;
}
