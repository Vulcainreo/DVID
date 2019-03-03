#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>


Adafruit_SSD1306 display(-1);
String password = "1234";
String currentPassword = "";
bool finished = false;
String rx = "";
bool first = true;

void printScreen(String text, String progress) {

  // Clear the buffer.
  display.clearDisplay();

  display.setCursor(0,0);
  //               xxxxxxxxxxxxxxxxxxxxx
  display.println("T01 Hard.Pass.   "+progress+"%"); //first line - only 21 chars
  display.drawLine(0,7,120,7,WHITE);

  display.setCursor(0,8);
  display.println(text);

  display.display();
}

void setup()   
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  } 
  
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  currentPassword = "";
  
 // Display Text
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  
  printScreen("A useful information is hardcoded, Find it to unlock", "  0");

  while(!finished) {
    
    if (currentPassword != password) {
     
      if (!first) {
        printScreen("Wrong password\nTry again", " 50");
        currentPassword = "";
      }
          
      
      if (Serial.available() > 0) {
               
        rx = Serial.readString();
        currentPassword = currentPassword + rx;
        currentPassword.trim();
        printScreen("Pass : "+currentPassword, " 50");
        first = false;
        delay(2000);
      }
    }
    else
    {
      printScreen("Well done ! Challenge unlocked","100");
      finished = true;
    }

  
  }

}

void loop() {}
