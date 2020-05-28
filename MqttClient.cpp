#include "MqttClient.h"

#include "Arduino.h"

MqttClient::MqttClient() {
  setUpWiFi();
  espClient = WiFiClient();
  client = PubSubClient(espClient);
  client.setServer(MQTT_SERVER, MQTT_SERVERPORT);
  client.setCallback([this] (char* topic, byte * payload, unsigned int length) {
    this->callback(topic, payload, length);
  });
}

void MqttClient::connect() {
  while (!client.connected()) {
    if (client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
      client.publish(MQTT_RELAY_STATE_PUBLISH_TOPIC, "false");
      client.subscribe(MQTT_RELAY_SUBSCRIBE_TOPIC);
    } else {
      delay(5000);
    }
  }
}

void MqttClient::loop() {
  if (!client.connected()) {
    this->connect();
  }
  client.loop();
}

void MqttClient::publishState(bool state) {
  if (state) {
    client.publish(MQTT_RELAY_STATE_PUBLISH_TOPIC, "true");
  } else {
    client.publish(MQTT_RELAY_STATE_PUBLISH_TOPIC, "false");
  }
}

void MqttClient::setCallback(EventCallback *eventCallback) {
  this->eventCallback = eventCallback;
}

void MqttClient::callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == 't') {
    if (eventCallback != NULL ) {
      eventCallback->callback(true);
    }
  } else {
    if (eventCallback != NULL ) {
      eventCallback->callback(false);
    }
  }
}

void MqttClient::setUpWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
