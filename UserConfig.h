#ifndef UserConfig_h
#define UserConfig_h

#define WLAN_SSID        "kezro"
#define WLAN_PASSWORD    "P@ul123D3bbie"

#define DELAY 500


#define MQTT_CLIENT_NAME "OfficeRelay"
#define MQTT_SERVER      "192.168.2.18"
#define MQTT_SERVERPORT  1883
#define MQTT_USERNAME    ""
#define MQTT_PASSWORD    ""

#define MQTT_RELAY_STATE_PUBLISH_TOPIC "/Office/Relay/State"
#define MQTT_RELAY_SUBSCRIBE_TOPIC "/Office/Relay/Switch"

#endif
