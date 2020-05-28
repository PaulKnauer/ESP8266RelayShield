#ifndef RELAY_H
#define RELAY_H

#include "Arduino.h"

class Relay {
  public:
    Relay(int relayPin);
    void on();
    void off();
  private:
    int relayPin;
};

#endif
