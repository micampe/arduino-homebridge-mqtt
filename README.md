# Arduino Homebridge MQTT

[![Build Status](https://travis-ci.org/waritsan/arduino-homebridge-mqtt.svg?branch=master)](https://travis-ci.org/waritsan/arduino-homebridge-mqtt)

Arduino library for connecting to Homebridge.

### Dependancies:
* [Mosquitto](https://mosquitto.org)
* [Homebridge](https://github.com/nfarina/homebridge)
* [Homebridge-MQTT](https://github.com/cflurin/homebridge-mqtt)

### Installation Guide
* [PlatformIO](https://platformio.org/lib/show/1907/ArduinoHomebridgeMqtt)
* [Arduino IDE](https://www.arduino.cc/en/Guide/Libraries#toc4)

### Usage
```cpp
// Switch example
#include <ArduinoHomebridgeMqtt.h>

ArduinoHomebridgeMqtt client;

void operateSwitch(const char* serviceName, const char* characteristic, int value) {
  if (strcmp(serviceName, "MySwitch") == 0) {
    digitalWrite(D1, value);
  }
}

void setup() {
  Serial.begin(9600);
  client.onSetValueFromHomebridge(operateSwitch);
  client.connect(IPAddress(192, 168, 1, 1)); // Replace the IP with your MQTT server IP
}

void loop() {
  client.loop();
}
```
See other examples in /examples
