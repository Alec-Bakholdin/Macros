#ifndef IDTRACKER_H
#define IDTRACKER_H

#include "../Header.h"


#define ID_LENGTH 10


class Event;

class IDTracker{
    public:
        //Variables
        map<string, Event*> ID_Event_Map;//A map of ids to corresponding events

        //Methods
        IDTracker();                    //Default Constructor. Initializes the event map

        string generateEventID();        //Generate a random Event ID that hasn't been used yet
        Event *getEvent(string ID);      //Find an in the map given teh 
        int insertEvent(Event *event);   //Inserts an event into the map with key event->id
        int removeEvent(string ID);      //Remove the event with the matching 

};

static IDTracker Event_IDs;

#endif