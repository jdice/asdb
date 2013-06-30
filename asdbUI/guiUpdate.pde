void guiSetup(){
  // GUI setup
  cp5 = new ControlP5(this);
  
  guiCurrentLat = cp5.addNumberbox("Car Latitude")
    .setPosition(5, 5)
    .setSize(70,20)
    ;
  guiLatLon(guiCurrentLat);
    
  guiCurrentLon = cp5.addNumberbox("Car Longitude")
    .setPosition(75, 5)
    .setSize(70,20)
    ;
  guiLatLon(guiCurrentLon);
    
  guiGoalLat = cp5.addNumberbox("Goal Latitude")
    .setPosition(5, 41)
    .setSize(70,20)
    ;
  guiLatLon(guiGoalLat);
    
  guiGoalLon = cp5.addNumberbox("Goal Longitude")
    .setPosition(75, 41)
    .setSize(70,20)
    ;
  guiLatLon(guiGoalLon);
    
  guiMouseLat = cp5.addNumberbox("Mouse Latitude")
    .setPosition(5, 77)
    .setSize(70,20)
    ;
  guiLatLon(guiMouseLat);
    
  guiMouseLon = cp5.addNumberbox("Mouse Longitude")
    .setPosition(75, 77)
    .setSize(70,20)
    ;
  guiLatLon(guiMouseLon);
    
  guiDrivetrain = cp5.addToggle("Drivetrain")
    .setPosition(5, 115)
    .setSize(40,40)
    ;
  
  guiSteering = cp5.addToggle("Steering")
    .setPosition(55, 115)
    .setSize(40,40)
    ;
  
  guiHeadlight = cp5.addToggle("Headlight")
    .setPosition(105, 115)
    .setSize(40,40)
    ;
      
  guiGPSLock = cp5.addToggle("GPS Lock")
    .setPosition(5, 171)
    .setSize(40,40)
    .setValue(false)
    ;
  deactivateToggle(guiGPSLock);
  
  guiLeftBumper = cp5.addToggle("L Bumper")
    .setPosition(55, 171)
    .setSize(40,40)
    .setValue(false)
    ;
  deactivateToggle(guiLeftBumper);
  
  guiRightBumper = cp5.addToggle("R Bumper")
    .setPosition(105, 171)
    .setSize(40,40)
    .setValue(false)
    ;
  deactivateToggle(guiRightBumper);
    
  guiManualAutomatic = cp5.addToggle("Manual/Automatic")
    .setPosition(5, 228)
    .setSize(140,40)
    .setValue(false)
    .setMode(ControlP5.SWITCH)
    .setColorBackground(color(255, 0, 0))
    .setColorActive(color(255, 200, 0))
    .setLock(true)
    ;
      
  guiFollowMouse = cp5.addToggle("Follow Mouse")
    .setPosition(5, 285)
    .setSize(140,20)
    ;
      
  
  guiGoalSpeed = cp5.addSlider("Goal Speed")
    .setPosition(10,350)
    .setSize(10,200)
    .setRange(0,maxGoalSpeed)
    .setValue((float) goalSpeed)
    .setSliderMode(Slider.FLEXIBLE)
    ;
    
  guiCopyPosition = cp5.addButton("copyPosition")
    .setPosition(40, 350)
    .setValue(0)
    .setCaptionLabel("Copy Position")
    .setSize(105,20)
    ;
    

  guiCurrentHeading = cp5.addKnob("Heading")
    .setRange(0,1)
    .setValue(0.02)
    .setPosition(45,410)
    .setRadius(50)
    .setLock(true)
    .setTickMarkWeight(0)
    .setStartAngle(0)
    ;
    
  guiGoalHeading = cp5.addKnob("HeadingGoal")
    .setRange(0,1)
    .setValue(0.02)
    .setPosition(66,431)
    .setRadius(29)
    .setLock(true)
    .setTickMarkWeight(0)
    .setLabelVisible(false)
    .setColorBackground(color(1, 108, 158))
    .setColorForeground(color(2, 52, 77))
    .setStartAngle(0)
    ;

  guiWaypointBehavior = cp5.addDropdownList("Waypoint Behavior")
    .setPosition(5,340)
    .setSize(140,20)
    .setItemHeight(15)
    .setBarHeight(15)
    .setHeight(100)
    ;
  guiWaypointBehavior.captionLabel().set("Waypoint Behavior");
  guiWaypointBehavior.captionLabel().style().marginTop = 3;
  guiWaypointBehavior.captionLabel().style().marginLeft = 3;
  guiWaypointBehavior.valueLabel().style().marginTop = 3;
  guiWaypointBehavior.addItem("Stop", 0);
  guiWaypointBehavior.addItem("Loop", 1);
  guiWaypointBehavior.addItem("Reverse at End", 2);
  
  guiCurrentSpeed = cp5.addNumberbox("Current Speed")
    .setPosition(5, 570)
    .setSize(70,20)
    ;
    guiLatLon(guiCurrentSpeed);
    
   guiMaxSpeed = cp5.addNumberbox("Max Speed")
    .setPosition(75,570)
    .setSize(70,20)
    ;
    guiLatLon(guiMaxSpeed);
      
    guiDistanceToGoal = cp5.addNumberbox("Distance to Goal")
    .setPosition(5, 610)
    .setSize(140,20)
    ;
    guiLatLon(guiDistanceToGoal);
  
  guiDebugVisible = cp5.addToggle("Debug Visible")
    .setPosition(5, 650)
    .setSize(140,20)
    .setValue(false)
    ;
  
  guiESC = cp5.addNumberbox("ESC")
    .setPosition(180,5)
    .setSize(75,20)
    .setDecimalPrecision(0)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
    
  guiServo = cp5.addNumberbox("Servo")
    .setPosition(260, 5)
    .setSize(75,20)
    .setDecimalPrecision(0)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
    
  guiRangefinder = cp5.addNumberbox("Rangefinder")
    .setPosition(180, 41)
    .setSize(75,20)
    .setDecimalPrecision(2)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
    
  guiDriveBattery = cp5.addNumberbox("Drive Battery")
    .setPosition(260, 41)
    .setSize(75,20)
    .setDecimalPrecision(3)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
  
  guiLoopNumber = cp5.addNumberbox("Loop Number")
    .setPosition(180, 77)
    .setSize(75,20)
    .setDecimalPrecision(3)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
    
    guiTrigger = cp5.addSlider("Trigger")
    .setPosition(340,5)
    .setSize(10,92)
    .setRange(0,1)
    .setValue((float) trigger)
    .setLock(true)
    .setColorBackground(color(255, 0, 0))
    .setColorForeground(color(255, 200, 0))
    .setVisible(debugVisible)
    ;
    
    guiLeftJoystick = cp5.addRange("LeftX")
    .setBroadcast(false)
    .setPosition(375,5)
    .setSize(100,10)
    .setHandleSize(3)
    .setRange(-1,1)
    .setRangeValues(-.05,.05)
    .setLock(true)
    .setColorBackground(color(255, 0, 0))
    .setColorForeground(color(255, 200, 0))
    .setVisible(debugVisible)
    ;
      
    guiRightJoystick = cp5.addRange("RightX")
    .setBroadcast(false)
    .setPosition(375,20)
    .setSize(100,10)
    .setHandleSize(3)
    .setRange(-1,1)
    .setRangeValues(-.05,.05)
    .setLock(true)
    .setColorBackground(color(255, 0, 0))
    .setColorForeground(color(255, 200, 0))
    .setVisible(debugVisible)
    ;
    
    guiReverseButton = cp5.addToggle("Rev")
    .setPosition(375, 40)
    .setSize(20,20)
    .setValue(false)
    .setColorBackground(color(255, 0, 0))
    .setColorActive(color(255, 200, 0))
    .setLock(true)
    .setVisible(debugVisible)
    ;
    guiStopButton = cp5.addToggle("Stop")
    .setPosition(400, 40)
    .setSize(20,20)
    .setValue(false)
    .setColorBackground(color(255, 0, 0))
    .setColorActive(color(255, 200, 0))
    .setLock(true)
    .setVisible(debugVisible)
    ;
      
/*  guiImuHistoryStdev = cp5.addNumberbox("imuStdev")
    .setPosition(260, 77)
    .setSize(75,20)   
    .setDecimalPrecision(3)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
*/
/*  guiGpsHeadingHistoryStdev = cp5.addNumberbox("GpsHeadingHistoryStdev")
    .setPosition(260, 113)
    .setSize(75,20)
    .setDecimalPrecision(3)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    .setVisible(debugVisible)
    ;
*/
}

void guiUpdate(){
  debugVisible = guiDebugVisible.getState();
  guiESC.setVisible(debugVisible);
  guiServo.setVisible(debugVisible);
  guiRangefinder.setVisible(debugVisible);
  guiDriveBattery.setVisible(debugVisible);
  guiLoopNumber.setVisible(debugVisible);
  guiTrigger.setVisible(debugVisible);
  guiLeftJoystick.setVisible(debugVisible);
  guiRightJoystick.setVisible(debugVisible);
  guiReverseButton.setVisible(debugVisible);
  guiStopButton.setVisible(debugVisible);
  //guiImuHistoryStdev.setVisible(debugVisible);
  //guiGpsHeadingHistoryStdev.setVisible(debugVisible);
}

void guiLatLon(Numberbox theNumberbox){
  theNumberbox
    .setDecimalPrecision(5)
    .setValue(0)
    .setColorBackground(color(35))
    .setColorForeground(color(160))
    .setLock(true)
    ;
}

void deactivateToggle(Toggle theToggle){
  theToggle
    .setColorBackground(color(35))
    .setColorActive(color(200))
    .setLock(true)
    ;
}
