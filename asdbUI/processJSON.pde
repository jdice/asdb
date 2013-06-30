void processJSONData(){
  try{
    JSONObject statusData = jsonData.optJSONObject("status");
      stopOverrides = statusData.optBoolean("stopOverrides", stopOverrides);
      steeringEnabled = statusData.optBoolean("steeringEnabled", steeringEnabled);
      xbeeStop = statusData.optBoolean("xbeeStop", xbeeStop);
      drivetrainEnabled = statusData.optBoolean("drivetrainEnabled", drivetrainEnabled);
      headlightEnabled = statusData.optBoolean("headlightEnabled", headlightEnabled);
      adjustMySpeed = statusData.optBoolean("adjustMySpeed", adjustMySpeed);
      gpsLock = statusData.optBoolean("gpsLock", gpsLock);
      loopNumber = statusData.optInt("loopNumber", loopNumber);
    JSONObject sensorsData = jsonData.optJSONObject("sensors");
      rangefinderValue = sensorsData.optDouble("rangefinder", rangefinderValue);
      leftBumper = sensorsData.optBoolean("leftBumper", leftBumper);
      rightBumper = sensorsData.optBoolean("rightBumper", rightBumper);
      driveBatteryVoltage = sensorsData.optDouble("driveBatteryVoltage", driveBatteryVoltage);
    JSONObject locationData = jsonData.optJSONObject("location");
      JSONObject currentLocationData = locationData.optJSONObject("current");
        currentLat = currentLocationData.optDouble("lat",currentLat);
        currentLon = currentLocationData.optDouble("lon",currentLon);
      JSONObject goalLocationData = locationData.optJSONObject("goal");
        goalLat = goalLocationData.optDouble("lat",goalLat);
        goalLon = goalLocationData.optDouble("lon",goalLon);
        distanceToGoal = goalLocationData.optDouble("distanceToGoal", distanceToGoal);
      JSONObject headingLocationData = locationData.optJSONObject("heading");
        currentHeading = headingLocationData.optDouble("current", currentHeading);
        goalHeading = headingLocationData.optDouble("goal", goalHeading);
        turnAngle = headingLocationData.optDouble("turnAngle", turnAngle);
        steeringAngle = headingLocationData.optInt("steeringAngle", steeringAngle);
      JSONObject speedLocationData = locationData.optJSONObject("speed");
        currentSpeed = speedLocationData.optDouble("current", currentSpeed);
        goalSpeed = speedLocationData.optDouble("goal", goalSpeed);
        maxSpeed = speedLocationData.optDouble("max", maxSpeed);
        adjustedSpeedValue = speedLocationData.optInt("adjustedSpeedValue", adjustedSpeedValue);
    JSONObject imuData = jsonData.optJSONObject("imu");
      imuYaw = imuData.optDouble("yaw", imuYaw);
      imuPitch = imuData.optDouble("pitch", imuPitch);
      imuRoll = imuData.optDouble("roll", imuRoll);
    debugInfo = jsonData.optString("debug","Failed to read data.");
    jsonError = false;
  }
  catch(Exception e){
    System.out.println("Encountered error. Will not process.");
    jsonError = true;
  }
  if(!jsonError){
    // Status Buttons
    guiDrivetrain.setValue(!xbeeStop);
    guiGPSLock.setValue(gpsLock);
    // Sensor Buttons
    guiLeftBumper.setValue(leftBumper);
    guiRightBumper.setValue(rightBumper);
    guiHeadlight.setValue(headlightEnabled);
    guiSteering.setValue(steeringEnabled);
    guiRangefinder.setValue((float) rangefinderValue);
    guiDriveBattery.setValue((float) driveBatteryVoltage);
    // Current Position
    currentLocation = new LatLonPt(currentLat, currentLon, defaultPointSize);
    currentXY = new XYPt(currentLocation);
    guiCurrentLat.setValue((float) currentLocation.getLat());
    guiCurrentLon.setValue((float) currentLocation.getLon());
    // Goal Position
    goalLocation = new LatLonPt(goalLat, goalLon, defaultPointSize);
    goalXY = new XYPt(goalLocation);
    guiGoalLat.setValue((float) goalLocation.getLat());
    guiGoalLon.setValue((float) goalLocation.getLon());
    guiDistanceToGoal.setValue((float) distanceToGoal);
    // Headings
    guiCurrentHeading.setStartAngle(radians((float)currentHeading-90));
    guiGoalHeading.setStartAngle(radians((float)goalHeading-90));
    guiServo.setValue(steeringAngle);
    
    // Speed
    guiCurrentSpeed.setValue((float) currentSpeed);
    guiGoalSpeed.setValue((float) goalSpeed);
    guiMaxSpeed.setValue((float) maxSpeed);
    guiESC.setValue(adjustedSpeedValue);
    // Debug Info
    guiLoopNumber.setValue(loopNumber);

  }
}
