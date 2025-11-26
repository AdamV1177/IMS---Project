#ifndef OPENTIME_H
#define OPENTIME_H

#include "Waterpark.hpp"
#include <simlib.h>

class OpeningTime : public Event {
	void Behavior();                             // Function opening all the waterpark entries
	void openQueue(Queue *queue, int registers); // Function opening a single waterpark entry, activating processes from its queue
};

#endif