void cameraUpdate(){
  viewXY = currentXY.lerp(goalXY, 0.5);
  cameraFollowMouse = guiFollowMouse.getState();
  if(cameraFollowMouse){
    viewXY = viewXY.lerp(mouseXY, 0.5);
  }
  double cameraMoveDistance = cameraXY.distanceTo(viewXY);
  double cameraViewDistance;
  if(cameraFollowMouse){
    cameraViewDistance = currentXY.distanceTo(goalXY)+currentXY.distanceTo(mouseXY);
  }else{
    cameraViewDistance = currentXY.distanceTo(goalXY);
  }
  double cameraMoveAngle = cameraXY.angleTo(viewXY);
  double cameraDelta = Math.min(Math.sqrt(cameraMoveDistance)/4.0,cameraMoveAmount);
  double cameraDeltaX = Math.cos(cameraMoveAngle)*cameraDelta;
  double cameraDeltaY = Math.sin(cameraMoveAngle)*cameraDelta;
  cameraXY.add(cameraDeltaX, cameraDeltaY);
  cameraHeight = lerp(cameraHeight, Math.max((float) cameraViewDistance, (windowHeight/2.0) / tan(PI/6)), 0.02);
}
