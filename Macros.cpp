#include "Header.h"
#include "Events/Event.h"
#include "Events/IDTracker.h"

int main(int argc, char** argv)
{
    //Initialize the ID tracker
    IDTracker idtracker = IDTracker();

    printf(idtracker.generateEventID().c_str());
    printf("\n");

    KEYDATA keyEvent = {'a'};
    EventData eventData = {keyEvent};
    Event event(1, Keyboard, eventData);

    int response;
    if((response = event.Invoke()) != 0)
        printf("ERROR %d: Invoke Failed\n", response);
    return 0;
}