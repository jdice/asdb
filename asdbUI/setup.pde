void setup(){
  frame.setBackground(new java.awt.Color(0,0,0));
  if(fullScreen){
    windowWidth = displayWidth;
    windowHeight = displayHeight;
  }else{
    windowWidth = 668;
    windowHeight = 690;
  }
  size(windowWidth, windowHeight, P3D);
  frameRate(60);
  uiFont = loadFont("uiFont.vlw");
  if(doSerial){
    String serialPort = "COM4"; //Serial.list()[0];
    myPort = new Serial(this, serialPort, 57600);
    println("Connecting serial " + serialPort);
    delay(100);
    myPort.clear();
    myPort.bufferUntil('~');
  }
  int mapImgSize = 2000;
  double mapCenterLat = 40.07155;
  double mapCenterLon = -105.22954;
  int zoomLevel = 20;
  String mapType = GoogleMapper.MAPTYPE_HYBRID;
  int mapWidth = mapImgSize;
  int mapHeight = mapImgSize;
  gMapper = new GoogleMapper(mapCenterLat,mapCenterLon,zoomLevel,mapType,mapWidth,mapHeight);
  LatLonPt.setMapper(gMapper);
  XYPt.setMapper(gMapper);
  mapImg = loadImage("data/map3.jpg");
  cameraHeight = (windowHeight/2.0) / tan(PI/6);
  
  guiSetup();
  
  controll = ControllIO.getInstance(this);
  device = controll.getDevice("XUSB Gamepad (Controller)");
  device.setTolerance(0.05f);
  
  buttonA = device.getButton(0);
  buttonB = device.getButton(1);
  buttonX = device.getButton(2);
  buttonXLastState = buttonX.pressed();
  buttonY = device.getButton(3);
  buttonLB = device.getButton(4);
  buttonRB= device.getButton(5);
  buttonStart = device.getButton(6);
  buttonBack = device.getButton(7);
  buttonLeftStick = device.getButton(8);
  buttonRightStick = device.getButton(9);
  
  cooliehat = device.getCoolieHat(10);
  cooliehat.setMultiplier(4);
  
  leftStickY = device.getSlider(0);
  leftStickX = device.getSlider(1);
  rightStickY = device.getSlider(2);
  rightStickX = device.getSlider(3);
  topTriggers = device.getSlider(4);
 
}
