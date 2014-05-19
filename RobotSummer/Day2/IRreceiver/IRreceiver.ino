#include <IRremote.h>
#include <IRremoteTools.h>

int RECV_PIN = 11;

void setup()
{
  Serial.begin(9600);
  beginIRremote(RECV_PIN); // Start the receiver
}

void loop() {
  if (IRrecived()) {
    Serial.print("Result: ");
    Serial.println(getIRresult(), HEX);
    Serial.println();
    resumeIRremote(); // Receive the next value
  }
}
