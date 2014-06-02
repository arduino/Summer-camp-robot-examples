/*
  Blink_1
 
 This example turns the onboard Svante robot LED on for
 one second, then off for another second.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

//Setup runs once when the program starts
void setup() {
  pinMode(17, OUTPUT); //Initialize the digital pin as an output
}

//Loop runs over and over and over ...
void loop() {
  digitalWrite(17, HIGH);  //Turn the LED on
  delay(1000);             //Wait 1000 milliseconds
  digitalWrite(17, LOW);   //Turn the LED off
  delay(1000);             //Wait 1000 milliseconds
}




