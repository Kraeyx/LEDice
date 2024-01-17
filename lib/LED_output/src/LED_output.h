/**
 * @file LED_output.h
 * Header-Datei der Bibliothek LED_output, die die Ausgabe einer Zahl auf einem Muster LEDs ausgibt.
 * @author Deu
*/
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
 int MIN_NUMBER;
 int MAX_NUMBER;
 };
#endif