#include <Arduino.h>

struct Vector {
    double x, y, z;
};

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
            Serial.println("Error: Messages do not match.");
            return "";
        }
    }
}

#define FLOAT_LEN 4

void execute_path(String path) {
    Serial.println("execute_path: " + path);
    for (int i = 0; i < path.length(); i += FLOAT_LEN*3) {
        char xbuffer[FLOAT_LEN];
        char ybuffer[FLOAT_LEN];
        char zbuffer[FLOAT_LEN];
        path.substring(i+0*FLOAT_LEN, i+1*FLOAT_LEN+1).getBytes(xbuffer, FLOAT_LEN+1);
        path.substring(i+1*FLOAT_LEN, i+2*FLOAT_LEN+1).getBytes(ybuffer, FLOAT_LEN+1);
        path.substring(i+2*FLOAT_LEN, i+3*FLOAT_LEN+1).getBytes(zbuffer, FLOAT_LEN+1);
        double x = atof(xbuffer);
        double y = atof(ybuffer);
        double z = atof(zbuffer);
        Serial.println(String(x) + " " + String(y) + " " + String(z));
        Vector vec = {x, y, z};
    }
}
