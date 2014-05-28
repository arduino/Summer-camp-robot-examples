/*
  Spin_3
 
 This example makes the Svante robot go forward in a wobbly way.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */
 
 #include <Svante.h>

void setup(){
  robot.begin();
}

void loop(){
  //Left wheel goes from speed 0 to 50, 
  //right wheel from 50 to 0
  for(int i=0; i<50; i+=5){
      robot.go(i,50-i);
      delay(100);
  }
  
  //Left wheel goes from speed 50 to 0, 
  //right wheel from 0 to 50
  for(int i=0; i<50; i+=5){
    robot.go(50-i,i);
    delay(100);
  }
}
