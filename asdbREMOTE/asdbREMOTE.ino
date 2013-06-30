#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <PS2Keyboard.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"

const int DataPin = 9;
const int IRQpin =  2;
PS2Keyboard keyboard;

//TinyGPS gps;
SoftwareSerial mySerial(11, 10);


float initialLat = 0;
float initialLon = 0;

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 3, 4);

char keyboardCharacter;
char keyboardCharacterLastState;
boolean backLight = true;
const int backLightPin = 8;

//void gpsdump(TinyGPS &gps);
//boolean feedgps();

//menu 1
boolean stopOverrides = 0;
boolean xbeeStop = 0;
boolean drivetrainEnabled = 0;
boolean steeringEnabled = 0;
boolean buttonStop = 0;
boolean leftBumper = 0;
boolean rightBumper= 0;

//menu 2
char waypointBehavior = 'r';
boolean adjustMySpeed = 0;
boolean automaticMode = 1;
float goalSpeed = 15.5;
float maxSpeed = 14.5;
float currentSpeed = 11.1;

//Menu3
float carLat = 12.3456;
float carLon = 12.3456;
float goalLat = 12.3456;
float goalLon = 12.3456;
float remoteLat = 12.3456;
float remoteLon = 12.3456;


//Menu 4
int escValue = 188;
int servoValue = 90;
int loopNumber = 10;
float driveBatteryVoltage = 7.20;
float rangefinderValue = 180.00;
float distanceToGoal = 20.00;

//Menu 5
boolean ubLights = 1;
boolean tailLights =1;
int music = 0;
float heading = 30.12;
float gyroYaw = 5.22;
boolean remoteGPSLock = 1;

void setup()   {
  Serial.begin(57600);

  display.begin();
  pinMode(backLightPin, OUTPUT);
  
  Serial.println("Up.");
  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(45);

  display.display(); // show splashscreen
  display.clearDisplay();   // clears the screen and buffer
  keyboard.begin(DataPin, IRQpin);
  
//  mySerial.begin(9600);
//  mySerial.println(PMTK_SET_NMEA_OUTPUT_RMCONLY);
//  mySerial.println(PMTK_SET_NMEA_UPDATE_10HZ);
}
void loop(){
  if (keyboard.available()) {
    keyboardCharacter = keyboard.read();
    keyboardCharacterLastState = keyboardCharacter;
  }else{
    keyboardCharacter = 0;
  }
 display.clearDisplay();
 if( keyboardCharacter == '1'){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print(spaces("Overrides:", stopOverrides));
  display.print(spaces("Xbee Stop:", xbeeStop));
  display.print(spaces("Drivetrain:", drivetrainEnabled));
  display.print(spaces("Steering:", steeringEnabled));
  display.print(spaces("BtnStop:", buttonStop));
  display.print("LB: ");
  display.print(leftBumper);
  display.print("   RB:  ");
  display.print(rightBumper);
  display.display();
  
  } 
 if( keyboardCharacter == '2'){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print(spaces("Auto Mode:", automaticMode));
  display.print(spaces("WayPt Beh:", waypointBehavior));
  display.print(spaces("Adj. Speed:", adjustMySpeed));
  display.print(spaces("GSpeed:", goalSpeed, 2));
  display.print(spaces("CSpeed:", currentSpeed, 2));
  display.print(spaces("MSpeed:", maxSpeed, 2));
  display.println(maxSpeed);
  display.display();
  
  }
 if( keyboardCharacter == '3'){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print(spaces("CLat:", carLat, 5));
  display.print(spaces("CLon:", carLon, 5));
  display.print(spaces("GLat:", goalLat, 5));
  display.print(spaces("GLon:", goalLon, 5));
  display.print(spaces("RLat:", remoteLat, 5));
  display.print(spaces("RLon:", remoteLon, 5));
  display.display();
  }

 if( keyboardCharacter == '4'){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print(spaces("ESC:",escValue));
  display.print(spaces("Servo:", servoValue));
  display.print(spaces("Rfinder:",rangefinderValue, 2));
  display.print(spaces("D.Bat:", driveBatteryVoltage, 2));
  display.print(spaces("LoopNum:", loopNumber));
  display.print(spaces("GoalDis:", distanceToGoal, 2));
  display.display();
  }
   if( keyboardCharacter == '5'){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print(spaces("Ub Lights:",ubLights));
  display.print(spaces("Tail Lights:", tailLights));
  display.print(spaces("Music:",music));
  display.print(spaces("Heading:", heading, 2));
  display.print(spaces("Yaw", gyroYaw, 2));
  display.print(spaces("R GPS Lock:", remoteGPSLock));
  display.display();
  }
  
    if(keyboardCharacter == '`'){
     backLight = !backLight;
    }
  
  digitalWrite(backLightPin, backLight);
  
  boolean newdata = false;
  unsigned long start = millis();
  // Every 5 seconds we print an update
/*  while (millis() - start < 100)
  {
    if (feedgps())
      newdata = true;
  }
  
  if (newdata)
  {
   // gpsdump(gps);
  }
  */
}

String spaces(String label, int value){
  String valueString = String(value);
  int numberOfSpaces = 14-label.length()-valueString.length();
  String spacesString = "";
  for(int i = 0; i < numberOfSpaces; i++){
    spacesString += " ";
  }
  return label + spacesString + valueString;
}

String spaces(String label, char value){
  String valueString = String(value);
  int numberOfSpaces = 14-label.length()-valueString.length();
  String spacesString = "";
  for(int i = 0; i < numberOfSpaces; i++){
    spacesString += " ";
  }
  return label + spacesString + valueString;
}

String spaces(String label, float value, int digits){
  String valueString = floatToString(value, digits);
  int numberOfSpaces = 14-label.length()-valueString.length();
  String spacesString = "";
  for(int i = 0; i < numberOfSpaces; i++){
    spacesString += " ";
 }
  return label + spacesString + valueString;
}

String floatToString(float number, int digits){
  String result = "";
  if (number < 0.0){
    result += '-';
    number = -number;
  }
  float rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i){
    rounding /= 10.0;
  }
  number += rounding;
  unsigned long int_part = (unsigned long)number;
  float remainder = number - (float)int_part;
  result += String(int_part);
  if (digits > 0){
    result += '.';
  }
  while (digits-- > 0){
    remainder *= 10.0;
    int toPrint = int(remainder);
    result += toPrint;
    remainder -= toPrint; 
  }
  return result;
}

/*void gpsdump(TinyGPS &gps)
{
  long lat, lon;
  float flat, flon;
  unsigned long age, date, time, chars, speed, course;
  float cardinalheading;
  //unsigned long age, time, date, speed, course;
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned short sentences, failed;
  unsigned long heading;
  double speedmph;
  feedgps(); // If we don't feed the gps during this long routine, we may drop characters and get checksum errors

  gps.f_get_position(&flat, &flon, &age);
  remoteLat = flat;
  remoteLon = flon;
  //float goal[] = {39.26450, -94.39680}; //end of the driveway at the gate
  //heading = gps.course();
 // heading = (heading/100);
 // cardinalheading = gps.course_to(myLat, myLon, goal[0], goal[1]);
  speed = gps.speed();
  speedmph = ((double) speed)* 0.011;

  if(initialLat==0){
    initialLat = flat;
  }
  if(initialLon==0){
    initialLon = flon;
  }
  
   feedgps();
}
   
 boolean feedgps()
{
  while (mySerial.available())
  {
    if (gps.encode(mySerial.read()))
      return true;
  }
  return false;
}*/
