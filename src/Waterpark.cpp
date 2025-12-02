#include <iostream>
#include "Waterpark.hpp"

void Waterpark::outputStatistics() {
    std::cout << "-------------------------MONEY MADE------------------------\n";
	std::cout << "Money made: " << Waterpark::moneyMade << " Kč" << std::endl;
	std::cout << "-----------------------------------------------------------\n";

	std::cout << "\n-------------------------ARRIVAL HISTOGRAM------------------------\n";
	Waterpark::arrivalHist.Output();
	std::cout << "-----------------------------------------------------------\n";
	
    std::cout << "\n-------------------------TIME IN QUEUE------------------------\n";
	for (int i = 0; i < SIM_HOURS; i++){
		std::cout << "Mean time in queue when arriving at " << i + START_HOUR << ": ";
		if (Waterpark::QueueWaitTime[i].Number() != 0)
			std::cout << Waterpark::QueueWaitTime[i].MeanValue() << " minutes" << std::endl;
		else 
			std::cout << "No arrivals at this hour" << std::endl;
	}
	std::cout << "-----------------------------------------------------------\n";
	
    std::cout << "\n-------------------------OCCUPANCY PER HOUR------------------------\n";
	for (int i = 0; i < SIM_HOURS; i++){
		std::cout << "Occupancy at " << i + START_HOUR << ":59: " << Waterpark::Occupancy[i] << std::endl;
	}
	std::cout << "-----------------------------------------------------------\n";
	
    std::cout << "\n-------------------------TIME SPENT IN WATERPARK------------------------\n";
	Waterpark::TimeInWaterpark.Output();
	std::cout << "-----------------------------------------------------------\n";

	std::cout << "\n-------------------------DEPARTURES PER HOUR------------------------\n";
	Waterpark::departureHist.Output();
	std::cout << "-----------------------------------------------------------\n";

	std::cout << "\n-------------------------ENTRIES INTO WATERPARK PER HOUR------------------------\n";
	Waterpark::entryHist.Output();
	std::cout << "-----------------------------------------------------------\n";

	std::cout << "\n-------------------------ALL INDIVIDUAL QUEUES ------------------------\n";
	Waterpark::MainEntryQueue.Output();
	Waterpark::SummerEntryQueue.Output();
	Waterpark::SummerSmartRegisterQueue.Output();
	Waterpark::SmartRegisterQueue.Output();
	std::cout << "-----------------------------------------------------------\n";

};