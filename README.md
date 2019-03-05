# DVID
Damn Vulnerable IoT Device - The first opensource vulnerable designed IoT device

**/!\\ This project is currently in development /!\\**

All details are available on DVID website : [http://dvid.eu](http://dvid.eu)

# Project overview

This IoT device is designed by my own and published on OpenSource. The main objective is to provide to each interrested people a vulnerable board to improve their skill in IoT hacking.

The board core is composed by a Atmega328p and a OLED screen. For each vulnerabilities, a firmware could be flashed on the Atmega328p in order to offer a specific vulnerable environment.

There is also connection port like UART, Bluetooth, 2,4Ghz and Wifi. In each vulnerability, a specific extension board must be plugged to the board.

Hacking required attacks tools like USBasp and USBuart.

# Board

You can buy the board on marketplace (available soon) or build it yourself with Gerber files.
The board is shipped with theses three packages :
* **Board only and component reference** : Naked board only. You must buy all component yourself and solder all component.
* **Soldered board without attack component and extention** : Soldered board but you must buy all external tools like USBuart, USBasp, extention board.
* **Full package** : Everything needed (soldered board, external board and attack tools).

# Part list

Part | Quantity | Total Cost | Buying link
--- | --- | --- | ---
Board | 1 | 3€ | Available soon or build yourself :)
Jumper Double Row Female 2x4P | 2 | 0,5€ | https://www.banggood.com/30pcs-2_54mm-2x4P-8P-Double-Row-Female-Straight-Pin-Header-Needle-Socket-Pin-Strip-p-1348262.html
Jumper Single Row Male | 4 | 0,5€ | https://www.banggood.com/10Pcs-40-Pin-2_54mm-Male-Female-SIL-Socket-Row-Strip-PCB-Connector-p-953436.html
28 pins socket (for atmega328p) | 1 | 0,5€ | https://www.banggood.com/50pcs-28-Pins-IC-DIP-2_54mm-Wide-Integrated-Circuit-Sockets-Adaptor-p-1211042.html
PCB screw to oled screen | 4 | 0,5€ | https://www.banggood.com/300pcs-M3-Nylon-Black-Hex-Scre-p-984310.html
Oled Screen 4Pin white | 1 | 5€ | https://www.banggood.com/1_3-Inch-4Pin-White-OLED-LCD-Display-12864-IIC-I2C-Interface-Module-For-Arduino-p-1067874.html
Atmega328p | 1 | 3€ | https://www.banggood.com/DIP28-ATmega328PPU-MCU-IC-Chip-With-Arduino-UNO-Bootloader-p-932159.html
5V to 3V power supply | 1 | 1€ | https://www.banggood.com/5V-To-3_3V-DC-DC-Step-Down-Power-Supply-Buck-Module-AMS1117-800MA-p-933674.html
16Mhz resonator | 1 | 0,5€ | https://www.banggood.com/10Pcs-HC-49S-16MHz-16-MHz-16M-Hz-16_000M-Mini-Passive-Resonator-Quartz-Crystal-Oscillator-p-1096168.html
Status led | 1 | 0,5€ | https://www.banggood.com/10pcs-5mm-3000-6000mcd-LED-Bright-Decoration-Torch-Toy-Light-Green-p-73175.html
Total |  | 15€ |

# Attack tools and extention board

Part | Quantity | Total Cost | Buying link
--- | --- | --- | ---
UsbUART | 1 | 3€ |  https://www.banggood.com/CP2102-USB-To-TTL-Module-p-1263924.html?rmmds=myorder&cur_warehouse=CN
UsbASP + 6P adapter | 1 | 4€ | https://www.banggood.com/3_3V-5V-USBASP-USBISP-AVR-Programmer-Downloader-ATMEGA8-ATMEGA128-With-Download-Cable-p-1179967.html
JDY-18 BLE module | 1 | 4€ | https://www.banggood.com/JDY-18-Bluetooth-Module-4_2-High-Speed-Transmission-BLE-Mesh-Networking-Master-Slave-Integration-p-1324896.html
CSR BLE adapter | 1 | 4€ | https://www.banggood.com/Mini-Wireless-Dongle-CSR-4_0-Bluetooth-Adapter-V4_0-USB-2_03_0-For-Win-7810XP-For-Vista-3264-p-1132661.html
Jumper Wire female female | 1 | 2€ | https://www.banggood.com/120pcs-20cm-Male-To-Female-Female-To-Female-Male-To-Male-Color-Breadboard-Jumper-Cable-Dupont-Wire-Combination-For-Arduino-p-974006.html
Total |  | 18€ |
