#include "Arrivals.hpp"
#include "Constants.hpp"
#include "Visitor.hpp"
#include "Waterpark.hpp"
#include <iostream>

void Arrivals::Behavior() {

	// Generate visitor arrivals until the last entry time 
	while (Time < LAST_ENTRY_TIME) {

		// Register visitor arrival hour for statistic
		int hour = int(Time / HOUR);
		Waterpark::arrivalHist(hour);

		// Activate new visitor after computed time
		double d = GetInterarrivalTime(hour);
		(new Visitor)->Activate();
		Wait(Exponential(d));
	}
}

double Arrivals::GetArrivalsPerHour(int hour) {

	// Access array with visitor arrival counts based on current hour
	if (Waterpark::summerMode) {
		if (Waterpark::holidayMode)
			return SUMMER_WEEKEND[(int)(hour - START_TIME_SIMULATION / HOUR)];
		else
			return SUMMER_WEEKDAY[(int)(hour - START_TIME_SIMULATION / HOUR)];
	} else {
		if (Waterpark::holidayMode)
			return DEFAULT_WEEKEND[(int)(hour - START_TIME_SIMULATION / HOUR)];
		else
			return DEFAULT_WEEKDAY[(int)(hour - START_TIME_SIMULATION / HOUR)];
	}
}

double Arrivals::GetInterarrivalTime(int hour) {
	double arrivals = GetArrivalsPerHour(hour) * Waterpark::visitorScale;	// Scale visitor arrivals by given amount

	if (arrivals <= 0)
		return __INT_MAX__;

	return HOUR / arrivals;
}