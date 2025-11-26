#ifndef VISITOR_H
#define VISITOR_H

#include <simlib.h>

class Visitor : public Process {

	// Main Visitor process
	void Behavior();

	// Entry through the outside available in summer mode
	void outsideEntry();

	// Entry through the inside available year-round
	void insideEntry();

	// Visitor in waterpark for Gamma(a, b) hours
	void inWaterpark();

	// Function using a register at a generic entry with a generic queue
	void useRegister(Facility *entry, Queue *queue, int count, double time);
};

#endif