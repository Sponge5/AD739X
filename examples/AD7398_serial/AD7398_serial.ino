/* --------------------------------------------------------------
   Example sketch to send value to DAC via serial interface. Open
   serial connection, type value between 0 and 4095 and press enter.
   Check newline (NL) terminator in your terminal.

Author: Christoph Jurczyk
-------------------------------------------------------------- */

#include "AD7398.h"
#include "UserInterface.h"

// Pins
#define DAC_CS_PIN  2
#define LATCH_PIN   3
#define RESET_PIN   4

// DAC init
AD7398 dac(DAC_CS_PIN, LATCH_PIN);

// Variables
String inString = "";


void setup() {
    pinMode(RESET_PIN, OUTPUT);
    digitalWrite(RESET_PIN, HIGH);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    Serial.begin(115200);
    Serial.println("Hello world!");
}


void loop() {
    if(Serial.available())
    {
        int newValue = read_int();
        Serial.print("Read: ");
        Serial.println(newValue);
        uint16_t dacValue = ((uint16_t)newValue) & 0x0FFF;
        Serial.print("Set: ");
        Serial.println(dacValue);
        /* set dac */
        dac.writeValue(CHANNEL_A, dacValue);
        delay(10);
        Serial.print(analogRead(A0));
        Serial.println(" A0");
        Serial.print(analogRead(A1));
        Serial.println(" A1");
        Serial.print(analogRead(A2));
        Serial.println(" A2");
        Serial.print(analogRead(A3));
        Serial.println(" A3");
    }
}
