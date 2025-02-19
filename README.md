# Summary

Arduino UNO with LoRa module sends processed data to ESP8266.  
ESP8266 to Blynk for monitoring.  

# Components

## Required functionality

Measure humidity, temperature, pressure, rainfall.  
Lora node collects data from sensors, process data, transmit to gateway (with ESP8266).  
Collected data are displayed on mobile app.  
Notification when weather parameter exceeds a threshhold.

## Parts list

- ~~[Arduino UNO](https://hshop.vn/vietduino-uno)~~
- [Module RF UART Lora SX1278 433Mhz 3000m](https://hshop.vn/mach-thu-phat-rf-lora-uart-sx1278-433mhz3000m) (2)
- 433MHz antenna (optional?)
- [ESP8266](https://hshop.vn/mach-mtiny-esp8266-esp-12s-arduino-compatible) 
- ~~[Water sensor](https://hshop.vn/cam-bien-nuoc-mua-v2-rain-water-sensor) (rainfall sensor)~~
- ~~[DHT11](https://hshop.vn/cam-bien-do-am-nhiet-do-dht11) (temp, humidity sensor)~~
- [BMP180](https://nshopvn.com/product/cam-bien-ap-suat-khong-khi-bmp180/) (pressure sensor)

# Schematics
