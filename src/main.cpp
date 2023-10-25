#include <Arduino.h>
#include <avr/sleep.h>

const int LED_COUNT = 7;
const int LED_PINS[LED_COUNT] = {6,7,8,5,12,3,4};
const int BUTTON_PIN = 2;
int clockWaiter;

/**
 * Setzt den Taktzähler auf 0 und macht den Button eingabebereit
*/
void isAwake(void)
{
  clockWaiter = 0;
  detachInterrupt(BUTTON_PIN);
}

/**
 * Started den Sleep-Modus
*/
void enterSleepMode(void)
{
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
}
/**
 * Initialisiert die Pins und den Initialzustand
*/
void setup() {
  Serial.begin(19200);
  clockWaiter = 0;
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
    Serial.println("Angekommen");
    clearLED();
    int result = 1 + (rand() % 6);
    Serial.println("Nummer: " + result);
    showNumber(result);
    clockWaiter = 0;
    delay(1000);
  }
  else if (clockWaiter >= 1500){
      attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), isAwake, LOW);
      Serial.println("Entering sleep");
      delay(1000);
      clearLED();
      enterSleepMode();
  }
  else {
      clockWaiter++;
  }
    Serial.println(clockWaiter);
}
