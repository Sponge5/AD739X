/* --------------------------------------------------------------
   Example sketch to send value to DAC via serial interface. Open
   serial connection, type value between 0 and 4095 and press enter.
   Check newline (NL) terminator in your terminal.

Author: Christoph Jurczyk
-------------------------------------------------------------- */

#include <AD739X.h>
#include "UserInterface.h"

// Pins
#define LOAD_PIN     15
#define CLEAR_PIN    16

// DAC init
AD7390 dac(LOAD_PIN, CLEAR_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("AD7390!");
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
        if(dacValue != 0 && !dac.isCleared())
            dac.writeValue(dacValue);
        else if(dacValue == 0 && !dac.isCleared())
            dac.clear();
        else if(dacValue != 0 && dac.isCleared())
        {
            dac.unclear();
            dac.writeValue(dacValue);
        }
        delay(10);
    }
}
