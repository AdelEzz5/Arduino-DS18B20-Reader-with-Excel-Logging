#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

#define ONE_WIRE_BUS 3 //DS18B20 Pin

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
File dataFile;

const int chipSelect = 10; //CS pin for SD card
int x = 0; //Timer
int numberSensors = 0;
float temp;

void setup() {
  // start serial port
  Serial.begin(9600);
  // start SD port
  while(!Serial) {
    ;
  }

  Serial.print("Initialize SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Initalization failed!");
    while(1);
  }
  Serial.println("Initalization done.");
  
  if (SD.exists("TEMP.csv")){
    Serial.println("TEMP.csv exist");
  } else {
    Serial.println("TEMP.csv doesn't exist.");
  }
  
  // Start up the DS18B20 library
  sensors.begin();
  // locate devices
  numberSensors = sensors.getDeviceCount();
  Serial.print(numberSensors);
  Serial.println(" sensors found");
  Serial.println();
}

void loop() {
  //Print to the serial port
  //Timer
  Serial.print("Time Passed: ");
  Serial.print(x);
  Serial.println(" seconds");
  //Print the sensors reading  
  sensors.requestTemperatures();
  for (int i = 0; i < numberSensors; i++){
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" = ");
    temp = sensors.getTempCByIndex(i); //Print Temperatures in celsius
    Serial.print(temp);
    Serial.println(" C");
  }
  //Print to the SD Card
  //Open TEMP.csv file on SD Card
  dataFile = SD.open("TEMP.csv", FILE_WRITE);

  if (dataFile){
    //Print Timer
    dataFile.print("Time Passed: ");
    dataFile.print(x);
    dataFile.println(" seconds");
    //Print the sensors reading to TEMP.csv
    for (int i = 0; i < numberSensors; i++){
      dataFile.print("Sensor ");
      dataFile.print(i);
      dataFile.print(" = ");
      temp = sensors.getTempCByIndex(i);
      dataFile.print(temp);
      dataFile.println(" C");
    }
    dataFile.close(); //Close the file
  }
  else{
    Serial.println("error opening TEMP.csv");
  }
  x = x + 10; //Setting Timer With Delay
  delay(10000);
}
