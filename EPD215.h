/*********************************************************************
This is a library for the Pervasive Displays Epaper Screen E2215CS062.
This library has been written for and fully supports the Teensy-LC and the rest of the Teensy 3.x series and uses their native SPI library.
It can also be used with Arduino, ESP8266, and most available microcontrollers, optionally using a slower bitbanged interface.

This code and further updates will be hosted at https://github.com/jarek319/EPD215

These displays use SPI to communicate. For more information on the signaling protocol used, please see the official datasheet for all the details: http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=232068

Written by Jarek Lupinski for Soniktech LLC  
Adapted from Adafruit GFX library driver code
BSD license, check license.txt for more information
All text above must be included in any redistribution
*********************************************************************/
#ifndef _EPD215_H_
#define _EPD215_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <SPI.h>
#include <Adafruit_GFX.h>

//Default is Portrait view
#define WIDTH    112
#define HEIGHT   208

#define BLACK    0
#define WHITE    1
#define INVERSE  2

#define DRIVEROUTPUTCONTROL 0x01
#define GATESCANSTART       0x0F
#define DATAENTRYMODE       0x11
#define SETRAMXSTARTEND     0x44
#define SETRAMYSTARTEND     0x45
#define SETRAMXADDRESS      0x4E
#define SETRAMYADDRESS      0x4F
#define SETBORDERWAVEFORM   0x3C
#define SETGATEDRIVINGVOLT  0x03
#define NORMALANALOGMODE1   0x05
#define NORMALANALOGMODE2   0x75
#define SENDIMAGEDATA       0x24
#define SETTEMPERATURE      0x1A
#define SETUPDATESEQUENCE   0x22
#define ACTIVEDISPLAYUPDATE 0x20

class EPD215 : public Adafruit_GFX {
 public:
  EPD215( uint32_t cs, uint32_t dc, uint32_t rs, uint32_t bs, int32_t d0 = 0xFF, int32_t d1 = 0xFF );
  void initScreen();
  void updateScreen( uint8_t temperature = 0x1A );
  void clearScreen();
  void writeToBuffer( uint8_t *buf );
  void softwareSpi( uint8_t data );
  void drawPixel( int16_t x, int16_t y, uint16_t color );

 private:
  uint32_t _d0, _d1, _cs, _dc, _rs, _bs;
  uint8_t _spiMode, _rotation, _cursorX, _cursorY;
  void _sendIndexData( uint8_t index, uint8_t *data, uint16_t len );
  uint8_t _bitReverse( uint8_t x );

};

#endif /* _EPD215_H_ */
