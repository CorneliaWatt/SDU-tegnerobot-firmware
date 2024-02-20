#include <Arduino.h>
#include "Marlin.h"

struct Vector {
    double x, y, z;
};

String read_until_newline() {
    String msg = "";
    while (true) {
        char c = MYSERIAL.read();
        if (c != '\n') msg += c;
        else break;
    }
    return msg;
}

String wait_for_message() {
    String msg1, msg2;

    while (true) {
        // Wait until serial data is available
        while(!MYSERIAL.available());

        msg1 = read_until_newline();
        msg2 = read_until_newline();

        if (msg1 == msg2) {
            MYSERIAL.println("ACK");
            return msg1;
        }
        else {
            MYSERIAL.println("Error: Messages do not match.");
            return "";
        }
    }
}

#define FLOAT_LEN 4

void execute_path(String path) {
    MYSERIAL.println("execute_path: " + path);
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
        MYSERIAL.println(String(x) + " " + String(y) + " " + String(z));
        Vector vec = {x, y, z};
    }
}
