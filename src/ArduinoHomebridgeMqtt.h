#include <AsyncMqttClient.h>
#include <ArduinoJson.h>

#ifndef DEFAULT_MQTT_PORT
#define DEFAULT_MQTT_PORT 1883
#endif

#ifndef ARDUINO_HOMEBRIDGE_MQTT_H
#define ARDUINO_HOMEBRIDGE_MQTT_H

class ArduinoHomebridgeMqtt {
private:
  bool debugMode = false;
  AsyncMqttClient mqttClient;
  std::function<void(const char* name, const char* serviceName, const char* characteristic, JsonVariantConst value)> callback;
  void publish(const char* topic, const char* payload);
  void initMqtt(const char* server, uint16_t port);
  void connect();
  
public:
  ArduinoHomebridgeMqtt();
  void onSetValueFromHomebridge(std::function<void(const char* name, const char* serviceName, const char* characteristic, JsonVariantConst value)>);
  void connect(const char* server, uint16_t port);
  void loop();
  void addAccessory(const char* name, const char* serviceName, const char* service);
  void addAccessory(const char* name, const char* serviceName, const char* service, const char* characteristics[]);
  void addAccessory(const char* name, const char* serviceName, const char* service, JsonObjectConst characteristics);
  void setAccessoryReachable(const char* name, bool reachable);
  void setAccessoryInfo(const char* name, const char* manufacturer, const char* model, const char* serial, const char* version);
  void addService(const char* name, const char* serviceName, const char* service);
  void addService(const char* name, const char* serviceName, const char* service, const char* characteristics[]);
  void addService(const char* name, const char* serviceName, const char* service, JsonObjectConst characteristics);
  void removeAccessory(const char* name);
  void removeService(const char* name, const char* serviceName);
  void getAccessory(const char* name);
  void setValueToHomebridge(const char* name, const char* serviceName, const char* characteristic, int value);
  void setValueToHomebridge(const char* name, const char* serviceName, const char* characteristic, float value);
  void setValueToHomebridge(const char* name, const char* serviceName, const char* characteristic, JsonVariantConst value);
  void setDebugEnabled(bool enabled);
  void debug(const char* message);
  void debugf(const char* format, ...);
};

#endif
