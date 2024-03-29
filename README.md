# LEDice
Ein Arduino-Projekt, welches zufällige Zahlen innerhalb eines definierten Bereichs auswürfeln und diese über an den Arduino angeschlossene LED-Lampen ausgeben kann. Zu Beginn wird eine Startanimation abgespielt, bei der die Muster aller hinterlegter Zahlen dargestellt werden. Danach geht das System in eine Wartephase über, bei der jeder Knopfdruck zum Abspielen einer Würfelanimation, dem Ermitteln einer zufälligen Zahl und dem Anzeigen der Zahl führt. Dieser Vorgang ist beliebig oft wiederholbar. Wird zu lange kein Würfelvorgang angefordert, werden die Lampen ausgeschaltet und das System geht in einen Ruhemodus über, aus dem es durch einen weiteren Knopfdruck geweckt werden kann.

![Würfelaufbau](https://github.com/Kraeyx/LEDice/assets/131872822/283193c9-4055-45be-9904-3105fe39defc)

## Aufbau
Das Projekt besteht aus 7 LEDs, die jeweils einen Vorwiderstand besitzen sowie einem Taster und einem Arduino Uno R3. Genauere Spezifikationen lassen sich der Stückliste und dem Schaltplan im Ordner res sowie der Entwicklerdokumentation entnehmen.
![Schaltplan](https://github.com/Kraeyx/Diodenwuerfel/assets/131872822/c055aabe-4f51-47bc-a512-298162e817f8)
## Funktionsweise
Zum Anschalten des Projektes den Knopf betätigen. Nach einer Startanimation kann durch erneutes Drücken ein Würfelvorgang durchgeführt werden. Dies lässt sich beliebig oft wiederholen. Sollte zu lange kein Würfelvorgang durchgeführt worden sein, geht das Projekt in einen Ruhezustand über, aus dem es durch erneutes Drücken des Knopfes wieder geweckt werden kann. Das sieht in der Praxis wie folgt aus: (Klicken, um eine Aufzeichnung eines Würfelvorgangs zu erreichen).
[![Bedienungszyklus](https://github.com/Kraeyx/LEDice/assets/131872822/ae686b5f-a76f-43e9-a3a3-0dbc358b5446)](https://github.com/Kraeyx/Diodenwuerfel/assets/131872822/4235a37f-b2ce-4701-979d-85947c56ef22)
## Repository
Im res-Ordner dieses Repositorys befindet sich die Entwicklerdokumentation, in der die Struktur des Projektes eingehender erläutert wird, sowie eine Stückliste benötigter Materialien, der Schaltplan und die Benutzerdokumentation. Der src-Ordner beinhaltet das Hauptprogramm (main.cpp). Im lib-Ordner befindet sich die Bibliothek LED_output. Weitere Ressourcen werden in der Entwicklerdokumnetation eingehender behandelt.

