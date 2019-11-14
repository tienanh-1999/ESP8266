#include <LiquidCrystal_I2C.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#include <Wire.h>
//#define dht_dpin 0
//DHT dht(dht_dpin, DHTTYPE);

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
//Serial.begin(115200);
////dht.begin();
////Use predefined PINS consts
//Wire.begin(D2, D1);
//lcd.begin();
//
//lcd.home();

Wire.begin(2,0);
lcd.begin();   // initializing the LCD
lcd.backlight(); // Enable or Turn On the backlight 
lcd.print(" Hello Makers "); // Start Printing

}

void loop() {

float h = dht.readHumidity();
float t = dht.readTemperature();

lcd.print("Humidity: ");
//lcd.print(h);
lcd.setCursor(0, 1);
lcd.print("Temp: ");
//lcd.print(t);
}
