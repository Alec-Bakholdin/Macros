#include "Header.h"
#include "Event.h"

class KeyboardEvent : public Event{
    public:

        //Constructors
        KeyboardEvent();                                    //Default Constructor
        KeyboardEvent(int id);                              //Empty with an id
        KeyboardEvent(int id, KEYDATA keyboardEventData);   //Full constructor

        //
        static int Equal(KeyboardEvent one, KeyboardEvent two);
        int Equal(KeyboardEvent event);
        int Invoke();
}