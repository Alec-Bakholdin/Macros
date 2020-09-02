#include "IDTracker.h"

IDTracker::IDTracker()
{
    this->ID_Event_Map = map<string, Event *>();
}

string IDTracker::generateEventID()
{
    string output = "";
    do
    {
        for(int i = 0; i < ID_LENGTH; i++)
            output[i] = rand() % 10 + '0';
        output[ID_LENGTH] = 0;

    }while(ID_Event_Map.find(output) != ID_Event_Map.end());

    return output;
}

Event *IDTracker::getEvent(string ID)
{
    if(ID_Event_Map.count(ID) == 0)
        return NULL;
    return ID_Event_Map.find(ID)->second;
}

int IDTracker::removeEvent(string ID)
{
    return 0;
}