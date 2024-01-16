#include <Arduino.h>
#include <LED_output.h>


const int* _pins; /** Zeiger auf den ersten Pin*/
int _pinCount; /** Anzahl der zugewiesenen Pins*/
int MIN_NUMBER; /** Minimal darstellbare Zahl*/
int MAX_NUMBER; /** Maximal darstellbare Zahl*/

/**
 * Konstruiert eine Instanz der Klasse
 * @param pin Zeiger auf die Belegung des ersten Pins
 * @param pinCount Anzahl der Pins
*/
LED_output::LED_output(const int* pin, const int pinCount, const int minNumber, const int maxNumber) {
  _pins = pin;
  _pinCount = pinCount;
  MIN_NUMBER = minNumber;
  MAX_NUMBER = maxNumber;
}

/**
 * Spielt eine Animation ab, bei der alle Zahlen von 1 bis 6 dargestellt werden
*/
void LED_output::startAnim() {
  for (int i = MIN_NUMBER; i <= MAX_NUMBER; i++) {
    Serial.println("Startnummer: " + String(i));
    delay(100);
    displayNumber(i);
    delay(200);
    clearLEDs();
  }
}
/**
 * Verdunkelt alle LEDs
*/
void LED_output::clearLEDs() {
  for(int i = 0; i < _pinCount; i++) {
    digitalWrite(*(_pins+i), LOW);
  }
}

/**
 * Stellt eine Nummer auf den LEDs dar
 * @param num Darzustellende Nummer
*/
void LED_output::displayNumber(int num) {
    switch(num) {
    case 1: 
      Serial.println("printing 1");
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
/**
 * Lässt alle LEDs aufblinken
*/
void LED_output::blink() {
  clearLEDs();
  for (int i = 0; i < _pinCount; i++) {
    digitalWrite(*(_pins+i), HIGH);
    Serial.println();
  }
  delay(200);
  clearLEDs();
  delay(100);
}
/**
 * Initialisiert die benötigten Pins für die Ausgabe
*/
void LED_output::initPins() {
    for(int i=0; i < _pinCount;i++) {
    pinMode(*(_pins + i), OUTPUT);
  }
}
