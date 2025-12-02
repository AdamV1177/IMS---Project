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

void outputStatistics();

}; // namespace Waterpark

#endif