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
        int channel = read_int();
        switch(channel)
        {
            case CHANNEL_A:
                Serial.println("Output: CHANNEL A");
                break;
            case CHANNEL_B:
                Serial.println("Output: CHANNEL B");
                break;
            case CHANNEL_C:
                Serial.println("Output: CHANNEL C");
                break;
            case CHANNEL_D:
                Serial.println("Output: CHANNEL D");
                break;
            default:
                Serial.println("WRONG OUTPUT, SETTING CHANNEL A");
                channel = CHANNEL_A;
                break;
        }
        Serial.print("Choose value: ");
        int newValue = read_int();
        Serial.println(newValue);
        uint16_t dacValue = ((uint16_t)newValue) & 0x0FFF;
        Serial.print("Setting value: ");
        Serial.println(dacValue);
        /* set dac */
        dac.writeValue((enum Channel)channel, dacValue);
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
