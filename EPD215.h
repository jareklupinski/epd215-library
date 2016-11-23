#ifndef _EPD215_H_
#define _EPD215_H_
#include <SPI.h>

extern const uint8_t fontBitmaps[];
extern const uint32_t fontDescriptors[][3];
	
class EPD215 {
  public:
    EPD215( uint32_t cs, uint32_t dc, uint32_t rs, uint32_t bs, int32_t d0 = 0xFF, int32_t d1 = 0xFF );
    void initScreen();
    void updateScreen();
    void clearScreen();
    void drawPixel( int x, int y, uint32_t color );
    void placeStringAt( String s, int x, int y );
    void placeCenteredStringAt( String s, int y );
    void placeRightStringAt( String s, int y );
    void writeToBuffer( uint8_t *buf );
    void softwareSpi( uint8_t data );
	
  private:
    uint32_t _d0;
    uint32_t _d1;
    uint32_t _cs;
    uint32_t _dc;
    uint32_t _rs;
    uint32_t _bs;
    uint8_t _spiMode = 0; // 0 = softwareSpi, 1 = hardwareSpi
    uint8_t _rotation = 0;
    uint8_t _cursorX;
    uint8_t _cursorY;
    void _placeChar( char c );
    void _placeChar( char c, int y );
    void _sendIndexData( uint8_t index, uint8_t *data, int len );
    uint8_t _bitReverse( uint8_t x );
};

#endif /* _EPD215_H_ */