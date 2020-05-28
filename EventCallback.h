#ifndef EVENT_CALLBACK_H
#define EVENT_CALLBACK_H

class EventCallback {
  public:
    virtual void callback(bool payload) = 0;
};

#endif
