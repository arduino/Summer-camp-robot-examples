/*
  Servo_2
 
 This example makes a servo, connected to DP4 on the Svante robot, sweep 
 from one side to the other and then back.
 
 This example is based on the Sweep example included in the 
 Arduino IDE, modified for the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>
#include <Servo.h> 
 
Servo myservo;  
int servoPin = DP4;                
 
int pos = 0;    // variable to store the servo position 
 
void setup() { 
  myservo.attach(servoPin);  
} 
 
 
void loop() { 
  for(pos = 0; pos < 180; pos++){   // in steps of 1 degree 
    myservo.write(pos);             // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 5ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos--){    // in steps of 1 degree                             
    myservo.write(pos);             // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 5ms for the servo to reach the position 
  } 
} 
