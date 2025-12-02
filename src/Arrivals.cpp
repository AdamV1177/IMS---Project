#include "Arrivals.hpp"
#include "Constants.hpp"
#include "Visitor.hpp"
#include "Waterpark.hpp"
#include <iostream>



void Arrivals::Behavior() {
	while (Time / HOUR < LAST_ENTRY_TIME) {
		int hour = int(Time / HOUR);
		Waterpark::arrivalHist(hour);
		double d = GetInterarrivalTime(hour, isSummer, isHoliday);
		(new Visitor)->Activate();
		Wait(Exponential(d));
	}
}
double Arrivals::GetArrivalsPerHour(int hour, bool isSummer, bool isHoliday) {
	if (isSummer) {
		if (isHoliday)
			return SUMMER_WEEKEND[(int)(hour - START_TIME_SIMULATION / HOUR)];
		else
			return SUMMER_WEEKDAY[(int)(hour - START_TIME_SIMULATION / HOUR)];
	} else {
		if (isHoliday)
			return DEFAULT_WEEKEND[(int)(hour - START_TIME_SIMULATION / HOUR)];
		else
			return DEFAULT_WEEKDAY[(int)(hour - START_TIME_SIMULATION / HOUR)];
	}
}

double Arrivals::GetInterarrivalTime(int hour, bool isSummer, bool isHoliday) {
	double arrivals = GetArrivalsPerHour(hour, isSummer, isHoliday) * Waterpark::visitorScale;

	if (arrivals <= 0)
		return __INT_MAX__;

	return HOUR / arrivals;
}