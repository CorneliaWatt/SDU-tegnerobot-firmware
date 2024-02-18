#include <Arduino.h>

String wait_for_message() {
    String msg1, msg2;
    while (true) {
        // Wait until serial data is available
        while(!Serial.available());

        msg1 = Serial.readStringUntil('\n');
        msg2 = Serial.readStringUntil('\n');

        if (msg1 == msg2) {
            Serial.println("ACK");
            return msg1;
        }
        else {
            Serial.println("msg1: " + msg1);
            Serial.println("msg2: " + msg1);
        }
    }
}
