#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Cytron_SSD1306.h>
#include <EEPROM.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Cytron_SSD1306 display;

void setup() {

  display.begin();
  display.clear();

  display.println("Hello ...");

  Serial.begin(9600);
}

void loop() {
    Serial.write("Hello\r\n");



    EEPROM.write(100, 80);
    delay(3000);
    EEPROM.write(100, 65);
    delay(3000);
    EEPROM.write(100, 83);
    delay(3000);
    EEPROM.write(100, 83);
    delay(3000);
    EEPROM.write(100, 87);
    delay(3000);
    EEPROM.write(100, 79);
    delay(3000);
    EEPROM.write(100, 82);
    delay(3000);
    EEPROM.write(100, 68);
    delay(3000);
}
