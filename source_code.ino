/*
  Hardware- Arduino nana 33 iot, BME280 sensor
  iot-Blynk
*/

//Defining the BLYNK_PRINT serial and other nessary libary requird for this project

#define BLYNK_PRINT serial
#include <wire.h>
#include <SPI.h>
#include  <WiFiNINA.h>
#include <Blynksimple WifiNINA.h>
#include <Adafruitsensor.h>
#include <Adafruit_BME280.h>

// Get Auth Token in the Blynk App.
// Go to the Project Settings.

char arth[] = "your arth token from Blynk APP"

// Your WiFi credentials.
// For your WiFi credentrials press WINDOWS KEY + R and type CMD and hit ENTER and type "Ipconfig" then type "netsh wlan show network" or "netsh wlan and hit enter and type show all"
// Set password to "" for open Wifi networks.

char ssid [] = "your ssid "
char pass[] = "your wifi password"

//I2C

Adafruit_BM280 bme; 

flote f;
flote h;
flote p;

BlynkTimer timer;

void sendsensor() {

  t = bme.readTemperature();
  h = bme.readHumidity();
  p = bme.readPressure();

  Blynk.virtualWrite(v5, t);
  Blynk.virtualWrite(v6, h);
  Blynk.virtualWrite (v7, p / 100.0F);

}

void setup() {

  serial.begin(9600);
  Blynk.begin(arth, ssid, pass);
  
  // You can also specify server for this work:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  Serial.println("BME280 test");

  if (!bme.begin()) {
    Serial.println("sorry, Could not find a valid BME280 sensor data, check wiring! and fault ");
    while (1);
  }

  timer.setInterval(3000, sendSensor);

}

void loop() {
  
  // read the sensors and append to the string:

  Blynk.run()
  timer.run()
}
