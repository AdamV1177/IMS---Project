#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include <simlib.h>
#include <iostream>

namespace Waterpark {

inline Histogram arrivalHist("Visitor Arrivals per Hour", 8, 1, 13);
inline Histogram departureHist("Visitor Departures per Hour", 8, 1, 13);
inline Histogram entryHist("Visitor entires into the waterpark per Hour", 8, 1, 13);

inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);  // Waterpark capacity
inline bool summerMode = false;                                 // Whether waterpark is in summer mode
inline bool holidayMode = false;                                // Whether waterpark is in holiday mode

// Entries
inline Facility SummerEntry[SUMMER_ENTRY_REGISTER_CNT];         // Summer entry with registers
inline Facility MainEntry[MAIN_ENTRY_REGISTER_CNT];             // Main entry for visitors without ticket
inline Facility SmartRegisterEntry[MAIN_ENTRY_SMART_CNT];       // Smart register entry for visitors with ticket
inline Facility SummerSmartRegisterEntry[SUMMER_ENTRY_SMART_CNT];       // Summer smart register entry for visitors with ticket

// Queues for each entry
inline Queue SummerEntryQueue;                                  
inline Queue MainEntryQueue;
inline Queue SmartRegisterQueue;
inline Queue SummerSmartRegisterQueue;

// Statistics
inline int moneyMade = 0;
inline Stat QueueWaitTime[SIM_HOURS];
inline int Occupancy[SIM_HOURS];
inline Histogram TimeInWaterpark("Hours Spent in Waterpark", 0, 1, SIM_HOURS);

inline void outputStatistics() {
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

}; // namespace Waterpark

#endif