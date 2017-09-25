// General TODOs:
// TODO: replace all delays with DigiKeyboard.delay() - this ensures the device keeps sending stuff to computer saying it's alive otherwise will think it's disconnected
// TODO: figure out what processing we can do on the device - can't just send interrupt stream but also have limited processing power & memory
// TODO: ensuring pins 2 & 3 are ok for interrupts - especially 3 as it shares USB+ which could cause issues esp. with DigiKeyboard library
// TODO: test viability of just putting the LEDs on 5V, cause may as well be always on

#include "DigiKeyboard.h"

// Set pins to power LEDs and get data from light to frequency converters
// NB: pins 0 and 1 are selected for LEDs as onboard LED can interfere with data readings otherwise
#define LED_F 0
#define LED_OD 1
#define LTF_F 2
#define LTF_OD 3

// Counters of how many times the pin has changed. Useful as TSL235R outputs
// a square wave (i.e. changes), with frequency proportional to light intensity
volatile unsigned long cntF = 0;
unsigned long oldcntF = 0;
unsigned long hz_F = 0;
unsigned long timeSinceLastF;
void irqF() {
    cntF++;
}

volatile unsigned long cntOD = 0;
unsigned long oldcntOD = 0;
unsigned long hz_OD = 0;
unsigned long timeSinceLastOD;
void irqOD() {
    cntOD++;
}

void setup() {
    // DigiKeyboard setup for older computers (no event indicated)
    // http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(250);

    // TODO: I changed the attachInterrupt lines to CHANGE - hopefully this works.
    // We may need to account for double interrupts being called somewhere, however as
    // OD is relative maybe not?

    pinMode(LTF_F, INPUT);
    digitalWrite(LTF_F, HIGH);
    attachInterrupt(LTF_F, irqF, CHANGE);

    pinMode(LTF_OD, INPUT);
    digitalWrite(LTF_OD, HIGH);
    attachInterrupt(LTF_OD, irqOD, CHANGE);

    DigiKeyboard.delay(250);
}

bool getMeasurement(volatile unsigned long *cnt, unsigned long *oldcnt, unsigned long *hz, unsigned long* timeSinceLast) {
    // Check not already measuring
    if (millis() - *timeSinceLast < 1000)
        return false;

    // Reset timer
    *timeSinceLast = millis();

    // Save # counts in last second i.e. the frequency
    *hz = rand() % 20000;//*cnt - *oldcnt;

    // Reset these to zero to prevent buffer overflow
    // TODO: Is this really necessary? Quick estimate gives this will only happen after 5 days.
    *cnt = 0;
    *oldcnt = 0;

    return true;
}

void loop() {
    if(getMeasurement(&cntF, &oldcntF, &hz_F, &timeSinceLastF) != -1) {
        DigiKeyboard.print('F' + String(hz_F) + ',');
    };
    if(getMeasurement(&cntOD, &oldcntOD, &hz_OD, &timeSinceLastOD) != -1) {
        DigiKeyboard.print("OD" + String(hz_OD) + ',');
    };

    DigiKeyboard.delay(400);
}
