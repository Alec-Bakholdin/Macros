#ifndef EVENT_H
#define EVENT_H

#include "../Header.h"

//Keyboard Event
typedef struct KeyboardEventData{
    char key;
}KeyboardEventData, KEYDATA;

//Mouse Event
typedef struct MouseEventData{
    bool click;
}MouseEventData, MOUSEDATA;

//Union of all above events
typedef union EventData{
    struct KeyboardEventData KEY;
    struct MouseEventData MOUSE;
}EventData;


enum EventType {Keyboard, Mouse, None};

class Event{
    public:

        //Variables defining the class
        string      id;         //Unique ID for the event
        bool        invokable;  //Is it invokable or triggered? Are we listening for or doing this event?
        EventType   eventType;  //Type of the event (Keyboard, Mouse, etc.)
        EventData   eventData;  //Actual event (what key, how long to press, etc.)


        //Constructors
        Event();                                                               // Creates empty event, no type
        Event(string id, bool invokable, EventType type, EventData eventData); // More robust event constructor

        //Methods
        static int Equal(Event *one, Event *two);     //Check for equality of two events
        int Equal(Event *event);                      //Check for equality between this and another
        virtual int Invoke();                                 //Invokes the event, if possible
        virtual string tostring();                    //Returns string representation of the event out for debugging purposes
};

#endif