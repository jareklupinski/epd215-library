This is a library for the Pervasive Displays Epaper Screen E2215CS062.
This library has been written for and fully supports the Teensy-LC and the rest of the Teensy 3.x series and uses their native SPI library.
It can also be used with Arduino, ESP8266, and most available microcontrollers, optionally using a slower bitbanged interface.

This code and further updates will be hosted at https://github.com/jarek319/EPD215

These displays use SPI to communicate. For more information on the signaling protocol used, please see the official datasheet for all the details: http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=232068

Written by Jarek Lupinski for Soniktech LLC  
Adapted from Adafruit GFX library driver code
BSD license, check license.txt for more information
All text above must be included in any redistribution

To download: click the DOWNLOADS button in the top right corner, rename the uncompressed folder EPD215. Check that the EPD215 folder contains EPD215.cpp and EPD215.h

Place the EPD215 library folder in your <arduinosketchfolder>/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE.

You will also have to download the Adafruit GFX Graphics core which does all the circles, text, rectangles, etc. You can get it from
https://github.com/adafruit/Adafruit-GFX-Library
and download / install that library as well 