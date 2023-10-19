#include <Arduino.h>

const int LED_COUNT = 7;
const int LED_PINS[LED_COUNT] = {6,7,8,5,2,3,4};
const int BUTTON_PIN = 12;

/**
 * Initialisiert die Pins und den Initialzustand
*/
void setup() {
  Serial.begin(9600);
  for(int i=0; i < LED_COUNT;i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
/**
 * Zeigt über die LEDs eine Nummer an
*/
void showNumber(int num) {
  switch(num) {
    case 1: 
      digitalWrite(LED_PINS[3], HIGH);
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
  if (!digitalRead(BUTTON_PIN)){
    clearLED();
    int result = 1 + (rand() % 6);
    Serial.println(result);
    showNumber(result);
    delay(1000);
    }
}
