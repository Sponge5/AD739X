#ifndef __AD739X_H__
#define __AD739X_H__

class AD7390
{
public:
	AD7390(int load_pin, int clear_pin);
	bool writeValue(uint16_t value);
    bool isCleared();
    void clear();
    void unclear();
private:
    int _clear_pin;
	int _load_pin;
    bool _cleared;
};

class AD7398
{
public:
    enum Channel { CHANNEL_A, CHANNEL_B, CHANNEL_C, CHANNEL_D };
	AD7398(int cs_pin, int latch_pin);
	uint8_t writeValue(enum Channel channel, uint16_t value);
private:
	int _cs_pin;
    int _latch_pin;
    enum ChannelAddress
    {
        CHANNEL_A_ADDRESS = 0x0000,
        CHANNEL_B_ADDRESS = 0x1000,
        CHANNEL_C_ADDRESS = 0x2000,
        CHANNEL_D_ADDRESS = 0x3000,
    };
};

#endif /* __AD739X_H__ */

