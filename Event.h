#ifndef EVENT_H
#define EVENT_H

#include "Header.h"

enum EventType {Keyboard, Mouse};

typedef struct KeyboardEvent{
    char key;
}KeyboardEvent;

typedef struct MouseEvent{
    bool click;
}MouseEvent;

typedef union EventData{
    struct KeyboardEvent KEY;
    struct MouseEvent MOUSE;
}EventData;

class Event{
    private:
        static int global_id;
    public:
        int         id;
        EventType   type;
        EventData   eventData;

        Event(int id, EventType type, EventData eventData);

        int Invoke();
        bool Equal(Event event);
        static bool Equal(Event one, Event two);
};

#endif