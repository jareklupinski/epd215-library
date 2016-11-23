#include "EPD215.h"

#include "font.h" //Comment out this line if you want to use custom fonts

#include "Arduino.h"

#define HEIGHT 208
#define WIDTH 112
#define SPACING 2

//------------------------------------------------------------------------------
// Image generated by LCD Assistant
// http://en.radzio.dxp.pl/bitmap_converter/
//------------------------------------------------------------------------------
extern const uint8_t fontBitmaps[];
extern const uint32_t fontDescriptors[][3];

uint8_t _buffer [] = { //SonikTech Splash Screen
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x0F, 0xF8,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x01, 0xFF, 0xFC, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x01, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xC0, 0x07, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x3F, 0xFF, 0xFF, 0xE0, 0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x7F,
  0xFF, 0xFF, 0xF0, 0x1F, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x30, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
  0xF8, 0x3F, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x30, 0x0C, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFC, 0x7F,
  0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x30, 0x0C, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFC, 0x7F, 0xFF, 0xFF,
  0xF0, 0x3E, 0x00, 0x30, 0x0C, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xC0, 0x7C,
  0x00, 0x30, 0x0C, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0x81, 0xF0, 0x00, 0x30,
  0x0C, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0xC0, 0x00, 0x30, 0x0C, 0x00,
  0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xC0, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xC0, 0x40, 0x30, 0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFE, 0x03, 0xC0, 0xC0, 0x30, 0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFE, 0x03, 0xC3, 0xC0, 0x30, 0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
  0x01, 0xCF, 0xC0, 0x30, 0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0xFE,
  0xC0, 0x30, 0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFC, 0xC0, 0x30,
  0x0C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x00, 0x71, 0xC0, 0x30, 0x0C, 0x00,
  0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x00, 0x41, 0xC0, 0x30, 0x0C, 0x00, 0x07, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x80, 0x03, 0x80, 0x30, 0x0C, 0x00, 0x07, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFE, 0x01, 0xC0, 0x07, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF8, 0x01, 0xE0, 0x0F, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x03,
  0xFC, 0x7E, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x0F, 0xFF, 0xF8,
  0x00, 0x30, 0x0C, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x1F, 0xFF, 0xE0, 0x00, 0x30,
  0x0C, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x01, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFC, 0x07, 0xFF, 0xFE, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFC, 0x0F, 0xFF, 0xFE, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
  0x3F, 0xFF, 0xFC, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF,
  0xFC, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x0F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x07, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x07, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x3F, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x7F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0xF0, 0x1F,
  0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x01, 0xC0, 0x07, 0x07, 0xFF,
  0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x03, 0x80, 0x03, 0x83, 0xFF, 0xFF, 0xFF,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x03, 0x84, 0x01, 0xC7, 0xFF, 0xFF, 0xFF, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x07, 0x1E, 0x01, 0xCF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x07, 0x3E, 0x00, 0xFE, 0x3F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x06, 0xFF, 0x00, 0xF8, 0x1F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x07,
  0xE3, 0x00, 0xE0, 0x0F, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x07, 0xC3, 0x80,
  0xC0, 0x07, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x07, 0x01, 0xC0, 0xC0, 0x03,
  0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x04, 0x01, 0xC0, 0xC0, 0x01, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x01, 0xE1, 0xC0, 0x00, 0xFF, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xC1, 0xC0, 0x00, 0x7F, 0xFC, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x0F, 0x03, 0x80, 0x00, 0x3F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x3E, 0x07, 0x00, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0xF8, 0x0F, 0x00, 0x00, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x7E, 0xFC,
  0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x3F, 0xF8, 0x00, 0x00,
  0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
  0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x1C,
  0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x58, 0x3C, 0x3C, 0x5C, 0x00, 0x16, 0x82, 0x1C, 0x41, 0x00, 0x10, 0x5C,
  0x1E, 0xFE, 0x70, 0x66, 0x66, 0x66, 0x00, 0x22, 0x82, 0x22, 0x63, 0x00, 0x7C, 0x62, 0x23, 0xDA,
  0x70, 0x42, 0x42, 0x42, 0x00, 0x22, 0x92, 0x02, 0x22, 0x00, 0x10, 0x42, 0x41, 0x92, 0x58, 0x7E,
  0x7E, 0x42, 0x00, 0x22, 0xAA, 0x3E, 0x22, 0x00, 0x10, 0x40, 0x41, 0x92, 0x48, 0x40, 0x40, 0x42,
  0x00, 0x7F, 0xAA, 0x42, 0x14, 0x00, 0x10, 0x40, 0x41, 0x92, 0x44, 0x60, 0x60, 0x44, 0x00, 0x41,
  0xAA, 0x46, 0x14, 0x00, 0x10, 0x40, 0x62, 0x92, 0x42, 0x3E, 0x3E, 0x78, 0x00, 0x41, 0xC4, 0x3A,
  0x08, 0x00, 0x10, 0x40, 0x3C, 0x92, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC7, 0x00, 0x00, 0x04, 0x00, 0x04,
  0x20, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x21, 0x00, 0x00, 0x04, 0x00, 0x04, 0x20, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x21, 0x00, 0x00, 0x04, 0x00, 0x04, 0x20, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x04, 0x61, 0x01, 0xC1, 0xE4, 0x60, 0x04, 0x21, 0xE1, 0x03, 0xC3, 0xC0, 0x00,
  0x00, 0x07, 0xC1, 0x02, 0x22, 0x04, 0xC0, 0x07, 0xE2, 0x31, 0x06, 0x64, 0x00, 0x00, 0x00, 0x04,
  0x61, 0x00, 0x24, 0x05, 0x00, 0x04, 0x24, 0x11, 0x04, 0x24, 0x00, 0x00, 0x00, 0x04, 0x21, 0x03,
  0xE4, 0x06, 0x00, 0x04, 0x24, 0x11, 0x07, 0xE3, 0x80, 0x00, 0x00, 0x04, 0x21, 0x04, 0x24, 0x05,
  0x80, 0x04, 0x24, 0x11, 0x04, 0x00, 0x40, 0x00, 0x00, 0x04, 0x61, 0x04, 0x66, 0x04, 0xC0, 0x04,
  0x26, 0x21, 0x06, 0x00, 0x40, 0x00, 0x00, 0x07, 0xC7, 0xE3, 0xA1, 0xE4, 0x60, 0x04, 0x23, 0xC7,
  0xE3, 0xE7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xC5, 0xC1, 0xE0, 0x01, 0xEF, 0xE5, 0xC3, 0xC5, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x26, 0x22, 0x20, 0x02, 0x32, 0x06, 0x26, 0x66, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24,
  0x24, 0x20, 0x04, 0x12, 0x04, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE4, 0x24, 0x20,
  0x04, 0x12, 0x04, 0x27, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x24, 0x24, 0x20, 0x04, 0x12,
  0x04, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x64, 0x26, 0x60, 0x06, 0x23, 0x04, 0x26,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xA4, 0x23, 0xA0, 0x03, 0xC1, 0xE4, 0x23, 0xE4, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x3C, 0x1E, 0x42, 0x5C, 0x1E, 0x3C, 0x3C, 0x00, 0x1E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x40, 0x23,
  0x42, 0x62, 0x20, 0x66, 0x40, 0x00, 0x23, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x40, 0x41, 0x42, 0x42,
  0x40, 0x42, 0x40, 0x00, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x38, 0x41, 0x42, 0x40, 0x40, 0x7E,
  0x38, 0x00, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x04, 0x41, 0x42, 0x40, 0x40, 0x40, 0x04, 0x00,
  0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x04, 0x62, 0x46, 0x40, 0x60, 0x60, 0x04, 0x00, 0x62, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x3C, 0x3A, 0x40, 0x1E, 0x3E, 0x78, 0x00, 0x3C, 0x10, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x30, 0x40, 0x30, 0x70, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x14, 0x00, 0x00, 0x30, 0x40, 0x30, 0x10, 0x00, 0x20, 0x30, 0x00, 0x00, 0x00, 0x00, 0x14,
  0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x5C, 0x5C,
  0x70, 0x5C, 0x70, 0x10, 0x1C, 0xFE, 0x70, 0x1E, 0x5C, 0x00, 0x00, 0x22, 0x62, 0x62, 0x10, 0x62,
  0x10, 0x10, 0x22, 0x20, 0x10, 0x23, 0x62, 0x00, 0x00, 0x22, 0x42, 0x42, 0x10, 0x42, 0x10, 0x10,
  0x02, 0x20, 0x10, 0x41, 0x42, 0x00, 0x00, 0x22, 0x42, 0x42, 0x10, 0x42, 0x10, 0x10, 0x3E, 0x20,
  0x10, 0x41, 0x42, 0x00, 0x00, 0x7F, 0x42, 0x42, 0x10, 0x42, 0x10, 0x10, 0x42, 0x20, 0x10, 0x41,
  0x42, 0x00, 0x00, 0x41, 0x42, 0x42, 0x10, 0x42, 0x10, 0x10, 0x46, 0x30, 0x10, 0x62, 0x42, 0x00,
  0x00, 0x41, 0x42, 0x42, 0x7E, 0x42, 0x7E, 0x7E, 0x3A, 0x1E, 0x7E, 0x3C, 0x42, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0F, 0x1E, 0x78, 0xE1, 0x37, 0xE3, 0xC7, 0x96, 0x00, 0x3C, 0x7B, 0xF8, 0x00, 0x00, 0x10,
  0x33, 0x64, 0x21, 0x61, 0x04, 0x2C, 0x19, 0x00, 0x60, 0xCF, 0x68, 0x00, 0x00, 0x1C, 0x21, 0x44,
  0x21, 0x81, 0x07, 0xE8, 0x11, 0x00, 0x40, 0x86, 0x48, 0x00, 0x00, 0x03, 0x21, 0x44, 0x21, 0x41,
  0x04, 0x08, 0x11, 0x00, 0x40, 0x86, 0x48, 0x00, 0x00, 0x01, 0x33, 0x44, 0x21, 0x21, 0x06, 0x0C,
  0x11, 0x18, 0x60, 0xCE, 0x48, 0x00, 0x00, 0x1E, 0x1E, 0x44, 0xF9, 0x11, 0xE3, 0xE7, 0x91, 0x18,
  0x3C, 0x7A, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

EPD215::EPD215( uint32_t cs, uint32_t dc, uint32_t rs, uint32_t bs, int32_t d0, int32_t d1 ) {
  _cs = cs;
  _dc = dc;
  _rs = rs;
  _bs = bs;
  _d0 = d0;
  _d1 = d1;
}

void EPD215::softwareSpi( uint8_t data ) {
  for ( int i = 0; i < 8; i++ ) {
    if ((( data >> (7 - i) ) & 0x01 ) == 1 ) digitalWrite( _d1, HIGH );
    else digitalWrite( _d1, LOW );
    digitalWrite( _d0, HIGH );
    digitalWrite( _d0, LOW );
  }
}


void EPD215::clearScreen() {
  for ( int i = 0; i < 2912; i++ ) _buffer[ i ] = 0x00;
}

void EPD215::writeToBuffer( uint8_t *buf ) {
  for ( int i = 0; i < 2912; i++ ) _buffer[ i ] = buf[ i ];
}

void EPD215::initScreen() {
  if ( _d0 == 0xFF ) _spiMode = 1;
  if ( _spiMode ) {
    Serial.print( "Beginning SPI" );
    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  }
  else {
    Serial.print( "Beginning Software SPI" );
    pinMode( _d0, OUTPUT );
    pinMode( _d1, OUTPUT );
  }
  pinMode( _cs, OUTPUT );
  pinMode( _dc, OUTPUT );
  pinMode( _rs, OUTPUT );
  pinMode( _bs, INPUT_PULLUP );
  Serial.print( "Resetting screen" );
  digitalWrite( _rs, HIGH );        //RES# = 1
  delay( 1 );                       //Delay 1ms
  digitalWrite( _cs, HIGH );        //CS# = 1
  Serial.print( "waiting for busy signal" );
  while ( digitalRead( _bs ) == HIGH ); //Make sure BUSY = LOW
}

void EPD215::updateScreen() {
  uint8_t data1[] = { 0xCF, 0x00 };
  _sendIndexData( 0x01, data1, 2 );     //Driver output control setting
  uint8_t data2[] = { 0x00 };
  _sendIndexData( 0x0F, data2, 1 );     //Gate scan start setting
  uint8_t data3[] = { 0x03 };
  _sendIndexData( 0x11, data3, 1 );     //Data entry mode setting
  uint8_t data4[] = { 0x00, 0x0D };
  _sendIndexData( 0x44, data4, 2 );     //Set RAM X - Start-End position
  uint8_t data5[] = { 0x00, 0xCF };
  _sendIndexData( 0x45, data5, 2 );     //Set RAM Y - Start-End position
  uint8_t data6[] = { 0x00 };
  _sendIndexData( 0x4E, data6, 1 );     //Set RAM X address counter
  uint8_t data7[] = { 0x00 };
  _sendIndexData( 0x4F, data7, 1 );     //Set RAM Y address counter
  uint8_t data8[] = { 0x80 };
  _sendIndexData( 0x3C, data8, 1 );     //Select border waveform
  uint8_t data9[] = { 0x10, 0x0A };
  _sendIndexData( 0x03, data9, 2 );    //Set gate driving voltage
  uint8_t data10[] = { 0x00 };
  _sendIndexData( 0x05, data10, 1 );    //Normal analog mode
  uint8_t data11[] = { 0x00, 0x00, 0x00 };
  _sendIndexData( 0x75, data11, 3 );    //Normal analog mode
  //Send Image Data
  _sendIndexData( 0x24, _buffer, 2912 );
  //Update command sequence
  while ( digitalRead( _bs ) == HIGH ); //Make sure BUSY = LOW
  uint8_t data12[] = { 0x19, 0x00 };
  //uint8_t data12[] = { 0x00, 0x00 };
  _sendIndexData( 0x1A, data12, 2 );    //Send the temperature value
  uint8_t data13[] = { 0xF7 };
  _sendIndexData( 0x22, data13, 1 );    //Set update sequence
  uint8_t data14[] = { 0x00 };
  _sendIndexData( 0x20, data14, 1 );    //Active display update sequence
  while ( digitalRead( _bs ) == HIGH ); //Make sure BUSY = LOW
}

void EPD215::_sendIndexData( uint8_t index, uint8_t *data, int len ) {
  digitalWrite( _cs, LOW );      //CS Low
  digitalWrite( _dc, LOW );      //DC Low
  delay(1);
  if ( _spiMode ) SPI.transfer( index );         //SPI Send Index
  else softwareSpi( index );
  delay(1);
  digitalWrite( _dc, HIGH );     //DC High
  delay(1);
  for ( int i = 0; i < len; i++ ) {
    if ( _spiMode ) SPI.transfer( data[ i ] ); //SPI Send Data
    else softwareSpi( data[ i ] );
  }
  delay(1);
  digitalWrite( _cs, HIGH );     //CS High
}

void EPD215::drawPixel( int x, int y, uint32_t color ) { //drawPixel function cribbed from adafruit gfx library
  if (( x < 0 ) || ( y < 0 ) || ( x >= WIDTH ) || ( y >= HEIGHT )) return;
  uint32_t t;
  switch ( _rotation ) {
    case 1:
      t = x;
      x = WIDTH  - 1 - y;
      y = t;
      break;
    case 2:
      x = WIDTH  - 1 - x;
      y = HEIGHT - 1 - y;
      break;
    case 3:
      t = x;
      x = y;
      y = HEIGHT - 1 - t;
      break;
  }
  uint8_t *ptr = &_buffer[( x / 8 ) + y * (( WIDTH + 7 ) / 8 )];
  if ( color ) *ptr |= 0x80 >> ( x & 7 );
  else         *ptr &= ~( 0x80 ) >> ( x & 7 );
}

void EPD215::_placeChar( char c ) {
  uint32_t offset = ( int( c ) - 32 );
  uint32_t charWidth = fontDescriptors[ offset ][ 0 ];
  uint32_t charHeight = fontDescriptors[ offset ][ 1 ];
  uint32_t charOffset = fontDescriptors[ offset ][ 2 ];
  if ( charWidth < WIDTH ) {
    if (_cursorX > ( WIDTH - charWidth )) {
      _cursorY += charHeight;
      _cursorX = 0;
    }
  }
  if ( _cursorY > ( HEIGHT - charHeight )) _cursorY = 0;
  for ( uint32_t i = 0; i < charHeight; i++ ) {
    uint32_t charData;
    if ( charWidth > 24 ) charData = ( fontBitmaps[ charOffset + ( i * 4 ) ] << 24 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 1 ] << 16 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 2 ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 3 ] );
    else if ( charWidth > 16 ) charData = ( fontBitmaps[ charOffset + ( i * 3 ) ] << 16 ) | ( fontBitmaps[ charOffset + ( i * 3 ) + 1 ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 3 ) + 2 ] );
    else if ( charWidth > 8 ) charData = ( fontBitmaps[ charOffset + ( i * 2 ) ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 2 ) + 1 ] );
    else charData = fontBitmaps[ charOffset + i ] << 8;
    for ( uint32_t j = 0; j < ( charWidth + 1 ); j++ ) {
      uint32_t point;
      if ( charWidth > 24 ) point = ( charData << j ) & 0x80000000;
      else if ( charWidth > 16 ) point = ( charData << j ) & 0x800000;
      else if ( charWidth > 8 ) point = ( charData << j ) & 0x8000;
      else point = ( charData << j ) & 0x8000;
      drawPixel( _cursorX + j, _cursorY + i, point );
    }
  }
  _cursorX += charWidth + SPACING;
}

