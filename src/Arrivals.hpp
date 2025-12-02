#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <simlib.h>
#include "Waterpark.hpp"

class Arrivals : public Process {
	public:

	void Behavior();

	void printHistory();
	double GetArrivalsPerHour(int hour);
	double GetInterarrivalTime(int hour);
};

#endif
