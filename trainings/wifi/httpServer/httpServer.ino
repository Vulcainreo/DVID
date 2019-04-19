#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial wifi(2,3);

void setup()
{
  // Wifi
  wifi.begin(115200);

  delay(2000);
  wifi.println("AT");
  delay(2000);
  wifi.println("AT+CWMODE=2");
  delay(2000);
  wifi.println("AT+CWSAP_CUR=\"ccc\",\"ccc\",5,0");

}

void loop() {}
