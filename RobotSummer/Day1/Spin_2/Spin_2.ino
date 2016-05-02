/*
  Spin_2
 
 This example makes the Svante robot go in a circle counterclockwise.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */
 
 #include <Svante.h>
 #include <EEPROM.h>
 
void setup(){
  robot.begin();
}
 
void loop(){
  robot.go(10,100);
}
