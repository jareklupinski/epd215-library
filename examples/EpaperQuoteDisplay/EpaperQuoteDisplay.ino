#include <EPD215.h>       //include the epaper library
#include "quotes.h"       //include the quotes to be displayed

#define ROTATE_DELAY 30    //number of minutes to display a quote before changing to the next on

EPD215 epaper( 4, 5, 6, 7, 13, 11 );            //initialize the epaper object

void setup() {            //setup function runs once on startup
  Serial.begin( 115200 ); //begin a Serial link in case we need troubleshooting
  delay( 2000 );          //wait one second
  epaper.initScreen();    //initialize the epaper hardware
  epaper.updateScreen();  //update the screen with whatever is in the buffer
  randomSeed( analogRead(A0) );
}

void loop() {                                                           //loop function runs forever until power is removed
  int quoteIndex = random( sizeof( quoteArray ) / 4 );                //get a random quote number
  epaper.clearScreen();                                               //clear the screen
  String quoteString = String( quoteArray[ quoteIndex ] );                     //get the quote from the array and save it as a String
  Serial.println( quoteString );                                      //print the String out over Serial for troubleshooting
  int delimiterIndex = quoteString.lastIndexOf( ';' );                //find where the quote test ends and the quote author begins
  String textString = quoteString.substring( 0, delimiterIndex );     //store the text of the quote in textString
  String authorString = quoteString.substring( delimiterIndex + 1 );  //store the attributed source of the quote in quoteString
  epaper.placeStringAt( textString, 0, 0 );                           //write the text of the string to the e-paper screen buffer
  epaper.placeStringAt( authorString, 0, 170 );                       //write the attributed source of the string to the e-paper screen buffer
  epaper.updateScreen();                                              //update the epaper screen with what is in the buffer
  delay( ROTATE_DELAY * 60000 );                                      //wait ROTATE_DELAY minutes before continuing
}
