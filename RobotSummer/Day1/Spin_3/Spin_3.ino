#include <Svante.h>

void setup(){
  robot.begin();
}

void loop(){
  for(int i=0; i<50; i+=5){
      robot.go(i,50-i);
      delay(100);
  }
  for(int i=0; i<50; i+=5){
    robot.go(50-i,i);
    delay(100);
  }
}
