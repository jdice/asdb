aJsonObject *createMessage(){
  aJsonObject *msg, *myStatus, *mySensors, *myLocation, *myLocationCurrent, *myLocationGoal, *myLocationHeading, *myLocationSpeed, *myIMU;
  msg = aJson.createObject();

  aJson.addItemToObject(msg, "status", myStatus = aJson.createObject());
    aJson.addBoolToObject(myStatus, "stopOverrides", stopOverrides);
    aJson.addBoolToObject(myStatus, "steeringEnabled", steeringEnabled);
    aJson.addBoolToObject(myStatus, "xbeeStop", xbeeStop);
    aJson.addBoolToObject(myStatus, "drivetrainEnabled", drivetrainEnabled);
    aJson.addBoolToObject(myStatus, "headlightEnabled", headlightEnabled);
    aJson.addBoolToObject(myStatus, "adjustMySpeed", adjustMySpeed);
    aJson.addBoolToObject(myStatus, "buttonStop", buttonStop);
    aJson.addBoolToObject(myStatus, "gpsLock", gpsLock);
    aJson.addNumberToObject(myStatus, "loopNumber", loopNumber);
    
  aJson.addItemToObject(msg, "sensors", mySensors = aJson.createObject());
    aJson.addNumberToObject(mySensors, "rangefinder", rangefinderValue);
    aJson.addBoolToObject(mySensors, "leftBumper", leftBumper);
    aJson.addBoolToObject(mySensors, "rightBumper", rightBumper);
    aJson.addNumberToObject(mySensors, "driveBatteryVoltage", driveBatteryVoltage);
    
  aJson.addItemToObject(msg, "location", myLocation = aJson.createObject());
  
    aJson.addItemToObject(myLocation, "current", myLocationCurrent = aJson.createObject());
      aJson.addNumberToObject(myLocationCurrent, "lat", currentLat);
      aJson.addNumberToObject(myLocationCurrent, "lon", currentLon);
    aJson.addItemToObject(myLocation, "current", myLocationGoal = aJson.createObject());
      aJson.addNumberToObject(myLocationGoal, "lat", goalLat);
      aJson.addNumberToObject(myLocationGoal, "lon", goalLon);
      aJson.addNumberToObject(myLocationGoal, "distanceToGoal", distanceToGoal);
    aJson.addItemToObject(myLocation, "current", myLocationHeading = aJson.createObject());
      aJson.addNumberToObject(myLocationHeading, "current", currentHeading);
      aJson.addNumberToObject(myLocationHeading, "goal", goalHeading);
      aJson.addNumberToObject(myLocationHeading, "adjustedGoal", adjustedGoalHeading);
      aJson.addNumberToObject(myLocationHeading, "turnAngle", turnAngle);
      aJson.addNumberToObject(myLocationHeading, "steeringAngle", steeringAngle);
    aJson.addItemToObject(myLocation, "current", myLocationSpeed = aJson.createObject());
      aJson.addNumberToObject(myLocationSpeed, "current", currentSpeed);
      aJson.addNumberToObject(myLocationSpeed, "goal", goalSpeed);
      aJson.addNumberToObject(myLocationSpeed, "max", maxSpeed);
      aJson.addNumberToObject(myLocationSpeed, "adjustedSpeedValue", adjustedSpeedValue);

  aJson.addItemToObject(msg, "location", myIMU = aJson.createObject());
    aJson.addNumberToObject(myIMU, "yaw", imuEulerAngles[0]);
    aJson.addNumberToObject(myIMU, "pitch", imuEulerAngles[1]);
    aJson.addNumberToObject(myIMU, "roll", imuEulerAngles[2]);
    //aJson.addNumberToObject(myIMU, "accX", imuAccX);
    //aJson.addNumberToObject(myIMU, "accY", imuAccY);
    //aJson.addNumberToObject(myIMU, "accZ", imuAccZ);
  aJson.addStringToObject(msg, "debug", debugInfo);
  
  return msg;
}
