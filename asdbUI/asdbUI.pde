import processing.serial.*;
import org.json.*;
import org.json.JSONObject;
import java.util.*;
import googlemapper.*;
import java.lang.Math;
import controlP5.*;
import procontroll.*;
import java.io.*;

// Application Settings
boolean fullScreen = false;
boolean doSerial = false;
boolean debugVisible = false;
boolean doTestPointMove = false;
float defaultPointSize = 5.0;

// Clipboard Setup 
ClipHelper clippy = new ClipHelper();

// Make a Queue for history location data
String inString;
String theData;
JSONObject jsonData;
String debugInfo;
Serial myPort;  // Create object from Serial class

// location data for drawing
XYPt initialXY = new XYPt(1000, 1000, defaultPointSize);
XYPt currentXY = new XYPt(600, 700, defaultPointSize);
XYPt goalXY = new XYPt(600, 1300, defaultPointSize);
XYPt viewXY = initialXY;
XYPt cameraXY = initialXY;
XYPt mouseXY = initialXY;
float mouseSceneX, mouseSceneY;
LatLonPt currentLocation, goalLocation, mouseLocation;

// Camera Setup
boolean cameraFollowMouse = false;
float cameraHeight;
double cameraMoveAmount = 100.0; // suit to taste
PImage mapImg;
GoogleMapper gMapper;
PFont uiFont;
int textLineSize = 26;
int windowWidth, windowHeight;
int maxGoalSpeed = 15;

// controlP5 objects
ControlP5 cp5;
float testTheta = 0;
Numberbox guiCurrentLat, guiCurrentLon, guiGoalLat, guiGoalLon, guiMouseLat, guiMouseLon, guiServo, guiESC, guiRangefinder, guiDriveBattery, guiLoopNumber, guiCurrentSpeed, guiMaxSpeed, guiDistanceToGoal;
Toggle guiDrivetrain, guiSteering, guiHeadlight, guiGPSLock, guiFollowMouse, guiLeftBumper, guiRightBumper, guiManualAutomatic, guiDebugVisible, guiReverseButton, guiStopButton;
Button guiCopyPosition;
DropdownList guiWaypointBehavior;
Knob guiCurrentHeading, guiGoalHeading;
Slider guiGoalSpeed, guiTrigger;
Range guiLeftJoystick, guiRightJoystick;

// data from car
boolean stopOverrides = false, steeringEnabled = false, xbeeStop = true, drivetrainEnabled = false, headlightEnabled = false, adjustMySpeed = false, gpsLock = false; // myStatus
int loopNumber = 0; //myStatus
double rangefinderValue = 0, driveBatteryVoltage = 0; //mySensors
boolean leftBumper = false, rightBumper = false; //mySensors
double currentLat = 39.24745, currentLon = -94.40990, goalLat = 39.24745, goalLon = -94.40990, distanceToGoal = 0; //myLocation
double currentHeading = 0, goalHeading = 0, turnAngle = 0, currentSpeed = 0, goalSpeed = 0, maxSpeed = 0; //mySpeed
int steeringAngle = 0, adjustedSpeedValue = 0; // steering and esc values
double imuYaw = 0, imuPitch = 0, imuRoll = 0; //myImu

boolean jsonError = true;

//Controller Setup
ControllIO controll;
ControllDevice device;
ControllButton buttonA;
ControllButton buttonB;
ControllButton buttonX;
ControllButton buttonY;
ControllButton buttonLB;
ControllButton buttonRB;
ControllButton buttonBack;
ControllButton buttonStart;
ControllButton buttonLeftStick;
ControllButton buttonRightStick;
ControllCoolieHat cooliehat;
ControllSlider leftStickX;
ControllSlider leftStickY;
ControllSlider rightStickX;
ControllSlider rightStickY;
ControllSlider topTriggers;

float lx;
float ly;
float rx;
float ry;
float trigger;
boolean manualAutomatic;
boolean buttonXLastState;

boolean sketchFullScreen() {
  return fullScreen;
}

public void copyPosition(int buttonValue){
  clippy.copyString(currentLocation.toString() + ", 3.0,\r\n");
}
