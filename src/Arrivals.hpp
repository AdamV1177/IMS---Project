#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <simlib.h>

extern Histogram arrivalHist;

class Arrivals : public Process {
	bool isSummer;
	bool isHoliday;

	// Histogram arrivalHist;
	public:
	Arrivals(bool summer, bool holiday)
	    : isSummer(summer),
	      isHoliday(holiday)
	//   arrivalHist("Visitor Arrivals per Hour", 8, 1, 13)
	{}

	void Behavior();

	void printHistory();
	double GetArrivalsPerHour(int hour, bool isSummer, bool isHoliday);
	double GetInterarrivalTime(int hour, bool isSummer, bool isHoliday);
};

#endif
