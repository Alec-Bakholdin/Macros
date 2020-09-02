#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent()
{
    this->id = Event_IDs.generateEventID();

    this->invokable = false;
    this->eventType = Keyboard;

    //Create empty KEYDATA struct
    KEYDATA keyData = {};
    this->eventData.KEY = keyData;

    //Handle errors if necessary
    if(Event_IDs.insertEvent(this) != 0)
        return;
}

KeyboardEvent::KeyboardEvent(string id, bool invokable)
{
    this->id = id;
    this->invokable = invokable;
    this->eventType = Keyboard;
    
    //Create empty KEYDATA Struct
    KEYDATA keyData = {};
    this->eventData.KEY = keyData;

    //Handle errors here
    if(Event_IDs.insertEvent(this) != 0)
        return;
}

KeyboardEvent::KeyboardEvent(string id, bool invokable, KEYDATA keyData)
{
    this->id = id;
    this->invokable = invokable;
    this->eventType = Keyboard;
    this->eventData.KEY = keyData;

    //Handle errors here
    if(Event_IDs.insertEvent(this) != 0)
        return;
}

string KeyboardEvent::tostring()
{
    //Initialize
    string output = "KeyboardEvent";

    //Adds the specified key to string
    output += " '" + this->eventData.KEY.key + '\'';

    //Adds invokable flag
    output += " invokable: " + this->invokable;

    return output;
}
