#ifndef EVENT_H
#define EVENT_H

#include "../Header.h"

enum EventType {NONE, Keyboard, Mouse};

typedef struct KeyboardEventData{
    char key;
}KeyboardEventData, KEYDATA;

typedef struct MouseEventData{
    bool click;
}MouseEventData, MOUSEDATA;

typedef union EventData{
    struct KeyboardEventData KEY;
    struct MouseEventData MOUSE;
}EventData;

class Event{
    public:

        //Variables defining the class
        int         id;         //Unique ID for the event
        EventType   type;       //Type of the event (Keyboard, Mouse, etc.)
        EventData   eventData;  //Actual event (what key, how long to press, etc.)
        bool        invokable;  //Is it invokable or triggered? Are we listening for or doing this event?


        //Constructors
        Event();                                            // Creates empty event, no type
        Event(int id, EventType type, EventData eventData); // More robust event constructor

        
        static int Equal(Event one, Event two);     //Check for equality of two events
        int Equal(Event event);                     //Check for equality between this and another
        int Invoke();                               //Invokes the event, if possible
};

#endif