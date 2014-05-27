/*
  Spin_2
 
 This example makes the Svante robot go in a circle counterclockwise.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */
 
 #include <Svante.h>
 
void setup(){
  robot.begin();
}
 
void loop(){
  robot.go(10,100);
}
