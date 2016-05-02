/*
  Servo_1
 
 This example makes a servo, connected to DP4 on the Svante robot, move to 180,
 90, and 0 degrees. 
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>
#include <Servo.h> //Include the servo library

Servo myservo;  // create servo object to control a servo 
int servoPin = DP4;  

void setup() { 
  myservo.attach(servoPin);  // attaches the servo on pin DP4 to the servo object 
} 


void loop() { 
  myservo.write(180);  // tell servo to go to position 180 degrees
  delay(1000);
  myservo.write(90);   // tell servo to go to position 90 degrees
  delay(1000);
  myservo.write(0);    // tell servo to go to position 0 degrees
  delay(1000);  
} 

