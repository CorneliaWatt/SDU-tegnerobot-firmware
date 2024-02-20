#include "serial.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  String msg = "1.123.456.781.123.456.78";
  Serial.println(msg);
  execute_path(msg);
  Serial.println("after");
}

void loop() {
  String msg = wait_for_message();
  Serial.println(msg);
  execute_path(msg);
}
