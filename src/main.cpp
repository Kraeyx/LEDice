#include <Arduino.h>
#include <avr/sleep.h>
#include <LED_output.h>

const int LED_COUNT = 7;
const int LED_PINS[LED_COUNT] = {6,7,8,5,12,3,4};
const int BUTTON_PIN = 2;
LED_output out(&LED_PINS[0], LED_COUNT);
int clockWaiter;
boolean start;

/**
 * Setzt den Taktzähler auf 0 und macht den Button eingabebereit
*/
void isAwake(void)
{
  clockWaiter = 0;
  Serial.println("isAwake");
  detachInterrupt(digitalPinToInterrupt(BUTTON_PIN));
  delay(200);
  start = true;
}

/**
 * Started den Sleep-Modus
*/
void enterSleepMode(void)
{
    Serial.println("Entering sleep");
    delay(100);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
}
/**
 * Initialisiert die Pins und den Initialzustand
*/
void setup() {
  Serial.begin(38400);
  clockWaiter = 0;
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  start = true;
}


/**
 * Testet auf einen Knopfdruck und führt, wenn nötig, den Würfelvorgang durch
*/
void loop() { 
  if (!start && !digitalRead(BUTTON_PIN)){
    out.blink();
    out.blink();
    out.blink();
    int result = 1 + (rand() % 6);
    out.displayNumber(result);
    clockWaiter = 0;
    delay(500);
  }
  else if (!start && clockWaiter >= 3000){
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), isAwake, LOW);
    out.clearLEDs();
    delay(100);
    enterSleepMode();
  }
  else if (start) {
    out.startAnim();
    Serial.println("gestartet");
    delay(500);
    start = false;
  }
  else {
      clockWaiter++;
      Serial.println(clockWaiter);
  }
}
