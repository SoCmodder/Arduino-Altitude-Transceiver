#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>

// using I2C
Adafruit_BMP280 bme;

// HC-12 Radio Transceiver
SoftwareSerial HC12(10, 11);

void setup() {
  Serial.begin(9600);
  delay(2000);
  HC12.begin(9600);
//  bme.begin(9600);
//  if (!bme.begin()) {
//    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
//    while (1);
//  }
}

void loop() {
  Serial.println("Loop start");
  listenRadio();
  transmitTestData();
//  readAltitude();
//  transmitAltitude();
  Serial.println("Loop End");
  delay(1000);
}

// Listen to HC-12 for incoming radio message
void listenRadio() {
  if (HC12.available()) {
    Serial.print(HC12.readString());
  }
}

void readAltitude() {
  Serial.print(bme.readAltitude(1013.25));
}

void transmitAltitude() {
  Serial.println("Transmitting Altitude");
  HC12.write(bme.readAltitude(1013.25));
  delay(1000);
}

void transmitTestData() {
  Serial.println("Transmitting Test Data");
  HC12.write("Test Data");
  delay(1000);
}

void readAll() {
  Serial.print("---- GY BMP 280 ----------------\n");
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100); // 100 Pa = 1 millibar
  Serial.println(" mb");
  Serial.print("Approx altitude = ");
  Serial.print(bme.readAltitude(1013.25));
  Serial.println(" m");
  Serial.print("--------------------------------\n\n");
  delay(2000);
}

// TODO:
// Method to illuminate LED to show when radio is transmitting
void showTransmitting() {

}

