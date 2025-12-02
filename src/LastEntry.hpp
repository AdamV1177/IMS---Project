#ifndef LASTENTRY_H
#define LASTENTRY_H

#include <simlib.h>

class LastEntry : public Event {
	void Behavior();       
	void ClearQueue(Queue& queue);                      
};

#endif