#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <simlib.h>


class Arrivals : public Process {
	bool isSummer;
	bool isHoliday;

	public:
	Arrivals(bool summer, bool holiday)
	    : isSummer(summer),
	      isHoliday(holiday){}

	void Behavior();

	void printHistory();
	double GetArrivalsPerHour(int hour, bool isSummer, bool isHoliday);
	double GetInterarrivalTime(int hour, bool isSummer, bool isHoliday);
};

#endif
