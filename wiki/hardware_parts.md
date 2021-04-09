# FAQ
<!-- TOC -->

- [FAQ](#faq)
- [Passive Parts](#passive-parts)
    - [IPU, IPD (internal)](#ipu-ipd-internal)
    - [IR LED Control](#ir-led-control)
    - [POWER check when choosing GPIO](#power-check-when-choosing-gpio)
    - [DC DC Converter](#dc-dc-converter)
- [Memory](#memory)
    - [EEPROM clk speed check (100/400 kHz)](#eeprom-clk-speed-check-100400-khz)
    - [Nandflash](#nandflash)
- [Communication IC](#communication-ic)
    - [UART waveform](#uart-waveform)

<!-- /TOC -->
# Passive Parts
## IPU, IPD (internal)
* Be careful IPU, IPD (They can be set in IC)
* Normally 20k ohm resistor is used
* There are some parts to change the value
* To pull up/down with IPU/IPD, use 1kohm (refer to datasheet)

## IR LED Control
1. FET - current control by voltage
2. Don't make current flow when IR LED Off
3. Hysterisis
    1. to ban oscillation
        1. ex) camera : day <-> night
        2. ex) IRLED : on <-> off

## POWER check when choosing GPIO
* when choosing GPIO, check group voltage
* when you need 3.3V control, you should not connect to 1.8V

## DC DC Converter
can change output voltage when we put not normal volatage into feedback input voltage
- make MCU PWM Signal   DC voltage  with capacitor > can control DC DC Converter output voltage

# Memory
## EEPROM clk speed check (100/400 kHz)
i2c communication clk speed check

## Nandflash 
1. wp (write protection)
    1. when booting, adjust wp for protection
2. flash write limitation
    1. check it. normally 100,000 (refer to datasheet)
    2. to extend : there are techniques 
    3. cautions 
        1. write when is only needed 
        2. don't write at a specific address continuously as possible as I can (rotate address)

# Communication IC
## UART waveform
* 0 ---------- 1
* start, stop
* 8bit data transfer between start and stop
* lsb or msb : in most cases, lsb
* ex) 37 send 0. 1100 1110 1.

