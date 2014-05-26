#include <Svante.h>

int speakerPin = DP0;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for(int i=200; i<1000; i++){
    tone(speakerPin, i);
    delay(1);
  }
}
