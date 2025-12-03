#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include "Arguments.hpp"
#include <simlib.h>
#include <iostream>
#include <vector>

namespace Waterpark {

inline Histogram arrivalHist("Visitor Arrivals per Hour", 8, 1, 13);
inline Histogram departureHist("Visitor Departures per Hour", 8, 1, 13);
inline Histogram entryHist("Visitor entires into the waterpark per Hour", 8, 1, 13);

inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);  // Waterpark capacity
inline Queue CapacityQueue;
inline bool summerMode = false;                                 // Whether waterpark is in summer mode
inline bool holidayMode = false;                                // Whether waterpark is in holiday mode
inline bool forceSummerEntry = false;                           // Flag needed for an experiment
inline double visitorScale = 1.0;                   

// Entries
inline std::vector<Facility*> SummerEntry;
inline std::vector<Facility*> MainEntry;
inline std::vector<Facility*> SmartRegisterEntry;
inline std::vector<Facility*> SummerSmartRegisterEntry;

inline int SummerEntryCnt;
inline int MainEntryCnt;
inline int SmartRegisterEntryCnt;
inline int SummerSmartRegisterEntryCnt;

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

void initialize(const Config& config);

void cleanup();

}; // namespace Waterpark

#endif