#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include "Arguments.hpp"
#include <simlib.h>
#include <iostream>
#include <vector>

namespace Waterpark {

inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);  // Waterpark capacity
inline bool summerMode = false;                                 // Whether waterpark is in summer mode
inline bool holidayMode = false;                                // Whether waterpark is in holiday mode
inline bool forceSummerEntry = false;                           // Flag needed for an experiment
inline double visitorScale = 1.0;                               // Multiplier for incoming visitors

// Entries
inline std::vector<Facility*> SummerEntry;
inline std::vector<Facility*> MainEntry;
inline std::vector<Facility*> SmartRegisterEntry;
inline std::vector<Facility*> SummerSmartRegisterEntry;

// Number of registers at all entries
inline int SummerEntryCnt;
inline int MainEntryCnt;
inline int SmartRegisterEntryCnt;
inline int SummerSmartRegisterEntryCnt;

// Queues for each entry
inline Queue SummerEntryQueue;                                  
inline Queue MainEntryQueue;
inline Queue MainSmartQueue;
inline Queue SummerSmartQueue;
inline Queue CapacityQueue;     // Queue for a situation, where the aquapark capacity is filled


// Statistics
inline Histogram arrivalHist("Visitor Arrivals per Hour", 8, 1, 13);
inline Histogram departureHist("Visitor Departures per Hour", 8, 1, 13);
inline Histogram entryHist("Visitor entires into the waterpark per Hour", 8, 1, 13);
inline int moneyMade = 0;
inline Stat QueueWaitTime[SIM_HOURS];
inline int Occupancy[SIM_HOURS];
inline Histogram TimeInWaterpark("Hours Spent in Waterpark", 0, 1, SIM_HOURS);

void outputStatistics();    // Function printing all statistics to stdout

void initialize(const Config& config);  // Functiopn initializing waterpark state with given config 

void cleanup(); // Memory cleanup

}; // namespace Waterpark

#endif