#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

#include <Servo.h> 
 
Servo myServo;  // create servo object to control a servo 
 
int currentMode;//0:search, 1:track 
 
int servoPos=0;
int target=0;
int trackCount=0;
boolean tracked=false;
const int trackCountMax=30;
const int trackCountThreshold=5;
const int servoPosMin=30;
const int servoPosMax=150;

const int valSample_len=5;
const int detectionRange=30;

int error;

void setup() 
{ 
  Serial.begin(9600);
  Robot.begin();
  myServo.attach(D1);  // attaches the servo on pin 9 to the servo object 
  currentMode=0;
  searchMode();
} 
 
void loop() 
{ 
  scan();
  if(trackCount>trackCountThreshold)
    tracked=true;
    
  Serial.println(tracked);
  modeManager();
  delay(5);
}
void modeManager(){
  if(!tracked){
    if(currentMode!=0){
      currentMode=0;
      searchMode();
    }
  }else{
    if(abs(error)<30){
      currentMode=2;
      attackMode();
      
    }else{
      currentMode=1;
      trackMode();
    }
  }
  
}
void scan(){
  int distance=getValAvg();
  //Serial.println(distance);
  target=servoPos;
  if(distance<detectionRange){
    //detected
    //target=servoPos;
//    Serial.println("found");
    //tracked=true;
    if(trackCount<trackCountMax)
      trackCount+=1;
    if(servoPos>servoPosMin){
      servoPos--;
      myServo.write(servoPos);
    }
    
    
  }else{
    //not detected
    //target=90;
    if(trackCount>0)
      trackCount--;
      
    if(servoPos<servoPosMax){
      servoPos++;
      myServo.write(servoPos);

    }else{
      tracked=false;
      servoPos=servoPosMin;
      myServo.write(servoPos);

      delay(20);
    }
  }
}
int getValAvg(){
  int sum=0;
  for(int i=0;i<valSample_len;i++){
    sum+=getDistance();
  }
  int valAvg=sum/valSample_len;
  return valAvg;
}
int getDistance(){
  int val=abs((6762/(Robot.analogRead(M0)-9))-4);
  return val;
}

void searchMode(){
  Robot.motorsWrite(60,-60);
}

void trackMode(){
  error=target-90;
  //Serial.println(error);
  int res=error*0.3;
  if(res<0){
    res-=50;
  }else if(res>0){
    res+=50;
  }
  //if(res==0){
  //  Robot.motorsStop();
  //}else{
  Robot.motorsWrite(res,-res);
  //}
  //Robot.motorsWrite(res+80,80-res);
  
}
void attackMode(){
  error=target-90;
  //Serial.println(error);
  int res=error*0.5;
  
  Robot.motorsWrite(res+80,80-res);
}
