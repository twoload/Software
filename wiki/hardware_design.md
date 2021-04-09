# Things to consider

<!-- TOC -->

- [Things to consider](#things-to-consider)
- [1. When drawing electronic circuit](#1-when-drawing-electronic-circuit)
    - [For readability](#for-readability)
    - [Practical Experience](#practical-experience)
- [2. when drawing artwork](#2-when-drawing-artwork)
- [3. when debugging](#3-when-debugging)
- [4. For product reliability](#4-for-product-reliability)
    - [1) temperature](#1-temperature)
    - [2) EMI](#2-emi)
    - [3) LSS, ESD, Impulse](#3-lss-esd-impulse)
        - [LSS](#lss)
        - [ESD](#esd)
    - [4) Safety](#4-safety)
- [5. Produce Jig, Assembly Workability](#5-produce-jig-assembly-workability)
- [6. AS (After Service)](#6-as-after-service)

<!-- /TOC -->

# 1. When drawing electronic circuit 

## For readability

When drawing circuit diagram, it is good to draw for understanding easily.
1. --------------> (dataflow : start from left to right)
   Because I think it is more comfortable for people to see something  from left to right direction.
2. Element Library
   Draw like symbol that datasheet offers rather than pin order(1,2,3...)
   Because similar function pins are nearby each other. 
   It is easy to draw on a function base. (datasheet application)
   And element having a lot of pins is divided into several blocks.
3. It is good to draw block diagram at a front page of circuit
4. Be careful of TX/RX signals names from connector
   1. Mistake sometimes happens that TX/RX are connected wrong.
   2. ex) need own naming rule : TX from CPU, RX from Micom 
5. When draw data line, use Bus line and page connector

## Practical Experience

1. Connector Pin Map
   1. Locate Pin map not to happen Power/GND short though user connects cable in an opposite direction
2. Numbers of connector pin
   1. Power pin : set pin numbers considering the amount of current flowing
      1. ex) If we have to supply 5V/1A with 400mA/Pin Connector, use over 3 pins (1A < 400x3mA)
   2. And GND pin : the same pin numbers as POWER pins
      1. reason : need Return Path. we have to make Power flow load 

# 2. when drawing artwork

1. consider POWER path
2. imagine connection diagram with connector, power and signals
3. consider element location at the same time
   1. we can print 1:1 circuit diagram and match to mechanic diagram on a paper
4. consider the amount of current 
   1. path thickness, length, via numbers
5. check if items are located as my intention.
   1. see if related items get together
      (bypass cap is located nearby element)
6.  Don't make GND island
   1. make one GND
7. Secure GND via
8. make signal lines and GND not sharp (the cause of EMI radiation)
9. Important Signal lines are covered by GND
   1. ex. video output signals and clock

# 3. when debugging
Booting Issue
1. check by eye : SMT
2. cold soldering joint : simply push IC strongly by finger and see. or request to check
3. timing : check with dryer and freezer
4. programming register value (ex. PLL)
5. PCB line disconnection
6. chip failure : check lot

# 4. For product reliability

## 1) temperature

## 2) EMI

1. metal frame convers circuit (Good EMI : shielding effect )
2. EMI radiate through cable
   1. check if PCB pattern (to cable) passes by the elements giving noise --> not to pass by
   2. fix it for preventing cable from moving
   3. use EMI core (proper frequency)
   4. FFC cable : GND shield (with cable GND), flat EMI core
   5. signal clock line : serial resistance

## 3) LSS, ESD, Impulse

### LSS

Use TVS Diode so that LSS goes to GND through it not to have influence on other ICs.

1. divide GND 
2. Ethernet Protection Circuit (TVS diode) : locate it to between ethernet transformer and phyceiver rather than between transformer and outside line 
3. increase serial resistance value for audio input signal

### ESD

make PCB hole through hole (metal) and make it touch to mechanical chassis to get large GND

how to touch mechanical chassis
- wire
- EMI gasket

consider GND combination or separation

how to trace the cause

- Suspicious IC : what has an influence on it ?
  - lower supply power
  - short crystal
  - short input signal
  - reset
  - GND combination or separation 

## 4) Safety

# 5. Produce Jig, Assembly Workability
1. Produce Jig
  1. PCB hole for routing
    ideal : 4 EA each square edge, 3 EA in a triangle shape in case of not locate All 4EA    
  2. make over 3EA for GND TP (TestPoint)
    Because GND can be short for several POWER TP
2. Assembly Workability
  1. locate connector for easy assemble with cable
  2. not to use same pin number connector as possible as I can
  3. put parts over 1mm away from machine hole when PCB thickness is 1t
  4. parts +/- silk marking
  5. machine hole has to hold PCB stable for SMT

# 6. AS (After Service)
when board failure happens,
1. HW : offer trouble shooting guide
2. SW : how to use SW tool
  1. program download
  2. check and adjust program



     
