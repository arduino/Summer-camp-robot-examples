/*
  Tone_1
 
 This example plays a tone with a frequency of 262 herz, on
 a piezo connected to DP0 on the Svante robot.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */
 
#include <Svante.h>

int speakerPin = DP0;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  tone(speakerPin, 262); //Plays a tone with a frequency of 262 herz
}

