void drawPoint(color myColor, XYPt xy){
  pushStyle();
    ellipseMode(CENTER);
    fill(myColor);
    float radius = max((float) (2*xy.getRadius()), (float) cameraHeight/80);
    ellipse( (float) xy.getX(), (float) xy.getY(), radius, radius);
  popStyle();
}
