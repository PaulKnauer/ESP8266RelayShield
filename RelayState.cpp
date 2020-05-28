#include "RelayState.h"

RelayState::RelayState(Relay *relay) {
  this->relay = relay;
  state = false;
  currentState = false;
}

bool RelayState::stateChanged() {
  return state != currentState;
}

void RelayState::resetState() {
  currentState = state;
}

bool RelayState::getState() {
  return state;
}

void RelayState::callback(bool payload) {
  if (payload) {
    state = true;
    relay->on();
  } else {
    state = false;
    relay->off();
  }
}
