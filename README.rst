AD739X
======
Arduino Library for AD7390 and AD7398 DAC chips from Analog Devices.

Usage
=====
To use the library include the header-file and initialize an object as follows:

.. code-block::

    #include <AD739X.h>

    #define DAC_LOAD    8
    #define DAC_CLEAR   9
    AD7390 dac(DAC_LOAD, DAC_CLEAR);

To send a new value to the DAC call the following function:

.. code-block::

    uint16_t value = 1024;
    dac.writeValue(value);

That's it. There are also some examples available for better understanding.
