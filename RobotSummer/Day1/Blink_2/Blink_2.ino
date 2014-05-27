/*
  Blink_2
 
 This example turns an LED connected to DP0 on the Svante 
 robot, on for one second, then off for another second.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h> //Include the Svante library
 
void setup() {                
  pinMode(DP0, OUTPUT); //Initialize digital pin DP0 as an output
 }
 
void loop() {
  digitalWrite(DP0, HIGH);   
  delay(1000);               
  digitalWrite(DP0, LOW);    
  delay(1000);               
}
