#include "Header.h"
#include "Events/IDTracker.h"
#include "Events/AllEvents.h"

int main(int argc, char** argv)
{
    //Initialize the ID tracker
    Event_IDs = IDTracker();

    KEYDATA keyData = {'b'};
    string id = Event_IDs.generateEventID();
    KeyboardEvent keyEvent = KeyboardEvent(id, true, keyData);

    keyEvent.Invoke();

    return 0;
}