/*
  Blink_3
 
 This exampleis the same as Blink_2 but uses a variable to
 store the pin number DP0.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h>
#include <EEPROM.h>

int ledPin = DP0;
 
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
