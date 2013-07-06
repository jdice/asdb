/*
Sample sketch to demonstrate Multi Level JSON parsing in Arduino 
This sketch parses the complexly nested JSON
Libraries needed:
  aJson library for JSON parsing - https://github.com/interactive-matter/aJson
Circuit:
  You don't need any circuit, just an Arduino board
Authors: 
  Sudar - <http://sudarmuthu.com> <http://hardwarefun.com>
  Team asdb
Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino
*/

#include <aJSON.h>

// function definitions

// {"dataSource":1,"status":{"stopOverrides":true,"drivetrainEnabled":false,"steeringEnabled":true,"waypointBehavior":"s","adjustMySpeed":false,"trackingGPS":true,"goalSpeed":4.00},"swag":{"ubLights":true,"tailLights":false,"musicId":1},"manual":{"manualAutomatic":12.34567,"normEsc":0.00,"normSteering":0.00},"gps":{"remoteLat":12.34567,"remoteLon":12.34567}}

// Json string to parse
//char jsonString[] = "{\"dataSource\":1,\"status\":{\"stopOverrides\":true,\"drivetrainEnabled\":false,\"steeringEnabled\":true,\"waypointBehavior\":\"1\",\"adjustMySpeed\":false,\"trackingGPS\":true,\"goalSpeed\":4.00},\"swag\":{\"ubLights\":true,\"tailLights\":false,\"musicId\":1},\"manual\":{\"manualAutomatic\":12.34567,\"normEsc\":0.00,\"normSteering\":0.00},\"gps\":{\"remoteLat\":12.34567,\"remoteLon\":12.34567}}";
//char jsonString[] = "{\"dataSource\":2,\"status\":{\"stopOverrides\":true,\"drivetrainEnabled\":false,\"steeringEnabled\":true,\"waypointBehavior\":\"s\",\"adjustMySpeed\":false,\"trackingGPS\":true,\"goalSpeed\":4.00},\"swag\":{\"ubLights\":true,\"tailLights\":false,\"musicId\":1},\"manual\":{\"manualMode\":false,\"normEsc\":0.00,\"normSteering\":0.00}}";
//char jsonString[] = "{\"dataSource\":2,\"status\":{\"stopOverrides\":true,\"drivetrainEnabled\":false,\"steeringEnabled\":true},\"query\":{\"count\":1,\"created\":\"2012-08-04T14:46:03Z\",\"lang\":\"en-US\",\"results\":{\"item\":{\"title\":false}}}}";

const int ledPin = 13;

// main message variables
  int dataSource;

// status variables
  bool stopOverrides, drivetrainEnabled, steeringEnabled, adjustMySpeed, trackingGPS;
  char waypointBehavior = 'l';
  float goalSpeed;
  
// swag variables
  bool ubLights, tailLights;
  int musicId;
  
// manual variables
  bool manualMode;
  float normEsc, normSteering;

// gps variables
  float remoteLat, remoteLon; 

aJsonStream serial_stream(&Serial);

void setup(){
    Serial.begin(57600);
    Serial.println("Ready.");
    //Serial.print("JSON: ");
    //Serial.println(jsonString);
}

/**
 * Parse the JSON String. Uses aJson library
 * 
 * Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino
 */

