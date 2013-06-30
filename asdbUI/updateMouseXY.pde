void updateMouseXY(){
  mouseSceneX = (float) (cameraXY.getX() + (0.57735 * cameraHeight * width/height * (mouseX - 0.5*width) / (0.5*width) ) );
  mouseSceneY = (float) (cameraXY.getY() + (0.57735 * cameraHeight * (mouseY - 0.5*height) / (0.5*height) ) );
  mouseXY = new XYPt(mouseSceneX, mouseSceneY);
  mouseLocation = new LatLonPt(mouseXY);
  guiMouseLat.setValue((float) mouseLocation.getLat());
  guiMouseLon.setValue((float) mouseLocation.getLon());
}
