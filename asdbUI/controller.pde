void controller(){
  lx = leftStickX.getValue();
  ly = leftStickY.getValue();
  rx = rightStickX.getValue();
  ry = rightStickY.getValue();
  trigger = abs(topTriggers.getValue());
  
  guiLeftJoystick.setRangeValues(lx,lx);
  guiRightJoystick.setRangeValues(rx,rx);
  guiTrigger.setValue(trigger);
 
  if(buttonB.pressed()){
    guiReverseButton.setValue(true);
  }else{
    guiReverseButton.setValue(false);
  }
  if(buttonA.pressed()){
    guiStopButton.setValue(true);
  }else{
    guiStopButton.setValue(false);
  }
  if(buttonX.pressed()){
    if(!buttonXLastState){
      manualAutomatic = !manualAutomatic;
      guiManualAutomatic.setValue(manualAutomatic);
    }
  }
  buttonXLastState = buttonX.pressed();
}
