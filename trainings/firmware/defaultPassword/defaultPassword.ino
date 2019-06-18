#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>


#define DVID_logo_width 128
#define DVID_logo_height 64

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(OLED_RESET);

String password = "password";
String message = "R5azzbhz4bf23isccbts1111";
String currentPassword = "";
bool finished = false;
String rx = "";
bool first = true;

void printScreen(String text, String progress) {

  // Clear the buffer.
  display.clearDisplay();

  display.setCursor(0,0);
  //               xxxxxxxxxxxxxxxxx     xxxx
  display.println("T04 Default.Pass."+progress+"%"); //first line - only 21 chars
  display.drawLine(0,7,128,7,WHITE);

  display.setCursor(0,10);
  display.println(text);

  display.display();
}

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  currentPassword = "";

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

 // Display Text
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  String m = String(message[0])+String(message[2])+String(message[5])+String(message[9])+String(message[13])+String(message[18])+String(message[19]);
  printScreen("I have confidential message. Pass ?", "  0");

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
        Serial.println("ko");
        delay(2000);
      }
    }
    else
    {
      Serial.println("ok");
      printScreen("Well done! Message : "+m,"100");
      finished = true;
    }


  }

}

void loop() {}
