# Repeater for Infrared Remote Control

This project implements a simple repeater to extend the signal of IR remote control.


## How does it work?

Typical IR receiver module output looks like this:

![Imgur](https://i.imgur.com/86h8POu.png)

The implentation presented here does not decode the IR signal but simply repeats it.
Typical IR receiver module will demodulate the signal sent over 38 kHz carrier frequency as illustrated by the figure above.
The signal must be reconstructed, including the carrier frequency.

STM32F030 microcontroller is used to receive the data from the IR receiver module and to reconstruct
the output signal to the IR LED.


## Building the repeater

Data pin from IR receiver is connected to pin PA_4 of the microcontroller.
IR LED is driven with 3.3V by pin PB_1.
100 Ohm resistor is used as current limiting resistor.
The LED does not need to be bright since it will be located right besides
the remote controlled device.

![Imgur](https://i.imgur.com/eiFSDV1.jpg)

The source code for the microcontroller is available [here](src/main.cpp). It is written by using Mbed OS
and [PlatformIO](https://platformio.org/) as build environment.

Here is whay the finished product looks like:

![Imgur](https://i.imgur.com/3r9AKe0.jpg)
![Imgur](https://i.imgur.com/OJ5KOdU.jpg)


## Bill of materials

* [STM32F030F4P6](https://www.st.com/en/microcontrollers/stm32f030f4.html) development board (from [Aliexpress](https://www.aliexpress.com/wholesale?SearchText=STM32F030F4P6+development+board))
* TL1838 Infrared Receiver ([datasheet](https://cdn.instructables.com/ORIG/FT3/GKNT/IIQC8H9T/FT3GKNTIIQC8H9T.pdf))
* IR LED from an old remote control
* Project box and cables (one 3 core and one 2 core cable)
