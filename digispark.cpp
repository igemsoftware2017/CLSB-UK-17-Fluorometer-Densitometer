#include "DigiKeyboard.h"

// Set pins to get data from light to frequency converters
#define LED_5V 0
#define LED_GND 1
#define LTF 2

// Count how many times the pin has changed. Useful as TSL235R outputs
// a square wave (i.e. changes), with frequency proportional to light intensity
volatile unsigned long cnt = 0;
unsigned long timeSinceLast;
void irq() {
    cnt++;
}

void setup() {
    // DigiKeyboard setup for older computers (no event indicated)
    // http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(250);

    pinMode(LED_5V, OUTPUT);
    pinMode(LED_GND, OUTPUT);
    digitalWrite(LED_5V, HIGH);
    digitalWrite(LED_GND, LOW);

    pinMode(LTF, INPUT);
    digitalWrite(LTF, HIGH);
    attachInterrupt(0, irq, CHANGE);

    // Reset timer and count to zero so first result is not overly high
    // as will have been counting for brief setup period
    cnt = 0;
    timeSinceLast = millis();
}

void loop() {
    // Check not already measuring
    if (millis() - timeSinceLast > 1000) {
        // Print # counts in last second i.e. the frequency
        DigiKeyboard.print(String(cnt) + ',');

        // Reset to zero for next run
        cnt = 0;

        // Reset timer
        timeSinceLast = millis();
    }

    DigiKeyboard.delay(20);
}
