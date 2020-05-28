#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "UserConfig.h"
#include "EventCallback.h"

class MqttClient {
  public:
    MqttClient();
    void connect();
    void loop();
    void publishState(bool state);
    void setCallback(EventCallback *eventCallback);
  private:
    WiFiClient espClient;
    PubSubClient client;
    EventCallback *eventCallback;
    void callback(char* topic, byte* payload, unsigned int length);
    void setUpWiFi();
};

#endif
