/*
  RobotPuppy_2
 
 This example uses two ultrasonic sensors. The left one is connected to DP4 and
 the right one to A1 on the Svante robot. When the distance to an object for each
 sensor is calculated we can see if the object is in front, to the left or to the 
 right of the robot. This information is printed to the serial monitor.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

int trigR = A1;
int echoR = A1;
int trigL = DP8;
int echoL = DP8;

int threshold = 50; //threshold distance 

void setup(){  
  Serial.begin(9600);   //Initializes the serial communication
}

void loop(){
  int disR = getDistance(trigR, echoR); //Gets right distance
  int disL = getDistance(trigL, echoL); //Gets left distance
  
  //If the distance is less than the threshold on both sensors,
  //The object is in front of the robot
  if(disL<threshold && disR<threshold) Serial.println("In front!");  
  
  //If the distance is less than the threshold on the left sensor,
  //The object is to the left
  else if(disL<threshold) Serial.println("To the left!");
  
  //If the distance is less than the threshold on the right sensor,
  //The object is to the right
  else if(disR<threshold) Serial.println("To the right!");
  
  //If the sensor readings aren't less than the threshold, there's no object there
  else Serial.println("Nothing there!");

  delay(100);
}


int getDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH, 11800);
  int distance = constrain(duration/29/2, 0, 200);
  if(distance==0)distance=200;

  return distance;
}
