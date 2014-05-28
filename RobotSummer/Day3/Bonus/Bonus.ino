/*
  
*/
#include <Svante.h>

int ir_leds[] ={IR_1, IR_2, IR_3};
int delayTime = 100;

void setup() {              
  for(int i=0; i<3; i++)  pinMode(ir_leds[i], OUTPUT);    
}


void loop() {
  for(int i=0; i<3; i++){
    digitalWrite(ir_leds[i], HIGH);
    delay(delayTime);
  }
  for(int i=2; i>=0; i--){
    digitalWrite(ir_leds[i], LOW);
    delay(delayTime);
  }
  for(int i=2; i>=0; i--){
    digitalWrite(ir_leds[i], HIGH);
    delay(delayTime);
  }
  for(int i=0; i<3; i++){
    digitalWrite(ir_leds[i], LOW);
    delay(delayTime);
  }

}
