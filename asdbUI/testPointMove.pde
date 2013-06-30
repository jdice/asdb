void testPointMove(){
  testTheta += 0.0020;
  currentXY = new XYPt(1000+400*cos(testTheta+PI), 1000-730*sin(testTheta+PI));
  currentLocation = new LatLonPt(currentXY);
  guiCurrentLat.setValue((float) currentLocation.getLat());
  guiCurrentLon.setValue((float) currentLocation.getLon());
  float goalTheta = testTheta;
  goalTheta %= (2*PI);
  goalTheta /= (2*PI);
  goalTheta *= 12;
  goalTheta = ceil(goalTheta);
  goalTheta /= 12;
  goalTheta *= (2*PI);
  goalXY = new XYPt(1000+400*cos(goalTheta+PI), 1000-730*sin(goalTheta+PI));
  if(goalXY != null){
    goalLocation = new LatLonPt(goalXY);
    guiGoalLat.setValue((float) goalLocation.getLat());
    guiGoalLon.setValue((float) goalLocation.getLon());
  }
  debugInfo = "Tracking test data ellipse.";
}
