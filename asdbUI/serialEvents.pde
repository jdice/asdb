void serialEvent(Serial p){
  inString = (myPort.readString());
  String[] stringList = split(inString, '~');
  theData = trim(stringList[0]);
  jsonData = new JSONObject(theData);
}

void keyPressed(){
  if(key != CODED){
    myPort.write(key);
  }
}
