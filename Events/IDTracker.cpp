#include "IDTracker.h"

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
            output[i] = rand() % 10 + '0';
        output[ID_LENGTH] = 0;

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
        printf("ERROR: Key %s is already mapped to the event '%s'\n", event->id, ID_Event_Map[event->id]->tostring());
        return 1;
    }

    //If the insert function fails, it will return a pair <event, false>, which we check
    if(ID_Event_Map.insert(pair<string, Event *>(event->id, event)).second == false)
    {
        printf("ERROR: Could not insert Event '%s'\n", event->tostring());
        return 2;
    }

    //If nothing else, return true!
    return 0;
}

int IDTracker::removeEvent(string ID)
{

    return 0;
}