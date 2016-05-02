/*
  Go_1
 
 This example makes the Svante robot go forward for 1 second,
 stop 1 second, go backwards 1 second and finally stop another second.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

void setup(){
  robot.begin(); //Initializes the Svante library so we can control the wheels
}

void loop(){
  robot.go(100,100);     //Sets left and right wheel to top speed forward
  delay(1000);
  robot.stop();          //Stops both wheels
  delay(1000);
  robot.go(-100,-100);  //Sets left and right wheel to top speed backwards
  delay(1000);
  robot.stop();         //Stops both wheels
  delay(1000);
}

