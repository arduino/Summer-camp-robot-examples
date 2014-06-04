/*
*  RobotParty_1
* 
*  This is a party robot demonstrating how you can add
*  personality into the Svante robot.
*  It moves around for a while in quick bursts, play a 
*  melody, and blink the leds a few times. Such a happy
*  robot!
*  Use this as a start point for building your own robot
*  with emotion. Modify the parameters, add/remove/rearrange
*  blocks so the robot works in the way you prefer.
* 
*  This is an example from the Svante robot summer camp.
*  zgz.verkstad.cc 
*  (c) 2014 Arduino Verkstad
*/

#include <Svante.h>
#include <EEPROM.h>
#include "pitches.h"

//pins for the leds
int ledPin = DP0;
int ledPin2 = DP1;

// notes in the melody: (0 is silence)
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 4};

//Amount of notes in the melody
int length=9;

int piezoPin=DP2;


void setup(){
  robot.begin();
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin2,OUTPUT);
}
void loop(){
  //Move the robot
  robot.go(100,100);
  delay(300);
  robot.stop();
  delay(300);
  
  robot.go(50,-50);
  delay(300);
  robot.stop();
  delay(300);
  
  robot.go(100,100);
  delay(300);
  robot.stop();
  delay(300);

  robot.go(-100,-100);
  delay(300);
  robot.stop();
  delay(300);

  //playMelody with a function
  playMelody();
  
  //blink the leds, try to rewrite with loops!
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(100);

  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(100);

  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(100);

  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(100);

  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(100);

  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(100);
  
  //Turn off the leds
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);

  delay(1500);

}

void playMelody(){
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
