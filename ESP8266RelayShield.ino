#include "MqttClient.h"
#include "Relay.h"
#include "RelayState.h"

const int relayPin = D3;

MqttClient *client;
Relay *relay;
RelayState *state;

void setup() {
  client = new MqttClient();
  client->connect();

  relay = new Relay(relayPin);
  state = new RelayState(relay);
  client->setCallback(state);
}

void loop() {
  client->loop();
  if (state->stateChanged()) {
    client->publishState(state->getState());
    state->resetState();
  }
  delay(DELAY);
}
