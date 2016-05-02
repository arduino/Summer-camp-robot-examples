/*
  Spin_1
 
 This example makes the Svante robot spin counterclockwise for 1 second,
 stop 1 second, spin clockwise 1 second and finally stopfor another second.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

void setup(){
  robot.begin();
}

void loop(){
  
  //Sets left wheel to top speed backwards, right wheel to top speed forward
  //Makes the robot spin counterclockwise
  robot.go(-100,100); 
  delay(1000);
  robot.stop(); //Stops both wheels
  delay(1000);
  
  //Sets left wheel to top speed forward, right wheel to top speed backwards
  //Makes the robot spin clockwise  
  robot.go(100,-100);
  delay(1000);
  robot.stop(); //Stops both wheels
  delay(1000);
}

