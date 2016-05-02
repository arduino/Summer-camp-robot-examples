/*
  Blink_4
 
 This example turns 2 LEDs connected to DP0 and DP1 on the 
 Svante robot, on for one second, then off for another second.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */
 
 #include <Svante.h>
 #include <EEPROM.h>
 
int ledPin = DP0;
int ledPin2 = DP1;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
void loop() {
  //Turn both LEDs on
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(1000);
 
  //Turn both LEDs off
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  delay(1000);
}
