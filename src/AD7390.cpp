#include <Arduino.h>
#include <SPI.h>

#include "AD739X.h"

AD7390::AD7390(int load_pin, int clear_pin)
{
    pinMode(clear_pin, OUTPUT);
    digitalWrite(clear_pin, LOW);
    _clear_pin = clear_pin;

    _cleared = true;

	pinMode(load_pin, OUTPUT);
	digitalWrite(load_pin, LOW);
	_load_pin = load_pin;

	/* init SPI */
	SPI.begin();
}

void AD7390::clear()
{
    digitalWrite(_clear_pin, LOW);
    _cleared = true;
}

void AD7390::unclear()
{
    digitalWrite(_clear_pin, HIGH);
    _cleared = false;
}

bool AD7390::isCleared()
{
    return _cleared;
}

bool AD7390::writeValue(uint16_t value)
{
    if(_cleared)
        return true;
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
    digitalWrite(_load_pin, HIGH);
    SPI.transfer16(value);
    digitalWrite(_load_pin, LOW);
    SPI.endTransaction();
    return false;
}
