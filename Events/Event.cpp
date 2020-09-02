#include "Event.h"
#include "KeyboardEvent.h"
#include "IDTracker.h"

Event::Event()
{
    this->id = Event_IDs.generateEventID();
    this->invokable = false;
    this->eventType = None;
    this->eventData = {};

    //Handle errors here
    if(Event_IDs.insertEvent(this) != 0)
        return;
}

Event::Event(string id, bool invokable, EventType type, union EventData eventData)
{
    this->id = id;
    this->invokable = invokable;
    this->eventType = type;
    this->eventData = eventData;

    //Handle errors here
    if(Event_IDs.insertEvent(this) != 0)
        return;
}
int Event::Invoke()
{
    switch(this->eventType)
    {
        case Keyboard:
            printf("Invoking %s", ((KeyboardEvent*)this)->tostring().c_str());
            break;
        case Mouse:
            printf("Mouse Event\n");
            break;
        default:
            printf("Default Action. Something went wrong\n");
            return 1;
    }
    return 0;
}
string Event::tostring()
{
    return ((KeyboardEvent*)this)->tostring();
}
