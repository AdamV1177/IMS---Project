#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <simlib.h>
#include "Waterpark.hpp"

class Arrivals : public Process {
public:

	void Behavior();	// Main method of visitor generator

	double GetArrivalsPerHour(int hour);	// Function accessing per hour visitor counts from Constants.hpp
	double GetInterarrivalTime(int hour);	// Function calculating time betwwen visitor arrivals for given hour
};

#endif
