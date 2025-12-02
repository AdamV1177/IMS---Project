#include "Arrivals.hpp"
#include "Constants.hpp"
#include "Visitor.hpp"
#include "Waterpark.hpp"
#include <iostream>



void Arrivals::Behavior() {
	while (Time / HOUR < LAST_ENTRY_TIME) {
		int hour = int(Time / HOUR);
		Waterpark::arrivalHist(hour);
		double d = GetInterarrivalTime(hour);
		(new Visitor)->Activate();
		Wait(Exponential(d));
	}
}
double Arrivals::GetArrivalsPerHour(int hour) {
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
	double arrivals = GetArrivalsPerHour(hour);

	if (arrivals <= 0)
		return __INT_MAX__;

	return HOUR / arrivals;
}