void processMessage(aJsonObject* myMessage){
  Serial.println("Starting to parse");
  
  if(myMessage != NULL){
    printNameAndTypeFromJSON(myMessage, "myMessage");
    updateIntFromJSON(&dataSource, myMessage, "dataSource");
    
    aJsonObject* myStatus = aJson.getObjectItem(myMessage, "status");
    if(myStatus != NULL){
      printNameAndTypeFromJSON(myStatus, "myStatus");
      updateBoolFromJSON(&stopOverrides, myStatus, "stopOverrides");
      updateBoolFromJSON(&drivetrainEnabled, myStatus, "drivetrainEnabled");
      updateBoolFromJSON(&steeringEnabled, myStatus, "steeringEnabled");
      updateCharFromJSON(&waypointBehavior, myStatus, "waypointBehavior");
      updateBoolFromJSON(&adjustMySpeed, myStatus, "adjustMySpeed");
      updateBoolFromJSON(&trackingGPS, myStatus, "trackingGPS");
      updateFloatFromJSON(&goalSpeed, myStatus, "goalSpeed");
    }
    
    aJsonObject* mySwag = aJson.getObjectItem(myMessage, "swag");
    if(mySwag != NULL){
      printNameAndTypeFromJSON(mySwag, "mySwag");
      updateBoolFromJSON(&ubLights, mySwag, "ubLights");
      updateBoolFromJSON(&tailLights, mySwag, "tailLights");
      updateIntFromJSON(&musicId, mySwag, "musicId");
    }
    
    aJsonObject* myManual = aJson.getObjectItem(myMessage, "manual");
    if(myManual != NULL){
      printNameAndTypeFromJSON(myManual, "myManual");
      updateBoolFromJSON(&manualMode, myManual, "manualMode");
      updateFloatFromJSON(&normEsc, myManual, "normEsc");
      updateFloatFromJSON(&normSteering, myManual, "normSteering");
    }
    
    aJsonObject* myGPS = aJson.getObjectItem(myMessage, "gps");
    if(myGPS != NULL){
      printNameAndTypeFromJSON(myGPS, "myGPS");
      updateFloatFromJSON(&remoteLat, myGPS, "remoteLat");
      updateFloatFromJSON(&remoteLon, myGPS, "remoteLon");
    }
    
    Serial.println("Successfully parsed.");
  }else{
    Serial.println("Parse failed.");
  }
}

void updateIntFromJSON(int* value, aJsonObject* myJsonObject, char* fieldName){
  aJsonObject* query = aJson.getObjectItem(myJsonObject, fieldName);
  printNameAndTypeFromJSON(query, fieldName);
  *value = query->valueint;
}

void updateFloatFromJSON(float* value, aJsonObject* myJsonObject, char* fieldName){
  aJsonObject* query = aJson.getObjectItem(myJsonObject, fieldName);
  printNameAndTypeFromJSON(query, fieldName);
  *value = query->valuefloat;
}

void updateCharFromJSON(char* value, aJsonObject* myJsonObject, char* fieldName){
  aJsonObject* query = aJson.getObjectItem(myJsonObject, fieldName);
  printNameAndTypeFromJSON(query, fieldName);
  // char pointers are funky, because they're usually treated as strings.
  // Here, the function should actually update one char. Hence, the dereferencing operator *. Willing to accept better solutions.
  *value = *(query->valuestring);
}

void updateBoolFromJSON(bool* value, aJsonObject* myJsonObject, char* fieldName){
  aJsonObject* query = aJson.getObjectItem(myJsonObject, fieldName);
  printNameAndTypeFromJSON(query, fieldName);
  *value = query->valuebool;
}

void printNameAndTypeFromJSON(aJsonObject *query, char* fieldName){
  if (query != NULL) {
    Serial.print(fieldName);
    Serial.print(": ");
    if(query->type == aJson_True){
      Serial.println("aJson_True");
    }else if(query->type == aJson_False){
      Serial.println("aJson_False");
    }else if(query->type == aJson_NULL){
      Serial.println("aJson_NULL");
    }else if(query->type == aJson_Int){
      Serial.println("aJson_Int");
    }else if(query->type == aJson_Float){
      Serial.println("aJson_Float");
    }else if(query->type == aJson_String){
      Serial.println("aJson_String");
    }else if(query->type == aJson_Array){
      Serial.println("aJson_Array");
    }else if(query->type == aJson_Object){
      Serial.println("aJson_Object");
    }else{
      Serial.println("No applicable type found!");
    }
  }
}

void loop() {
  if (serial_stream.available()){
    aJsonObject* msg = aJson.parse(&serial_stream);
    processMessage(msg);
    aJson.deleteItem(msg);
    Serial.print("Data source: ");
    Serial.println(dataSource);
    Serial.print("Waypoint Behavior: ");
    Serial.println(waypointBehavior);
    Serial.print("Remote Lat: ");
    Serial.println(remoteLat);
  }
}
