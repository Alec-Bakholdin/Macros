#include "Event.h"

class KeyboardEvent : public Event{
    public:

        //Constructors
        KeyboardEvent();                                    //Default Constructor
        KeyboardEvent(int id);                              //Empty with an id
        KeyboardEvent(int id, KEYDATA keyData);   //Full constructor

        //Methods
        static int Equal(KeyboardEvent one, KeyboardEvent two); //Equality between two KeyboardEvents
        int Equal(KeyboardEvent event);                         //Equality between this and another KeyboardEvent
        int Invoke();                                           //Invokes the event, if possible

};