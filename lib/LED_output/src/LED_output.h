#ifndef LED_output_h
#define LED_output_h
#include "Arduino.h"

class LED_output {
 public:
 LED_output(const int* pins, const int pinCount);
 private:
 const int* _pins;
 const int _pinCount;
 void displayNumber(int num);
};
#endif