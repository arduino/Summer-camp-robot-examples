
/*
  RobotPuppy_4
 
 This example uses two ultrasonic sensors to check wether an object is in front, 
 to the left, or the right of the robot. The left sensor is connected to DP4 and
 the right one to A1 on the Svante robot. When we know where the object is the 
 robot wheels are controlled to move towards the object.
 
 A servo connected to DP4 acts as the robot puppys tail, and moves back and forth
 when an object is too close. 
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h>
#include <EEPROM.h>
#include <Servo.h>


int trigR = A1;
int echoR = A1;
int trigL = DP8;
int echoL = DP8;

int threshold = 40;
int stopThreshold = 10;

Servo tail;
int servoPin = DP4;

int robotSpeed = 50;

void setup(){  
  Serial.begin(9600);    //Initializes the serial communication
  robot.begin();         //Initializes the Svante library
}

void loop(){
  int disR = getDistance(trigR, echoR);
  int disL = getDistance(trigL, echoL);
  
  if(disL<stopThreshold || disR<stopThreshold) {
    Serial.println("Too close!");
    robot.stop();                        //If the robot gets too close to something, stop the robot
    wiggleTail();                        //And wiggle the tail
  }
  else if(disL<threshold && disR<threshold){  
    Serial.println("In front!");
    robot.go(robotSpeed, robotSpeed);  //If object is in front, make the robot go forward
  }
  else if(disL<threshold){
    Serial.println("To the left!");
    robot.go(0, robotSpeed);           //If object is to the left, make the robot turn left
  }
  else if(disR<threshold) {
    Serial.println("To the right!");
    robot.go(robotSpeed, 0);          //If object is to the right, make the robot turn lefrightt  
  }
  else {
    Serial.println("Nothing there!");
    robot.stop();                     //If there's nothing there, stop the robot
  }
}

//Switch the servo position quickly between 45 and 135 degrees
void wiggleTail(){
    tail.attach(servoPin);
    tail.write(45);
    delay(100);
    tail.write(135);
    delay(100);
    tail.detach();
    stopServo();
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
