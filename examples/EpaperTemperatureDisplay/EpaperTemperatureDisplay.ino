#include "font.h"       //include the custom font
#include <Wire.h>
#include <EPD215.h>       //include the epaper library
#define TMP102_I2C_ADDRESS 0x49 // This is the I2C address for our chip.
EPD215 epaper( 4, 5, 6, 7, 13, 11 );

float temperature;
float temperatureHigh;
float temperatureLow;

void getTemperature() {
  Wire.beginTransmission( TMP102_I2C_ADDRESS );
  Wire.write( 0x00 );
  Wire.endTransmission();
  Wire.requestFrom( TMP102_I2C_ADDRESS, 2 );
  Wire.endTransmission();
  int val = Wire.read() << 4;
  val |= Wire.read() >> 4;
  //temperature = (((( val * 0.0625 ) - 5 ) * 9 ) / 5 ) + 32; // Farenheit
  temperature = ( val * 0.0625 ) - 5; // Celsius
  if ( temperature > temperatureHigh ) temperatureHigh = temperature;
  if ( temperature < temperatureLow ) temperatureLow = temperature;
}

String parseTemperature( float t ) {
  String s;
  if ( t > 100 ) s = String( t / 100 );
  s += String(int( t / 10 ) % 10 );
  s += String(int( t ) % 10 );
  s += ".";
  s += String(int( t * 10 ) % 10 );
  return s;
}

void setup() {            //setup function runs once on startup
  Wire.begin();           //start the I2C library
  epaper.initScreen();    //initialize the epaper hardware
  epaper.updateScreen();  //update the screen with whatever is in the buffer
  getTemperature();
  temperatureHigh = temperature;
  temperatureLow = temperature;
}

void loop() {                                                           //loop function runs forever until power is removed
  getTemperature();
  epaper.clearScreen();                                               //clear the screen
  epaper.placeRightStringAt( parseTemperature( temperature ), 6 );                           //write the text of the string to the e-paper screen buffer
  epaper.placeRightStringAt( parseTemperature( temperatureHigh ), 82 );                           //write the text of the string to the e-paper screen buffer
  epaper.placeRightStringAt( parseTemperature( temperatureLow ), 156 );                           //write the text of the string to the e-paper screen buffer
  epaper.updateScreen();                                              //update the epaper screen with what is in the buffer
  //delay( 30000 );
}