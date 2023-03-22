# Arduino-DS18B20-Reader-with-Excel-Logging
This project is an Arduino code that detects how many DS18B20 sensors are connected to the board and receives the reading of all sensors to an excel sheet in a fixed delay. The project is useful for anyone who wants to monitor multiple temperature sensors and log the data to an excel sheet.
# Hardware
* Arduino Uno
* DS18B20 temperature sensors
* SD card module
# Libraries
* OneWire
* DallasTemperature
* SPI
* SD
# Wiring
Connect the DS18B20 sensors to the Arduino Uno as follows:
* VCC to 5V
* GND to GND
* Data to digital pin 3

Connect the SD card module to the Arduino Uno as follows:
* MOSI to pin 11
* MISO to pin 12
* SCK to pin 13
* CS to pin 10
# Usage
1. Insert an SD card into the SD card module.
2. Upload the code to the Arduino Uno.
3. Open the Serial Monitor.
4. Wait for the message “Initializing SD card…”.
5. Wait for the message “SD card initialized.”.
6. Wait for the message “Scanning for DS18B20 sensors…”.
7. Wait for the message “Found X sensors.” (where X is the number of sensors found).
8. Wait for the message “Writing to file…”.
9. Wait for the message “Done.”.
10. The data will be written to a file named “TEMP.csv” on the SD card.

You can change the delay as your need.
