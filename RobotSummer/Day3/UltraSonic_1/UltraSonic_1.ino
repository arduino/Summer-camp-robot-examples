/*
  UltraSonic_1
 
 This example reads the distance to an object with an ultrasonic sensor and
 prints it to the serial monitor. The ultrasonic sensor is connected to 
 DP8 on the Svante robot.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

int trig = DP8;
int echo = DP8;

void setup(){  
  Serial.begin(9600);  //Initializes the serial communication
}

void loop(){
  int dis = getDistance(trig, echo);   //Gets the distance in cm
  
  Serial.println(dis); //Prints the distance to the serial monitor
  delay(100);
}


//This function calculates and returns the distance in cm to the 
//closest object in front of the sensor.
int getDistance(int triggerPin, int echoPin){
  
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echo, INPUT);
  int duration = pulseIn(echoPin, HIGH, 11800);
  int distance = duration/29/2;
  
  return distance;
}
