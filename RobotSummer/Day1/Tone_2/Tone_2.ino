/*
  Tone_2
 
 This example plays siren like sound on a piezo connected to DP0,
 on the Svante robot.
 
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
  //Plays a tone for 1 millisecond for each iteration in the for loop. 
  //The frequency of the tone increases for each loop, starting off 
  //with 200 herz, and ending with 1000.
  for(int i=200; i<1000; i++){
    tone(speakerPin, i);
    delay(1);
  }
}

