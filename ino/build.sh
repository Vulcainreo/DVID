ls -la /
ls -la /build/
ls -la /build/src/

/opt/arduino-1.8.16/arduino-builder -compile -logger=machine -hardware /opt/arduino-1.8.16/hardware -tools /opt/arduino-1.8.16/tools-builder -tools /opt/arduino-1.8.16/hardware/tools/avr -built-in-libraries /opt/arduino-1.8.16/libraries -libraries /libraries -fqbn=arduino:avr:atmega328bb -ide-version=10815 -build-path /build/build -warnings=none -build-cache /cache -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.avrdude.path=/opt/arduino-1.8.16/hardware/tools/avr -prefs=runtime.tools.avrdude-6.3.0-arduino17.path=/opt/arduino-1.8.16/hardware/tools/avr -prefs=runtime.tools.avr-gcc.path=/opt/arduino-1.8.16/hardware/tools/avr -prefs=runtime.tools.avr-gcc-7.3.0-atmel3.6.1-arduino7.path=/opt/arduino-1.8.16/hardware/tools/avr -prefs=runtime.tools.arduinoOTA.path=/opt/arduino-1.8.16/hardware/tools/avr -prefs=runtime.tools.arduinoOTA-1.3.0.path=/opt/arduino-1.8.16/hardware/tools/avr -verbose /build/src/*.ino
