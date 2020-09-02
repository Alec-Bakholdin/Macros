#include "KeyboardEvent.h"
#include "IDTracker.h"

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

int KeyboardEvent::Invoke()
{   
    /*
    *   Invokes the KeyboardEvent, if possible.
    *   Return values:
    *       0 -> Success!
    *       1 -> invokable is false
    */

    //Let the console know what's going on
    printf("Invoking %s\n", tostring().c_str());

    //Test if invokable
    if(!invokable)
    {
        printf("Event %s is not invokable.\n", id.c_str());
        return 1;
    }

    //Invokes the event
    printf("Printing %c\n", eventData.KEY.key);

    return 0;
}

string KeyboardEvent::tostring()
{
    //Initialize
    string output = "<KeyboardEvent";

    //Adds the specified key to string
    output += ";Key: '";
    output += eventData.KEY.key;
    output += "'";

    //Adds invokable flag
    output += ";Invokable: ";
    output += (invokable ? "True" : "False");

    output += ">";
    return output;
}
