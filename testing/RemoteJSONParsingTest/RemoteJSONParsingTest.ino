/*
 Sample sketch to demonstrate Multi Level JSON parsing in Arduino
 
 This sketch parses the complexly nested JSON
 
 Libraries needed:

 - aJson library for JSON parsing - https://github.com/interactive-matter/aJson
 
 Circuit:

    You don't need any circuit, but need the Arduino board

 Author: 

    Sudar - <http://sudarmuthu.com> <http://hardwarefun.com>
    Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino

 License:

    BeerWare ;)
 
 */
#include <aJSON.h>

// function definitions - actually unnecessary
//char* parseJson(char *jsonString);

// Json string to parse
//char jsonString[] = "{\"status\":{\"stopOverrides\":true,\"drivetrainEnabled\":false,\"steeringEnabled\":true,\"waypointBehavior\":1,\"adjustMySpeed\":false,\"trackingGPS\":true,\"goalSpeed\":4},\"swag\":{\"ubLights\":true,\"tailLights\":false,\"music\":1},\"manual\":{\"dataSource\":1,\"manualAutomatic\":12.34567,\"normEsc\":1,\"normSteering\":1},\"gps\":{\"goalLat\":12.34567,\"goalLon\":12.34567,\"nextLat\":12.34567,\"nextLon:12.34567}}";
char jsonString[] = "{\"query\":{\"count\":1,\"created\":\"2012-08-04T14:46:03Z\",\"lang\":\"en-US\",\"results\":{\"item\":{\"title\":false}}}}";
const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(57600);
    Serial.println(jsonString);
    Serial.println("Starting to parse");

    boolean testthing = true;
    boolean value = parseJson(jsonString);
    Serial.println(value);

    Serial.print(F("Successfully parsed: "));
    Serial.println(value);
    if(value){
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }
    Serial.print("testthing:");
    Serial.println(testthing);
}

/**
 * Parse the JSON String. Uses aJson library
 * 
 * Refer to http://hardwarefun.com/tutorials/parsing-json-in-arduino
 */
/*int parseJson(char *jsonString){
  int value;

  aJsonObject* msg = aJson.parse(jsonString);
  Serial.print("msg = ");
  Serial.println(aJson.print(msg));
  if (msg != NULL) {
    Serial.println("msg!=null");
    aJsonObject* msgStatus = aJson.getObjectItem(msg, "status"); 
    if (msgStatus != NULL) {
      Serial.println("msgStatus!=null");
      aJsonObject* msgStatusStopOverrides = aJson.getObjectItem(msgStatus, "goalSpeed"); 
      if (msgStatusStopOverrides != NULL) {
        Serial.println("msgStatusStopOverrides!=null");
        value = msgStatusStopOverrides->valueint;
      }else{
        Serial.println("msgStatusStopOverrides == NULL");
      }
    }else{
      Serial.println("msgStatus == NULL");
    }
  }else{
    Serial.println("msg == NULL");
  }
  return value;
}*/
boolean parseJson(char *jsonString){
    
  aJsonObject* root = aJson.parse(jsonString);

    if (root != NULL) {
        //Serial.println("Parsed successfully 1 " );
        aJsonObject* query = aJson.getObjectItem(root, "query"); 
        Serial.println(aJson.print(query));

        if (query != NULL) {
            //Serial.println("Parsed successfully 2 " );
            aJsonObject* results = aJson.getObjectItem(query, "results"); 
            Serial.println(aJson.print(results));

            if (results != NULL) {
                //Serial.println("Parsed successfully 3 " );
                aJsonObject* item = aJson.getObjectItem(results, "item");
                Serial.println(aJson.print(item));

                if (item != NULL) {
                    //Serial.println("Parsed successfully 4 " );
                    aJsonObject* title = aJson.getObjectItem(item, "title"); 
                    
                    if (title != NULL) {
                        if(title->type == aJson_True){
                          Serial.println("aJson_True");
                        }else if(title->type == aJson_False){
                          Serial.println("aJson_False");
                        }else if(title->type == aJson_NULL){
                          Serial.println("aJson_NULL");
                        }else if(title->type == aJson_Int){
                          Serial.println("aJson_Int");
                        }else if(title->type == aJson_Float){
                          Serial.println("aJson_Float");
                        }else if(title->type == aJson_String){
                          Serial.println("aJson_String");
                        }else if(title->type == aJson_Array){
                          Serial.println("aJson_Array");
                        }else if(title->type == aJson_Object){
                          Serial.println("aJson_Object");
                        }else{
                          Serial.println("None");
                        } 
                        //Serial.println("Parsed successfully 5 " );
                        return title->valuebool;
                    }
                }
            }
        }
    }
}

void loop() {
   // Nothing to do
}
