#ifndef LED_output_h
#define LED_output_h
#include "Arduino.h"

class LED_output {
 public:
 LED_output(const int* pins, const int pinCount, const int minNumber, const int maxNumber);
 void displayNumber(int num);
 void clearLEDs();
 void initPins();
 void startAnim();
 void blink();
 private:
 const int* _pins;
 int _pinCount;
 };
#endif