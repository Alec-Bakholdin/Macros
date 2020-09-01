#include "Header.h"
#include "Events/EventTree.h"
#include "Events/Event.h"

int main(int argc, char** argv)
{
    KeyboardEvent keyEvent = {'a'};
    EventData eventData = {keyEvent};
    Event event(1, Keyboard, eventData);

    int response;
    if((response = event.Invoke()) != 0)
        printf("ERROR %d: Invoke Failed\n", response);
    return 0;
}