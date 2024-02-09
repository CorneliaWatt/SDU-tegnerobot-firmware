#include "serial.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
}

void loop() {
  String msg = wait_for_message();
}
