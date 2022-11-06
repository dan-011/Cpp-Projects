#ifndef __ECEvent_h
#define __ECEvent_h

#include "ECOrganism.h"

enum EventType{
    Eat = 0,
    Work = 1
};
class ECEvent{
private:
    ECOrganism* org;
    EventType eventType;
    int subtype;
    int pos;
public:
    ECEvent(ECOrganism* organism, EventType event, int subtype, int position);
    ~ECEvent();
    ECOrganism* GetOrganism() const;
    EventType GetEventType() const;
    int GetSubtype() const;
    int GetPosition() const;
};

#endif