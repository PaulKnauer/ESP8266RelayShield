#ifndef RELAY_STATE_H
#define RELAY_STATE_H

#include "Relay.h"
#include "EventCallback.h"

class RelayState : public EventCallback {
  public:
    RelayState(Relay *relay);
    bool stateChanged();
    void resetState();
    bool getState();
    void callback(bool payload);
  private:
    bool state;
    bool currentState;
    Relay *relay;
};

#endif
