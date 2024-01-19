#include "image.h"
#include <Cytron_SSD1306.h>

Cytron_SSD1306 oled;

void setup()   {                
  Serial.begin(9600);

  // initialize oled with default setting I2C addr 0x3C and screen 128x64
  oled.begin();  

  // Clear the buffer.
  oled.clear();

  // Display "hello world" at every row

  String text = "Hello, world!";

  //oled a text at second row
  for(int row = 0; row < 8; row++){
    oled.setCursor(10, row);
    oled.print(text + " " + String(row + 1));
  }
  delay(2000);

  //draw Bitmap Cytron Logo starting from x=0, row=0
  oled.clear();
  oled.drawBitmap(0, 0, espert_logo, 128, 64);
  delay(1000);
  
  // invert the display
  oled.invertDisplay(true);
  delay(1000); 
  oled.invertDisplay(false);
  delay(1000);
 
  oled.clear();

  //Set Font type TimesNewRoman
  oled.setFont(TimesNewRoman16);
  
  oled.print("Hello world");

  //scrolling animation
  scroll();
}


void loop() {
  
}

void scroll(void) {
  oled.startscrollright(0x00, 0x0F);
  delay(2000);
  oled.stopscroll();
  delay(1000);
  oled.startscrollleft(0x00, 0x0F);
  delay(2000);
  oled.stopscroll();
  delay(1000);    
  oled.startscrolldiagright(0x00, 0x07);
  delay(2000);
  oled.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  oled.stopscroll();
}
