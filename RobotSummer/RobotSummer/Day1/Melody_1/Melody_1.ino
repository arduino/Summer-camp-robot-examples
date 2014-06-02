/*
  Melody_1
 
 This example plays a short melody on a piezo, connected to DP0
 on the Svante robot.
 
 This example is based on the toneMelody example included in the 
 Arduino IDE, modified for the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <Svante.h>
#include <EEPROM.h>
#include "pitches.h"

// notes in the melody: (0 is silence)
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 4};

//Amount of notes in the melody
int length=9;

int piezoPin=DP0;

void setup() {

}

void loop() {
  // iterate over the notes of the melody:
  for (int i = 0; i < length; i++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[i];
    tone(piezoPin, melody[i], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(piezoPin);
  }
}

