#include <Arduino.h>
#include <LED_output.h>

const int* _pins;
const int _pinCount;

LED_output::LED_output(const int* pin, const int pinCount):_pins(pin), _pinCount(pinCount) {}

/**
 * Verdunkelt alle LEDs
*/
void clearLED() {
  for(int i = 0; i < _pinCount; i++) {
    digitalWrite(*(_pins+i), LOW);
  }
}

void LED_output::displayNumber(int num) {
    switch(num) {
    case 1: 
      digitalWrite(*(_pins+3), HIGH);
      break;
    case 2: 
      digitalWrite(*_pins, HIGH);
      digitalWrite(*(_pins+6), HIGH);
      break;
    case 3:
      digitalWrite(*_pins, HIGH);
      digitalWrite(*(_pins+3), HIGH);
      digitalWrite(*(_pins+6), HIGH);
      break;
    case 4: 
      digitalWrite(*_pins, HIGH);
      digitalWrite(*(_pins+2), HIGH);
      digitalWrite(*(_pins+4), HIGH);
      digitalWrite(*(_pins+6), HIGH);
      break;
    case 5: 
      digitalWrite(*_pins, HIGH);
      digitalWrite(*(_pins+2), HIGH);
      digitalWrite(*(_pins+3), HIGH);
      digitalWrite(*(_pins+4), HIGH);
      digitalWrite(*(_pins+6), HIGH);
      break;
    case 6:
      digitalWrite(*_pins, HIGH);
      digitalWrite(*(_pins+1), HIGH);
      digitalWrite(*(_pins+2), HIGH);
      digitalWrite(*(_pins+4), HIGH);
      digitalWrite(*(_pins+5), HIGH);
      digitalWrite(*(_pins+6), HIGH);
      break;
    default: 
      Serial.print("Fehler! Nummer " + String(num) + " ist ungültig");
      break;
    }
}
