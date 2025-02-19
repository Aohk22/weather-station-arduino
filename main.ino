#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "DHT.h"

#define DHTPIN A1
#define DHTTYPE DHT11

const int MAX_WATER_LEVEL = 700;
const int MIN_WATER_LEVEL = 300;
const int waterPin = A0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

// goes from 0 -> 660
int waterLevel = 0;
float temp = 0;
float humidity = 0;


void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.print("Sensor Monitor");
}


void loop() {
  waterLevel = analogRead(waterPin);
  temp = dht.readTemperature();
  humidity = dht.readHumidity();

  String status = "";
  
  status += waterStringLCD();
  status += tempStringLCD();
  status += humidityStringLCD();

  lcd.setCursor(0, 1);
  lcd.print(status);

  displayHumiditySerial();

  delay(1500);
}


String tempStringLCD() {
  char buffer[4];
  sprintf(buffer, " T%02dC", (int)temp);
  return buffer;
}


String humidityStringLCD() {
  char buffer[4];
  sprintf(buffer, " H%02d%%", (int)humidity);
  return buffer;
}


String waterStringLCD() {
  char buffer[6];  // ensure buffer is large enough
  float area = max(waterLevel, MIN_WATER_LEVEL) - MIN_WATER_LEVEL; 
  float waterPercent = (area / (MAX_WATER_LEVEL - MIN_WATER_LEVEL)) * 100;

  String waterText = "";

  if (waterPercent > 86.) {
    waterText = "H";
  } else if (waterPercent > 79.) {
    waterText = "M";
  } else {
    waterText = "L";
  }

  sprintf(buffer, "W%02d%%_%s", (int)waterPercent, waterText.c_str());
  return buffer;
}


void displayWaterLevelSerial(bool debug) {
  float area = max(waterLevel, MIN_WATER_LEVEL) - MIN_WATER_LEVEL; 
  float waterPercent = (area / (MAX_WATER_LEVEL - MIN_WATER_LEVEL)) * 100;

  String waterText = "";

  if (waterPercent > 86.) {
    waterText = "HIGH";
  } else if (waterPercent > 79.) {
    waterText = "MEDIUM";
  } else {
    waterText = "LOW";
  }

  Serial.println("Water level: " + waterText + " (" + String(waterPercent, 2) + "%).");

  if(debug) {
    Serial.println("DEBUG: waterLevel=" + String(waterLevel));
  }
}


void displayHumiditySerial() {
  Serial.println("Humidity: " + String(humidity));
}