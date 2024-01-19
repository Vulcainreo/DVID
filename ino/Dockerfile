FROM alpine

RUN apk update
RUN apk add xz
COPY arduino-1.8.16.tar.xz /

RUN xz -d arduino-1.8.16.tar.xz
RUN tar -xvf arduino-1.8.16.tar -C /opt

# RUN pip install ino

COPY boards.txt /opt/arduino-1.8.16/hardware/arduino/avr/
COPY Cytron_SSD1306 /opt/arduino-1.8.16/libraries/Cytron_SSD1306/
COPY SSD1306Ascii /opt/arduino-1.8.16/libraries/SSD1306Ascii/
COPY Adafruit_GFX_Library /opt/arduino-1.8.16/libraries/Adafruit_GFX_Library/
COPY Adafruit_SSD1306 /opt/arduino-1.8.16/libraries/Adafruit_SSD1306/
COPY Adafruit_BusIO /opt/arduino-1.8.16/libraries/Adafruit_BusIO/

COPY build.sh /
RUN chmod +x /build.sh

CMD ["sh", "-c", "./build.sh"]
# CMD ["tail", "-f", "/dev/null"]
