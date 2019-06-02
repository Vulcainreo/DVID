#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <SoftwareSerial.h>


Adafruit_SSD1306 display(-1);
SoftwareSerial ble(7,6);
SoftwareSerial wifi(2,3);

void printScreen(String text, String progress) {

  // Clear the buffer.
  display.clearDisplay();

  display.setCursor(0,0);
  //               xxxxxxxxxxxxxxxxx"+progress+"x
  display.println("TESTING......... "+progress+"%"); //first line - only 21 chars
  display.drawLine(0,7,120,7,WHITE);

  display.setCursor(0,8);
  display.println(text);

  display.display();
}

void setup()
{
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

 // Display Text
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Testing screen
  printScreen("Printing on screen" ," 30");

  // Testing BLE
  ble.begin(9600);

  ble.println("AT+ROLE0");
  ble.println("AT+UUID0xFFE0");
  ble.println("AT+CHAR0xFFE1");
  ble.println("AT+NAMEDVID-TESTING");
  ble.println("AT+RESET");

  printScreen("Testing BLE", "  60");

  // Testing Wifi
  wifi.begin(115200);

  wifi.println("AT");
  printScreen(wifi.readString(),"");
}

void loop() {}