void EPD215::_placeChar( char c, int y ) {
  uint32_t offset = ( int( c ) - 32 );
  uint32_t charWidth = fontDescriptors[ offset ][ 0 ];
  uint32_t charHeight = fontDescriptors[ offset ][ 1 ];
  uint32_t charOffset = fontDescriptors[ offset ][ 2 ];
  if ( charWidth < WIDTH ) {
    if (_cursorX > ( WIDTH - charWidth )) {
      _cursorY += charHeight;
      _cursorX = 0;
    }
  }
  if ( _cursorY > ( HEIGHT - charHeight )) _cursorY = 0;
  for ( uint32_t i = 0; i < charHeight; i++ ) {
    uint32_t charData;
    if ( charWidth > 24 ) charData = ( fontBitmaps[ charOffset + ( i * 4 ) ] << 24 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 1 ] << 16 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 2 ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 4 ) + 3 ] );
    else if ( charWidth > 16 ) charData = ( fontBitmaps[ charOffset + ( i * 3 ) ] << 16 ) | ( fontBitmaps[ charOffset + ( i * 3 ) + 1 ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 3 ) + 2 ] );
    else if ( charWidth > 8 ) charData = ( fontBitmaps[ charOffset + ( i * 2 ) ] << 8 ) | ( fontBitmaps[ charOffset + ( i * 2 ) + 1 ] );
    else charData = fontBitmaps[ charOffset + i ] << 8;
    for ( uint32_t j = 0; j < ( charWidth + 1 ); j++ ) {
      uint32_t point;
      if ( charWidth > 24 ) point = ( charData << j ) & 0x80000000;
      else if ( charWidth > 16 ) point = ( charData << j ) & 0x800000;
      else if ( charWidth > 8 ) point = ( charData << j ) & 0x8000;
      else point = ( charData << j ) & 0x8000;
      drawPixel( _cursorX + j, _cursorY + i + ( y - charHeight ), point );
    }
  }
  _cursorX += charWidth + SPACING;
}

