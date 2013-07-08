#include <PID_v1.h>
#include <PWMServo.h> 
#include <TinyGPS.h>

int escVal;
int servoVal = 75;
double normEsc = 0.0;
double setpointSpeed = 3;
double currentSpeed = 0.0;
PWMServo esc;
PWMServo servo;
TinyGPS gps;
unsigned long gpsLockAge;


PID myPID(&currentSpeed, &normEsc, &setpointSpeed, 0.01, 0.01, 0.01, DIRECT);

void setup(){
  Serial3.begin(57600);
  Serial2.begin(115200);
  myPID.SetOutputLimits(0.0, 1.0);
 // myPID.SetSampleTime(10);
  myPID.SetMode(AUTOMATIC);
  esc.attach(SERVO_PIN_A);
  servo.attach(SERVO_PIN_B);
  
}

float floatMap(float x, float inMin, float inMax, float outMin, float outMax){
  return (x-inMin)*(outMax-outMin)/(inMax-inMin)+outMin;
}

void loop(){
  
  while(Serial3.available()){  //is there anything to read?
	char getData = Serial3.read();  //if yes, read it

	if(getData == '0'){  	 
  	   myPID.SetMode(MANUAL);
           escVal = 100;
	}else if(getData == 'w'){
  	  servoVal = 75;
	}else if(getData == 'a'){
  	   servoVal = 112;
	}else if(getData == 's'){
  	   myPID.SetMode(AUTOMATIC);
	}else if(getData == 'd'){
  	   servoVal = 37;
	}
  }
  
  if(myPID.Compute()){
    escVal = (int) floatMap(normEsc, 0.0, 1.0, 100, 25);
  //  Serial3.print("Computed:");
   // Serial3.print("\tnormEsc = ");
   // Serial3.print(normEsc);
    Serial3.print("escVal ");
    Serial3.print(escVal);
    Serial3.print("\tcurrentSpeed ");
    Serial3.println(currentSpeed);
   // Serial3.print("\tsetpointSpeed = ");
    //Serial3.println(setpointSpeed);

   
  }
  esc.write(escVal);
  servo.write(servoVal);
  
  currentSpeed = gps.speed() * 0.011;
  
  if(feedgps()){
    gpsdump(gps);
  }
}

void gpsdump(TinyGPS &gps){
 
  currentSpeed = gps.speed() * 0.011;
}

boolean feedgps(){
  while (Serial2.available()){
    if (gps.encode(Serial2.read())){
      return true;
    }
  }
  return false;
}
