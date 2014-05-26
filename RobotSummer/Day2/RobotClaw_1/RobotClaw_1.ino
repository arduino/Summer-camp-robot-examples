// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include <Svante.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoPin = 9;                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() { 
  closeClaw();
  delay(2000);
  openClaw();
  delay(2000);
} 

void closeClaw(){
  for(pos = 0; pos < 180; pos++){                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
}

void openClaw(){
  myservo.write(0);
}
