
#include <Svante.h>

int trig = DP1;
int echo=DP0;
int piezo = DP12;

void setup(){  
  //Initialize the serial communication
  Serial.begin(9600); 
}

void loop(){
  int dis = getDistance(trig, echo);
  delay(100);

  if(dis<30){
    int pitch = map(dis, 0, 30, 200, 1000);
    tone(piezo, pitch);
    Serial.println(pitch);
  }
  else{ 
    noTone(piezo);
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
