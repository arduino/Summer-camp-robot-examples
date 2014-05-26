#include <Svante.h>
 
int speakerPin = DP0;
 
void setup() {
  pinMode(speakerPin, OUTPUT);
}
 
void loop() {
  tone(speakerPin, 262);
}
