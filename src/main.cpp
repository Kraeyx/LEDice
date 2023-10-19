#include <Arduino.h>

const int LED_COUNT = 7;
const int LED_PINS[LED_COUNT] = {8,7,6,5,4,3,2};
const int BUTTON_PIN = 11;

/**
 * Initialisiert die Pins und den Initialzustand
*/
void setup() {
  for(int i=0; i < LED_COUNT;i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
}
/**
 * Zeigt über die LEDs eine Nummer an
*/
void showNumber(int num) {
  switch(num) {
    case 1: 
      digitalWrite(LED_PINS[5], HIGH);
      break;
    case 2: 
      digitalWrite(LED_PINS[0], HIGH);
      digitalWrite(LED_PINS[6], HIGH);
      break;
    case 3:
      digitalWrite(LED_PINS[0], HIGH);
      digitalWrite(LED_PINS[3], HIGH);
      digitalWrite(LED_PINS[6], HIGH);
      break;
    case 4: 
      digitalWrite(LED_PINS[0], HIGH);
      digitalWrite(LED_PINS[2], HIGH);
      digitalWrite(LED_PINS[4], HIGH);
      digitalWrite(LED_PINS[6], HIGH);
      break;
    case 5: 
      digitalWrite(LED_PINS[0], HIGH);
      digitalWrite(LED_PINS[2], HIGH);
      digitalWrite(LED_PINS[3], HIGH);
      digitalWrite(LED_PINS[4], HIGH);
      digitalWrite(LED_PINS[6], HIGH);
      break;
    case 6:
      digitalWrite(LED_PINS[0], HIGH);
      digitalWrite(LED_PINS[1], HIGH);
      digitalWrite(LED_PINS[2], HIGH);
      digitalWrite(LED_PINS[4], HIGH);
      digitalWrite(LED_PINS[5], HIGH);
      digitalWrite(LED_PINS[6], HIGH);
      break;
    default: 
      Serial.print("Fehler! Nummer ungültig");
      break;
    }
}
/**
 * Verdunkelt alle LEDs
*/
void clearLED() {
  for(int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}

/**
 * Testet auf einen Knopfdruck und führt, wenn nötig, den Würfelvorgang durch
*/
void loop() {
    clearLED();
    int result = 1 + rand() % 5;
    showNumber(result);
    delay(2000);
}
