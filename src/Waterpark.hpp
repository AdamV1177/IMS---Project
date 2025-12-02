#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include <simlib.h>
#include <iostream>
#include <vector>

namespace Waterpark {

inline Histogram arrivalHist("Visitor Arrivals per Hour", 8, 1, 13);
inline Histogram departureHist("Visitor Departures per Hour", 8, 1, 13);
inline Histogram entryHist("Visitor entires into the waterpark per Hour", 8, 1, 13);

inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);  // Waterpark capacity
inline bool summerMode = false;                                 // Whether waterpark is in summer mode
inline bool holidayMode = false;                                // Whether waterpark is in holiday mode

// Entries
inline std::vector<Facility> SummerEntry(SUMMER_ENTRY_REGISTER_CNT);
inline std::vector<Facility> MainEntry(MAIN_ENTRY_REGISTER_CNT);
inline std::vector<Facility> MainSmartEntry(MAIN_ENTRY_SMART_CNT);
inline std::vector<Facility> SummerSmartEntry(SUMMER_ENTRY_SMART_CNT);

// Queues for each entry
inline Queue SummerEntryQueue;                                  
inline Queue MainEntryQueue;
inline Queue MainSmartQueue;
inline Queue SummerSmartQueue;

// Statistics
inline int moneyMade = 0;
inline Stat QueueWaitTime[SIM_HOURS];
inline int Occupancy[SIM_HOURS];
inline Histogram TimeInWaterpark("Hours Spent in Waterpark", 0, 1, SIM_HOURS);

void outputStatistics();

}; // namespace Waterpark

#endif