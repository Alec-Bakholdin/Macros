#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include "../Header.h"
#include "Event.h"

class KeyboardEvent : public Event {
    public:

        //Constructors
        KeyboardEvent();                                            //Default Constructor
        KeyboardEvent(string id, bool invokable);                   //Empty with an id
        KeyboardEvent(string id, bool invokable, KEYDATA keyData);  //Full constructor

        //Methods
        static int Equal(KeyboardEvent one, KeyboardEvent two); //Equality between two KeyboardEvents
        int Equal(KeyboardEvent event);                         //Equality between this and another KeyboardEvent
        int Invoke();                                           //Invokes the event, if possible

        //Debugging
        string tostring();                                      //String representation of the event, for debugging purposes
        static string tostring(KeyboardEvent *event);            //Static version of the above function
};

#endif