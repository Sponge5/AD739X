/* --------------------------------------------------------------
	Arduino Library for the Analog Devives AD7390 12-bit DAC

	Author: Christoph Jurczyk
	Version: 1.0

	Changelog:
		1.0		12.08.2018:		Initial Upload

 -------------------------------------------------------------- */

#ifndef AD7398_H
#define AD7398_H

#include "Arduino.h"

#define CHANNEL_A_ADDR          0x0000
#define CHANNEL_B_ADDR          0x1000
#define CHANNEL_C_ADDR          0x2000
#define CHANNEL_D_ADDR          0x3000

enum Channel
{
    CHANNEL_A,
    CHANNEL_B,
    CHANNEL_C,
    CHANNEL_D
};

class AD7398
{
public:
	AD7398(int cs_pin, int latch_pin);
	uint8_t writeValue(enum Channel channel, uint16_t value);
private:
	int _cs_pin;
    int _latch_pin;
};

#endif
