#include "Event.h"
#include "EventTree.h"

Event::Event()
{
    
}

Event::Event(int id, EventType type, union EventData eventData)
{
    this->id = id;
    this->type = type;
    this->eventData = eventData;
}
int Event::Invoke()
{
    switch(this->type)
    {
        case Keyboard:
            printf("Keyboard Event: '%c'\n", this->eventData.KEY.key);
            break;
        case Mouse:
            printf("Mouse Event\n");
            break;
        default:
            printf("Default Action. Something went wrong\n");
            return -1;
    }
    return 0;
}
