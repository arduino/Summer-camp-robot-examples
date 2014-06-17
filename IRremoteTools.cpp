#include "IRremote.h"
#include "IRremoteTools.h"
#include <Arduino.h>

IRrecv irrecv=IRrecv();
decode_results results; // container for received IR codes

void beginIRremote(int recvpin){
	irrecv.setRecvPin(recvpin);
	irrecv.enableIRIn(); // Start the receiver
}

bool IRreceived(){
	return irrecv.decode(&results);
}

void resumeIRremote(){
    irrecv.resume(); // resume receiver
}

unsigned long getIRresult(){
	return results.value;
}

