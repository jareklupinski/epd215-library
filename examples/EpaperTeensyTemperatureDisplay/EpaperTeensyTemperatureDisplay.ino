#include <Adafruit_GFX.h> // include the base Adafruit Graphics library
#include <EPD215.h>       // include the epaper display driver library
#include <Wire.h>         // include the temperature sensor protocol driver library

#define TMP102_I2C_ADDRESS 0x49 // I2C address for our temperature chip

// initialize epaper with pin numbers for cs, dc, rs, bs, d0, d1 for software SPI
//EPD215 epaper( 17, 16, 15, 14, 13, 11 );
// initialize epaper with pin numbers for cs, dc, rs, bs for hardware SPI
EPD215 epaper( 17, 16, 15, 14 );

float temperature;
float temperatureHigh;
float temperatureLow;

void getTemperature() { //get temperature from temperature sensor
  Wire.beginTransmission( TMP102_I2C_ADDRESS ); // for more details on how to read the temperature from this sensor
  Wire.write( 0x00 );                           // please refer to the device datasheet: 
  Wire.endTransmission();                       // http://www.ti.com.cn/cn/lit/ds/symlink/tmp102.pdf
  Wire.requestFrom( TMP102_I2C_ADDRESS, 2 );
  Wire.endTransmission();
  int val = Wire.read() << 4;
  val |= Wire.read() >> 4;
  //temperature = (((( val * 0.0625 ) - 5 ) * 9 ) / 5 ) + 32; // Farenheit
  temperature = ( val * 0.0625 ) - 5; // Celsius
  if ( temperature > temperatureHigh ) temperatureHigh = temperature;
  if ( temperature < temperatureLow ) temperatureLow = temperature;
}

String parseTemperature( float t ) { // convert temperature value to String
  String s;
  if ( t > 100 ) s = String( t / 100 );
  s += String(int( t / 10 ) % 10 );
  s += String(int( t ) % 10 );
  s += ".";
  s += String(int( t * 10 ) % 10 );
  return s;
}

void setup() {                   // setup function runs once on startup
  Wire.begin();                  // start the I2C driver
  epaper.initScreen();           // initialize the epaper hardware
  epaper.updateScreen();         // update the screen with whatever is in the buffer
  getTemperature();              // get the latest temperature
  temperatureHigh = temperature; // initialize the high and low temperatures
  temperatureLow = temperature;
}

void loop() {                    // loop function runs forever until power is removed
  getTemperature();
  epaper.clearScreen();          // clear the screen buffer
  epaper.setCursor( 0, 0 );      // reset the cursor position
  epaper.println( String( "Current: " ) + parseTemperature( temperature ) + "C" );     // write the current temperature to the epaper screen buffer
  epaper.println( String( "Highest: " ) + parseTemperature( temperatureHigh ) + "C" ); // write the highest recorded temperature to the epaper screen buffer
  epaper.println( String( "Lowest : " ) + parseTemperature( temperatureLow ) + "C" );  // write the lowest recorded temperature to the epaper screen buffer
  epaper.updateScreen( temperature );                    // update the epaper screen with the buffer contents, passing the current temperature to the epaper screen
  delay( 30000 );                // wait 30 seconds before taking the next measurement
}