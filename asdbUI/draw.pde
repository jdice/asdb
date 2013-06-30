void draw(){
  hint(ENABLE_DEPTH_TEST);
  
  if(jsonData != null){
    processJSONData();
  }else{
    if(doTestPointMove){
      testPointMove();
    }
  }
  
  cameraUpdate();
  controller();
  guiUpdate();
  clear();
  textFont(uiFont);
  pushMatrix();
  
    perspective(PI/3.0,(float)width/height,1/(cameraHeight*2),cameraHeight*2);
    camera(
      (float) cameraXY.getX(), // Camera X position
      (float) cameraXY.getY(), // Camera Y position
      cameraHeight, // Camera Z position
      (float) cameraXY.getX(), (float) cameraXY.getY(), 0, //looking at X,Y,Z
      0, 1, 0 // Screen-Up vector
    );
    updateMouseXY();
    image(mapImg,0,0);
    drawPoint(color(0,255,0),goalXY);
    drawPoint(color(255,255,0),currentXY);
    
    //drawPoint(color(0,0,255),viewXY);
    //drawPoint(color(0,255,255),cameraXY);
  popMatrix();
  camera(); // resets view
  hint(DISABLE_DEPTH_TEST); // Draw UI and "static" 2D elements after this line
  pushMatrix();
    if(debugInfo != null){
      text("Debug: " + debugInfo, textLineSize, height-(textLineSize*1));
    }else{
      text("Debug: ", textLineSize, height-(textLineSize*1));
    }
    translate(width-180,height-180,0);
    ortho();
    rotateY(HALF_PI);
    rotateX(-radians((float) currentHeading));
    rotateZ(-radians((float) imuPitch));
    rotateY(radians((float) imuRoll));
    cone(0,0,40,180);
  popMatrix();
}
