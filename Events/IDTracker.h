#pragma once

#include "../Header.h"
#include "Event.h"

#define ID_LENGTH 10

class IDTracker{
    public:
        //Variables
        map<string, Event*> ID_Event_Map;//A map of ids to corresponding events

        //Methods
        IDTracker();                    //Default Constructor. Initializes the event map

        string generateEventID();        //Generate a random Event ID that hasn't been used yet
        int insertEvent(Event *event);   //Inserts an event
        Event *getEvent(string ID);      //Find an in the map given teh 
        int removeEvent(string ID);      //Remove the event with the matching 

};
