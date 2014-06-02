/*
  RobotClaw_1
 
 This example uses a servo connected to DP4 on the Svante robot, 
 to open and close a claw.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h>
#include <Servo.h> 
#include <EEPROM.h>

Servo claw;
int servoPin = DP4;             
    
void setup() { 
  claw.attach(servoPin);
} 
 
 
void loop() { 
  claw.write(50);
  delay(2000);
  claw.write(180);  
  delay(2000);  
} 
