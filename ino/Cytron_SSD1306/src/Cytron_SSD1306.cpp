/*********************************************************************
This is a library for Monochrome OLEDs based on SSD1306 drivers for I2C 
communication only.

Modified from Adafruit SSD1306 Library


The original library is Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen below must be included in any redistribution
*********************************************************************/

#ifdef __AVR__
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#else
 #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif

// #if !defined(__ARM_ARCH) && !defined(ENERGIA) && !defined(ESP8266)
//  #include <util/delay.h>
// #endif

//#include <stdlib.h>

#include "Cytron_SSD1306.h"

Cytron_SSD1306::Cytron_SSD1306():SSD1306Ascii(){
}

void Cytron_SSD1306::invertDisplay(uint8_t i) {
  if (i) {
    ssd1306WriteCmd(SSD1306_INVERTDISPLAY);
  } else {
    ssd1306WriteCmd(SSD1306_NORMALDISPLAY);
  }
}

// startscrollright
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void Cytron_SSD1306::startscrollright(uint8_t start, uint8_t stop){
  ssd1306WriteCmd(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(start);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(stop);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(0XFF);
  ssd1306WriteCmd(SSD1306_ACTIVATE_SCROLL);
}

// startscrollleft
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void Cytron_SSD1306::startscrollleft(uint8_t start, uint8_t stop){
  ssd1306WriteCmd(SSD1306_LEFT_HORIZONTAL_SCROLL);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(start);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(stop);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(0XFF);
  ssd1306WriteCmd(SSD1306_ACTIVATE_SCROLL);
}

// startscrolldiagright
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void Cytron_SSD1306::startscrolldiagright(uint8_t start, uint8_t stop){
  ssd1306WriteCmd(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(SSD1306_LCDHEIGHT);
  ssd1306WriteCmd(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(start);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(stop);
  ssd1306WriteCmd(0X01);
  ssd1306WriteCmd(SSD1306_ACTIVATE_SCROLL);
}

// startscrolldiagleft
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void Cytron_SSD1306::startscrolldiagleft(uint8_t start, uint8_t stop){
  ssd1306WriteCmd(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(SSD1306_LCDHEIGHT);
  ssd1306WriteCmd(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(start);
  ssd1306WriteCmd(0X00);
  ssd1306WriteCmd(stop);
  ssd1306WriteCmd(0X01);
  ssd1306WriteCmd(SSD1306_ACTIVATE_SCROLL);
}

void Cytron_SSD1306::stopscroll(void){
  ssd1306WriteCmd(SSD1306_DEACTIVATE_SCROLL);
}

// Dim the display
// dim = true: display is dimmed
// dim = false: display is normal
void Cytron_SSD1306::dim(boolean dim) {
  uint8_t contrast;

  if (dim) {
    contrast = 0; // Dimmed display
  } else {
    contrast = 0xCF;
  }
  // the range of contrast to too small to be really useful
  // it is useful to dim the display
  ssd1306WriteCmd(SSD1306_SETCONTRAST);
  ssd1306WriteCmd(contrast);
}

void Cytron_SSD1306::drawBitmap(int16_t x, int16_t y,
 const uint8_t *bitmap, int16_t w, int16_t h, uint8_t color) {

  int16_t i, j;
  int16_t y_start = y >> 3; //divided by 8
  uint8_t row; 

  if (h%8==0) {
    row=h/8;//row from 0 to 7 
  }
  
  else{
    row=h/8+1;//Quotient+1
  }

  for(j = 0 ; j < row; j++){

    setCursor(x, y_start);
    
    for(i = 0; i < w; i++) {  
      
      ssd1306WriteRamBuf(pgm_read_byte(bitmap + i + j * w));

      if((w*h/8 - 1) == (i + j * w)) return; //if pixels are enough

    }

    y_start++;

  }
  setCursor(x, y_start);

  // for(int idx = 0; idx < w*h/8; idx++){
  //   if(idx%w==0) println();
  //   ssd1306WriteRamBuf(pgm_read_byte(bitmap + idx));
  // }
}

/*void Cytron_SSD1306::drawPixel(int16_t x, int16_t y, uint16_t color) {
  // Bitmask tables of 0x80>>X and ~(0x80>>X), because X>>Y is slow on AVR
  static const uint8_t PROGMEM
    GFXsetBit[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 },
    GFXclrBit[] = { 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE };

    if((x < 0) || (y < 0) || (x >= _width) || (y >= _height)) return;

    //find out which row is the value of y
    cursor_x = x;
    cursor_y = y/(_width/8);
    setCursor(cursor_x, cursor_y);

    uint8_t *ptr = &buffer[(x / 8) + y * ((_width + 7) / 8)];
    if(color) *ptr |= pgm_read_byte(&GFXsetBit[x & 7]);
    else      *ptr &= pgm_read_byte(&GFXclrBit[x & 7]);
  }
}*/

