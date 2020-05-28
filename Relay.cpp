#include "Relay.h"

Relay::Relay(int relayPin) {
  this->relayPin = relayPin;
  pinMode(this->relayPin, OUTPUT);
}

void Relay::on() {
  digitalWrite(relayPin, HIGH);
}

void Relay::off() {
  digitalWrite(relayPin, LOW);  
}
