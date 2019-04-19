#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <SoftwareSerial.h>


Adafruit_SSD1306 display(-1);
String password = "abcd";
String currentPassword = "";
bool finished = false;
String rx = "";
bool first = true;
SoftwareSerial ble(7,6);

void printScreen(String text, String progress) {

  // Clear the buffer.
  display.clearDisplay();

  display.setCursor(0,0);
  //               xxxxxxxxxxxxxxxxx"+progress+"x
  display.println("T01 BLE.Charact. "+progress+"%"); //first line - only 21 chars
  display.drawLine(0,7,120,7,WHITE);

  display.setCursor(0,8);
  display.println(text);

  display.display();
}

void setup()
{
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  currentPassword = "";

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

 // Display Text
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // BLE
  ble.begin(9600);

  ble.println("AT+ROLE0");
  ble.println("AT+UUID0xFFE0");
  ble.println("AT+CHAR0xFFE1");
  ble.println("AT+NAMEDVID-TAA");
  ble.println("AT+RESET");
  ble.println("not here");

  delay(3000);
  // flush ble buffer after configuration setup
  ble.flush();

  printScreen("Send abcd to board throught BLE to unlock", "  0");

  while(!finished) {

    if (currentPassword != password) {

      if (!first) {
        printScreen("Wrong password\nTry again", " 50");
        currentPassword = "";
      }
      rx = ble.readString();
      if (rx != "") {
        currentPassword = currentPassword + rx;
        currentPassword.trim();
        printScreen("Entered pass : "+currentPassword, " 50");
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
