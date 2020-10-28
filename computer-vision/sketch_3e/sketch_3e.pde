import gab.opencv.*;
import processing.video.*;

OpenCV opencv;
Capture video;

void setup() {
  //PImage src = loadImage("robot_light.jpg");
  //src.resize(800, 0);
  
  //size(src.width, src.height);
  size(640, 480);
  video = new Capture(this, 640, 480);
  opencv = new OpenCV(this, 640, 480);
  
  //opencv = new OpenCV(this, src);

  video.start();

}

void draw() {
  opencv.loadImage(video);

  image(video, 0, 0 );
  
  //image(opencv.getOutput(), 0, 0); //draw openCV output, this is what opencv sees
  
  PVector loc = opencv.max();
  PVector locmin = opencv.min(); 
  
  stroke(255, 0, 0);
  strokeWeight(4);
  noFill();
  ellipse(loc.x, loc.y, 10, 10);
  
  stroke(0, 255, 0);
  strokeWeight(4);
  noFill();
  ellipse(locmin.x, locmin.y, 10, 10);
  
}

void captureEvent(Capture c) {
  c.read();
}
