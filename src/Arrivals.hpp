#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <simlib.h>

class Arrivals : public Process {
	bool isSummer;
	bool isHoliday;

	public:
	Histogram arrivalHist;

	Arrivals(bool summer, bool holiday)
	    : isSummer(summer),
	      isHoliday(holiday),
	      arrivalHist("Visitor Arrivals per Hour", 8, 1, 13) {}

	void Behavior();

	double GetArrivalsPerHour(int hour, bool isSummer, bool isHoliday);
	double GetInterarrivalTime(int hour, bool isSummer, bool isHoliday);
};

#endif
