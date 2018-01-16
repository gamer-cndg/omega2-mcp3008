# Omega2 MCP3008 library

### Description

This repository contains C and Python code for interfacing an Omega2(+) with an MCP3008. The MCP3008 is a 10-bit ADC over SPI ([datasheet](https://cdn-shop.adafruit.com/datasheets/MCP3008.pdf)).

It makes use of [Onion's SPI GPIO driver](https://github.com/OnionIoT/spi-gpio-driver). The port is mainly ported from [Adafruit's MCP3008 library](https://github.com/adafruit/Adafruit_MCP3008) (MIT licensed).

### Wireup

SPI GPIO pins can be freely chosen in software. The chip also needs a supply voltage (2.7V to 5.5V) and ground. Refer to the datasheet for details.

### API Usage

C: 
```c
bool MCP3008_Startup(int miso, int mosi, int sclk, int cs);
int MCP3008_ReadChannel(int channel);
int MCP3008_ReadChannelDifferential(int differential);
```

Python:
```python
spi = initADC(9,8,7,6)
chan = 0 #from 0 to 8
adcVal = readADC(spi, chan)
#also: read differential values (e.g. channel 0 minus channel 1)`
adcDifVal = readADC(spi, chan)
```

All returned ADC values are integers, with 10 bits filled from the ADC. You may convert it into a voltage by remapping the value from the input range 0-1023 to 0-3.3 (i.e. `voltage = adcValue * (3.3 / 1023.0)`).

### Credits

* Adafruit for the original code (https://github.com/adafruit/Adafruit_MCP3008)
* Maximilian Gerhardt, porter for C + Python
* Forum questions ([here](https://community.onion.io/topic/2655/mcp3008-spi-addressing-and-0x00-returned-values), [here](https://community.onion.io/topic/1745/using-a-mcp3008-via-spi))

