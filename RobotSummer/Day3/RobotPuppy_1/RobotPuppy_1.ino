/*
  RobotPuppy_1
 
 This example uses two ultrasonic sensors. The left one is connected to DP4 and
 the right one to A1 on the Svante robot. The distance to the closest object to
 each sensor is calculated and printed to the serial monitor.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

int trigR = A1;
int echoR = A1;
int trigL = DP8;
int echoL = DP8;

void setup(){  
  Serial.begin(9600);   //Initializes the serial communication 
}

void loop(){
  int disR = getDistance(trigR, echoR); //Gets the distance in cm for the right sensor
  int disL = getDistance(trigL, echoL); //Gets the distance in cm for the left sensor

  Serial.print("Left distance: ");
  Serial.print(disL);                   //Prints left distance to the serial monitor
  Serial.print("  Right distance: ");
  Serial.println(disR);                 //Prints right distance to the serial monitor
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

