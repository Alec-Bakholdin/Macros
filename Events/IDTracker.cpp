#include "IDTracker.h"
#include "Event.h"

IDTracker::IDTracker()
{
    this->ID_Event_Map = map<string, Event *>();
}

string IDTracker::generateEventID()
{
    /*
    *   Generates a new unique ID (a string of numerical characters of length ID_LENGTH)
    *   that does not exist in the map as a key.
    *   Return values:
    *       string  -> valid ID
    *       ""      -> Error
    */

    //Initialize output variable
    string output = "";

    //Generate once, then test to see if the key exists
    do
    {
        for(int i = 0; i < ID_LENGTH; i++)
            output[i] = rand() % 10 + '0'; //Select random character from 0-9

        output[ID_LENGTH] = 0; //Null-terminate it so when converted to char* it's still fine

    }while(ID_Event_Map.find(output) != ID_Event_Map.end());

    return output;
}

Event *IDTracker::getEvent(string ID)
{
    /*
    *   Returns the event corresponding to the given ID in the map
    *   Return values:
    *       Event * -> Success!
    *       NULL    -> No Event found with the given id
    */
    if(ID_Event_Map.count(ID) == 0)
        return NULL;
    return ID_Event_Map.find(ID)->second;
}

int IDTracker::insertEvent(Event *event)
{
    /*
    *   Inserts the evnt into the map.
    *   Return values:
    *       0 -> Success!
    *       1 -> Key already exists
    *       2 -> Key could not be inserted (Mapping error)
    */

    //First check to see if the event id is already mapped
    if(ID_Event_Map.count(event->id) > 0)
    {
        printf("ERROR: Key %s is already mapped to the event %s\n", event->id.c_str(), ID_Event_Map[event->id]->tostring().c_str());
        return 1;
    }

    //If the insert function fails, it will return a pair <event, false>, which we check here
    if(ID_Event_Map.insert(pair<string, Event *>(event->id, event)).second == false)
    {
        printf("ERROR: Could not insert Event '%s'\n", event->tostring().c_str());
        return 2;
    }

    //If nothing else, return Success!
    return 0;
}

int IDTracker::removeEvent(string ID)
{

    return 0;
}