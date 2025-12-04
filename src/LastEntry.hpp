#ifndef LASTENTRY_H
#define LASTENTRY_H

#include <simlib.h>

// Event firing when time of last entry hits
class LastEntry : public Event {
	void Behavior();				// Event entry point
	void ClearQueue(Queue& queue);	// Function clearing the specified queue
};

#endif