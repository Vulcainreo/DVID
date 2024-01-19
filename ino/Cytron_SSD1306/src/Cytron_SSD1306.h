/*********************************************************************
This is a library for Monochrome OLEDs based on SSD1306 drivers for I2C 
communication only.

Modified from Adafruit SSD1306 Library


The original library is Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen below must be included in any redistribution
*********************************************************************/
#ifndef _CYTRON_SSD1306_H_
#define _CYTRON_SSD1306_H_

#include "utility/AvrI2c.h"
#include <SSD1306Ascii.h>

/*#if ARDUINO >= 100
 #include "Arduino.h"
 #define WIRE_WRITE Wire.write
#else
 #include "WProgram.h"
  #define WIRE_WRITE Wire.send
#endif

#if defined(__SAM3X8E__)
 typedef volatile RwReg PortReg;
 typedef uint32_t PortMask;
 #define HAVE_PORTREG
#elif defined(ARDUINO_ARCH_SAMD)
// not supported
#elif defined(ESP8266) || defined(ARDUINO_STM32_FEATHER)
  typedef volatile uint32_t PortReg;
  typedef uint32_t PortMask;
#else
  typedef volatile uint8_t PortReg;
  typedef uint8_t PortMask;
 #define HAVE_PORTREG
#endif

#ifdef __AVR__
 #include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#endif
//#include "Adafruit_GFX.h"
#include "glcdfont.c"
#include "ArialMT_Plain.h"
#include <Print.h>
*/

// Many (but maybe not all) non-AVR board installs define macros
// for compatibility with existing PROGMEM-reading AVR code.
// Do our own checks and defines here for good measure...
/*
#ifndef pgm_read_byte
 #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
 #define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
 #define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif
*/
// Pointers are a peculiar case...typically 16-bit on AVR boards,
// 32 bits elsewhere.  Try to accommodate both...
/*
#if !defined(__INT_MAX__) || (__INT_MAX__ > 0xFFFF)
 #define pgm_read_pointer(addr) ((void *)pgm_read_dword(addr))
#else
 #define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif
*/
//#define BLACK 0
//#define WHITE 1
//#define INVERSE 2
#define NORMAL 0
#define INVERTED 1

#define SSD1306_I2C_ADDRESS   0x3C  // 011110+SA0+RW - 0x3C or 0x3D
// Address for 128x32 is 0x3C
// Address for 128x64 is 0x3D (default) or 0x3C (if SA0 is grounded)

/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.

    SSD1306_128_64  128x64 pixel display

    SSD1306_128_32  128x32 pixel display

    SSD1306_96_16

    -----------------------------------------------------------------------*/
   #define SSD1306_128_64
//   #define SSD1306_128_32
//   #define SSD1306_96_16
/*=========================================================================*/

#if defined SSD1306_128_64 && defined SSD1306_128_32
  #error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32 && !defined SSD1306_96_16
  #error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 64
#endif
// #if defined SSD1306_128_32
//   #define SSD1306_LCDWIDTH                  128
//   #define SSD1306_LCDHEIGHT                 32
// #endif
// #if defined SSD1306_96_16
//   #define SSD1306_LCDWIDTH                  96
//   #define SSD1306_LCDHEIGHT                 16
// #endif
/*
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2
*/
// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A


class Cytron_SSD1306 : public SSD1306Ascii {
 public:
  Cytron_SSD1306();

  /**
   * @brief Initialize the display controller.
   *
   * @param[in] dev A device initialization structure.
   * @param[in] i2cAddr The I2C address of the display controller.
   * @param[in] fastMode Fast 400 kHz mode if true else standard 100 kHz mode.
   */
  void begin(const DevType* dev = &Adafruit128x64, uint8_t i2cAddr = SSD1306_I2C_ADDRESS, bool fastMode = true) {
    m_nData = 0;
    m_i2cAddr = i2cAddr;

    m_i2c.begin(fastMode);
    init(dev);

    //default font is System5x7
    setFont(System5x7);
  }

  void invertDisplay(uint8_t i);

  void startscrollright(uint8_t start, uint8_t stop);
  void startscrollleft(uint8_t start, uint8_t stop);

  void startscrolldiagright(uint8_t start, uint8_t stop);
  void startscrolldiagleft(uint8_t start, uint8_t stop);
  void stopscroll(void);

  void dim(boolean dim);

  void drawPixel(int16_t x, int16_t y, uint16_t color);

  void writeByte(const uint8_t byte, uint8_t color=NORMAL);
  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, 
                  uint8_t color=NORMAL);
  void drawBitmap(int16_t x, int16_t y, const char *bitmap, int16_t w, int16_t h, 
                  uint8_t color=NORMAL){
                    drawBitmap(x, y, (const uint8_t *)bitmap, w, h, color);
                  }
  
protected:
  void writeDisplay(uint8_t b, uint8_t mode) {
    if ((m_nData && mode == SSD1306_MODE_CMD)) {
      m_i2c.stop();
      m_nData = 0;
    }
    if (m_nData == 0) {
      m_i2c.start((m_i2cAddr << 1) | I2C_WRITE);
      m_i2c.write(mode == SSD1306_MODE_CMD ? 0X00 : 0X40);
    }
    m_i2c.write(b);
    if (mode == SSD1306_MODE_RAM_BUF) {
      m_nData++; 
    }else {      
      m_i2c.stop();
      m_nData = 0;
    }
  }

private:
  AvrI2c m_i2c;
  uint8_t m_i2cAddr;
  uint8_t m_nData;
  
};

#endif /* _CYTRON_SSD1306_H_ */
