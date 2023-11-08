#include <Arduino.h>
#include <avr/sleep.h>
#include <LED_output.h>;

const int LED_COUNT = 7;
const int LED_PINS[LED_COUNT] = {6,7,8,5,12,3,4};
const int BUTTON_PIN = 2;
LED_output* out;
int clockWaiter;
boolean start;

/**
 * Setzt den Taktzähler auf 0 und macht den Button eingabebereit
*/
void isAwake(void)
{
  clockWaiter = 0;
  detachInterrupt(BUTTON_PIN);
  delay(200);
  start = true;
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
  Serial.begin(38400);
  clockWaiter = 0;
  LED_output out_(&LED_PINS[0], LED_COUNT);
  out = &out_;
  (*out).initPins();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  start = true;
}


/**
 * Testet auf einen Knopfdruck und führt, wenn nötig, den Würfelvorgang durch
*/
void loop() { 
  if (!start && !digitalRead(BUTTON_PIN)){
    (*out).clearLEDs();
    int result = 1 + (rand() % 6);
    Serial.println("Nummer: " + result);
    delay(100);
    (*out).displayNumber(result);
    clockWaiter = 0;
    delay(500);
  }
  else if (!start && clockWaiter >= 1500){
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), isAwake, LOW);
    Serial.println("Entering sleep");
    (*out).clearLEDs();
    delay(100);
    enterSleepMode();
  }
  else if (start) {
    (*out).startAnim();
    Serial.println("gestartet");
    start = false;
  }
  else {
      clockWaiter++;
      Serial.println(clockWaiter);
  }
}
