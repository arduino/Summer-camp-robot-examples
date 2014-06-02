/*
  WiggleYourTail_1
 
 This example makes the Svante robot look like a happy puppy. 
 A servo, connected to DP4, with a cardboard tail is moved back 
 and forth to look like a tail.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h>
#include <EEPROM.h>
#include <Servo.h> 
 
Servo myservo;
int servoPin = DP4;             
    
void setup() { 
  myservo.attach(servoPin);
} 
 
 
void loop() { 
  myservo.write(45);
  delay(200);
  myservo.write(135);  
  delay(200);  
} 
