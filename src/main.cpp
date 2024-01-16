/**
Ein Programm, welches einen Würfel darstellt. Zu Beginn und vor jedem Würfelvorgang wird eine Animation abgespielt.
Ein Würfelvorgang erfolgt auf Knopfdruck. Wird zu lange nicht gewürfelt, wird ein Ruhemodus eingeschaltet, der durch einen
Knopfdruck beendet werden kann.
 @author Deu
*/
#include <Arduino.h>
#include <avr/sleep.h>
#include <LED_output.h>

const int LED_COUNT = 7;  //Anzahl der LEDs
const int LED_PINS[LED_COUNT] = {6,7,8,5,12,3,4}; //Pinbelegung der LEDs
const int BUTTON_PIN = 2; //Pin, an den der Button angeschlossen ist
const int RESULT_MINIMUM = 1; //Mindestens gewürfelte Zahl
const int RESULT_MAXIMUM = 6; //Höchstens gewürfelte Zahl
const int sleepClock = 3000; //Taktzahl, nach der der Ruhemodus eingeschaltet wird
LED_output out(&LED_PINS[0], LED_COUNT, RESULT_MINIMUM, RESULT_MAXIMUM); //Instanz der Ausgabe
int clockWaiter; // Taktzähler
boolean start; //Information, ob ein Startvorgang läuft

/**
 * Setzt den Taktzähler auf 0 und macht den Button nach dem Aufwachen eingabebereit
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
 * Startet den Sleep-Modus
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
  randomSeed(analogRead(0));
  start = true;
}


/**
 * Testet auf einen Knopfdruck und führt, wenn nötig, den Würfelvorgang durch
*/
void loop() { 
  //Wenn kein Starvorgang ausgeführt wird und der Knopf gedrückt wurde, wird eine Zahl gewürfelt und angezeigt
  if (!start && !digitalRead(BUTTON_PIN)){
    out.blink();
    out.blink();
    out.blink();
    randomSeed(analogRead(0));
    int result = random(RESULT_MINIMUM, RESULT_MAXIMUM);
    out.displayNumber(result);
    clockWaiter = 0;
    delay(500);
  }
    //Wenn zu lange nicht gewürfelt wurde, wird der Ruhemodus gestartet
  else if (!start && clockWaiter >= sleepClock){
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), isAwake, LOW);
    out.clearLEDs();
    delay(100);
    enterSleepMode();
  }
  //Ausführen des Startvorgangs wenn nötig
  else if (start) {
    out.startAnim();
    Serial.println("gestartet");
    delay(500);
    start = false;
  }
  //Inkrementierung des Taktzählers
  else {
      clockWaiter++;
      Serial.print("Takt:");
      Serial.println(clockWaiter);
  }
}
