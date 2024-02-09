#include <Arduino.h>

String wait_for_message() {
    String msg;

    do {
        msg = Serial.readString();
    }

    while (msg.length() == 0);

    Serial.println("ACK");

    return msg;
}
