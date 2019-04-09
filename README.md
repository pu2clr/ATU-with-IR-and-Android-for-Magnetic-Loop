# Antenna Tuner for Magnetic Loop Antenna controlled by Arduino via IR


## Table of contents

* [Introduction](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#introduction)
* [Component parts](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#component-parts)
* [Schematic](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#schematic)
* [Arduino sketch](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#arduino-sketch)
* [Photos](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#photos)
* [Videos](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop#videos)


## Introduction

Magnetic Loop Antenna is very useful for limited space and also portability.  It can provide reasonable gain on 20, 17 and 15 meters and excellent gain on 10 meters.   However, working with a Magnetic Loop Antenna can become uncomfortable sometimes doe to constant need to adequate it to the frequency or band that the user wants to work. This project tries to minimize this problem by allowing the user control the antenna remotely.

Using few components, this project intends to implement a remote control for a Magnetic Loop Antenna tha can be used with an Alexloop or a homebrew antenna.  


## Component parts

### [Servo TG9 Servo](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)

Small and lightweight with considerable output power. This Servo can rotate approximately 180 degrees, and works like a standard servo.



- [Rotary Encoder - Illuminated (Red/Green)](https://www.sparkfun.com/products/10596)
- [Infrared receiver (taken from a scrap DVD player)](http://www.ebay.com/itm/- VS1838B-Infrared-receiver-38Khz-Infrared-sensor-IR-Infrared-Receiver-/260875354763?pt=LH_DefaultDomain_0&hash=item3cbd62028b)
- [Arduino (Pro Mini atmega328 5V)](http://www.ebay.com/itm/New-ver-Promini-Pro-Mini-atmega328-328p-5V-16MHz-Arduino-Compatible-nano-size-/321090929788?pt=LH_DefaultDomain_0&hash=item4ac282c47c)
- [LEDS (Gree, Blue, Red and Yellow)](http://www.ebay.com/itm/271092424896?ssPageName=STRK:MEWNX:IT&_trksid=p3984.m1439.l2649)
- [VARIABLE CAPACITOR TWO GANG JACKSON BROS](http://www.ebay.com/itm/VARIABLE-CAPACITOR-TWO-GANG-JACKSON-BROS-/300844646071?pt=LH_DefaultDomain_3&hash=item460bbcfeb7)



## Schematic


![schematic](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/schematic/schematic_arduino_IR-NEW.png)



## Arduino sketch


There are two Arduino sketch version for this project.... see source folder ... to be continue... 




## Final consideration 


Before I started this project, I was worried if the Arduino could cause unwanted noise or interference in my reception, specially, if it works very close to loop antenna. Actually, there is a crystal that oscillates at 16MHz on Arduino board and other components that potentially can generate unwanted signal. However, I haven’t noticed any difference using the loop antenna with this system on and off.   



## Photos


![Photo 01](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo01.jpg)


![Photo 02](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo02.jpg)


![Photo 03](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo03.jpg)


![Photo 04](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo04.jpg)


## Videos

- [Arduino, IR and Encoder controlling Magnetic Loop Antenna Tuner](https://youtu.be/zD-wKD19_8U)





73
PU2CLR

Ricardo Caratti - 17 / 11 / 2013

email: pu2clr@gmail.com



