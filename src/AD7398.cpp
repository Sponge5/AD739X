/* --------------------------------------------------------------
	Arduino Library for the Analog Devives AD7390 12-bit DAC

	Author: Christoph Jurczyk
 -------------------------------------------------------------- */

#include "Arduino.h"
#include "AD7398.h"
#include <SPI.h>

AD7398::AD7398(int cs_pin, int latch_pin)
{
	/* chip select */
	pinMode(cs_pin, OUTPUT);
	digitalWrite(cs_pin, LOW);
	_cs_pin = cs_pin;
    /* latch pin */
    pinMode(latch_pin, OUTPUT);
	digitalWrite(latch_pin, LOW);
    _latch_pin = latch_pin;

    SPI.begin();
}

uint8_t AD7398::writeValue(enum Channel channel, uint16_t value)
{
    if(value > 0x0FFF)
        return 1;
    value &= 0x0FFF;
    /* transfer data */
    switch(channel)
    {
        case CHANNEL_A:
            value |= CHANNEL_A_ADDR;
            break;
        case CHANNEL_B:
            value |= CHANNEL_B_ADDR;
            break;
        case CHANNEL_C:
            value |= CHANNEL_C_ADDR;
            break;
        case CHANNEL_D:
            value |= CHANNEL_D_ADDR;
            break;
    }
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
    digitalWrite(_latch_pin, HIGH);
    digitalWrite(_cs_pin, LOW);
    SPI.transfer16(value);
    digitalWrite(_cs_pin, HIGH);
    SPI.endTransaction();
    digitalWrite(_latch_pin, LOW);
    __asm__("nop\n\t");
    digitalWrite(_latch_pin, HIGH);
    __asm__("nop\n\t");
    digitalWrite(_latch_pin, LOW);
    return 0;
}