void EPD215::placeStringAt( String s, int x, int y ) {
  _cursorX = x;
  _cursorY = y;
  uint32_t offset;
  uint32_t neededVerticalSpace = 0;
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    offset = ( uint32_t( s.charAt( i ) ) - 32 );
    uint32_t maxHeight = ( fontDescriptors[ offset ][ 1 ] );
    if ( maxHeight > neededVerticalSpace ) neededVerticalSpace = maxHeight;
  }
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    _placeChar( s[ i ] , neededVerticalSpace );
  }
}

void EPD215::placeCenteredStringAt( String s, int y ) {
  _cursorY = y;
  uint32_t offset;
  uint32_t neededTotalSpace = 0;
  uint32_t neededVerticalSpace = 0;
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    offset = ( uint32_t( s.charAt( i ) ) - 32 );
    neededTotalSpace += ( fontDescriptors[ offset ][ 0 ] + SPACING );
    uint32_t maxHeight = ( fontDescriptors[ offset ][ 1 ] );
    if ( maxHeight > neededVerticalSpace ) neededVerticalSpace = maxHeight;
  }
  _cursorX = ( WIDTH - neededTotalSpace ) / 2;
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    _placeChar( s[ i ] , neededVerticalSpace );
  }
}

void EPD215::placeRightStringAt( String s, int y ) {
  _cursorY = y;
  uint32_t offset;
  uint32_t neededTotalSpace = 0;
  uint32_t neededVerticalSpace = 0;
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    offset = ( uint32_t( s.charAt( i ) ) - 32 );
    neededTotalSpace += ( fontDescriptors[ offset ][ 0 ] + SPACING );
    uint32_t maxHeight = ( fontDescriptors[ offset ][ 1 ] );
    if ( maxHeight > neededVerticalSpace ) neededVerticalSpace = maxHeight;
  }
  _cursorX = WIDTH - neededTotalSpace;
  for ( uint32_t i = 0; i < s.length(); i++ ) {
    _placeChar( s[ i ] , neededVerticalSpace );
  }
}