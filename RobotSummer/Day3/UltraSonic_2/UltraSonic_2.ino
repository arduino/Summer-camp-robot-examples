/*
  UltraSonic_1
 
 This example reads the distance to an object with an ultrasonic sensor, and
 plays a tone on a piezo. The distance sets the pitch of the tone.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */

#include <Svante.h>
#include <EEPROM.h>

int trig = DP8;
int echo=DP8;
int piezo = DP12;

void setup(){  
}

void loop(){
  int dis = getDistance(trig, echo);
  delay(100);

  
  if(dis<30){                                //If the distance is less than 30 cm we play a sound
    int pitch = map(dis, 0, 30, 200, 1000);  //Maps the distance to a pitch between 200 and 1000 herz
    tone(piezo, pitch);                      //Plays the tone
  }
  else{ 
    noTone(piezo);                           //If distance is 30 cm or more, the piezo is quiet
  }
}


int getDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  pinMode(echo, INPUT);
  int duration = pulseIn(echoPin, HIGH, 11800);
  int distance = duration/29/2;

  return distance;
}

