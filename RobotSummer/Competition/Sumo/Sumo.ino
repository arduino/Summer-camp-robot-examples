/*
*  Robot sumo
*  Enlist your robot in the robot sumo fight! 
*  You'll need to attach a ultrasonic sensor to DP4, which is used for the right side of the robot,
*  another to DP8, which is used for the left side of the robot.
*  Gear up your robot with cardboard/plastic structures so it gains upper-hand. Make some research
*  and find out what're the best weaponaries people use in professional robot sumo.
*  There're also parameters you can customize to make your sumo robot work differently. Read the 
*  descriptions below to find out how they work
*  
*  This is an example from the Svante robot summer camp.
*  (c) 2014 Arduino LLC
*  
*/

#include <Svante.h>
#include <EEPROM.h>
 
 
int currentMode;//0:search, 1:track, 2:attack, 3:survive
 
int target=0;
int trackCount=0;
boolean tracked=false;
const int trackCountMax=10;
const int trackCountThreshold=5;

const int pingR=DP4;
const int pingL=DP8;

const int valSample_len=1;

//****************
//Customizable variables, read the description about how to tinker your sumo robot
const int detectionRange=30;  //the robot can see as far as x cm
const int searchSpeed=60;	//Speed when the robot is in search mode(rotating)
const int trackSpeed=50;	//Speed when the robot is in track mode(when the target is somewhat off)
const int attackSpeed=80;	//Speed when the robot is in attack mode(when the target is almost staright forward)
const int surviveSpeed=60;	//Speed when the robot is in survive mode(when it touches doujo ring and back off)
const float attackOffset=0.5;	//How big movements do the robot make when in attack mode
const float trackOffset=0.3;	//How big movements do the robot make when in track mode
//end of customizable variables
//****************

int edgeValue=200;	

int error;

void setup() 
{ 
  Serial.begin(9600);
  robot.begin();
  
  delay(5000);  //The robot starts 5 seconds after the match begins
  
  currentMode=0;
  searchMode();
} 
 
void loop() 
{ 
  scan();
  if(trackCount>trackCountThreshold)
    tracked=true;
  else
    tracked=false;
    
  //Serial.println(tracked);

  //Serial.println(currentMode);
  
  modeManager();
  delay(5);
}
void modeManager(){
  if(onEdge()){
    currentMode=3;
    surviveMode();
    return;
  }
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
  int distanceL=getValAvg(pingL);
  int distanceR=getValAvg(pingR);
  /*
  Serial.print(distanceL);
  Serial.print(" ");
  Serial.println(distanceR);
  */
  boolean trackedL=distanceL<detectionRange?true:false;
  boolean trackedR=distanceR<detectionRange?true:false;
  
  if(trackedL||trackedR){
    if(trackCount<trackCountMax) trackCount++;
  }else{
    if(trackCount>0) trackCount--;
  }
  
  target=90;
  if(trackedL)target-=90;
  if(trackedR)target+=90;
}
int getValAvg(int sensorPin){
  int sum=0;
  for(int i=0;i<valSample_len;i++){
    sum+=getDistance(sensorPin);
  }
  int valAvg=sum/valSample_len;
  return valAvg;
}
int getDistance(int sensorPin){
  pinMode(sensorPin,OUTPUT);
  digitalWrite(sensorPin,LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensorPin, LOW);
  
  pinMode(sensorPin, INPUT);
  int duration = pulseIn(sensorPin, HIGH, 11800);
  return getCMs(duration);
}
long getCMs(int ms){
  if(ms!=0){
    return ms/29/2;
  }else{
    return 1000;
  }
}

boolean onEdge(){
  for(int i=0;i<5;i++){
    if(robot.getIRArray(i)<edgeValue)
      return true;
  }
  return false;
}

void searchMode(){
  robot.go(searchSpeed,-searchSpeed);
}
void trackMode(){
  error=target-90;
  int res=error*trackOffset;
  if(res<0){
    res-=trackSpeed;
  }else if(res>0){
    res+=trackSpeed;
  }
  robot.go(res,-res);
}
void attackMode(){
  error=target-90;
  int res=error*attackOffset;
  
  robot.go(res+attackSpeed,attackSpeed-res);
}
void surviveMode(){
  robot.go(-surviveSpeed,-surviveSpeed);
  delay(500);
}
