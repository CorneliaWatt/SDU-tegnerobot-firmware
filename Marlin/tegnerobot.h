#ifndef SERIAL_H
#define SERIAL_H
#include <Arduino.h>

#define FLOAT_LEN 8

String wait_for_message();
void execute_path(String path);
void send_started();

#endif
