#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include <simlib.h>

namespace Waterpark {

inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);  // Waterpark capacity
inline bool summerMode = false;                                 // Whether waterpark is in summer mode

// Entries
inline Facility SummerEntry[SUMMER_ENTRY_REGISTER_CNT];         // Summer entry with registers
inline Facility MainEntry[MAIN_ENTRY_REGISTER_CNT];             // Main entry for visitors without ticket
inline Facility SmartRegisterEntry[MAIN_ENTRY_SMART_CNT];       // Smart register entry for visitors with ticket

// Queues for each entry
inline Queue SummerEntryQueue;                                  
inline Queue MainEntryQueue;
inline Queue SmartRegisterQueue;

// Statistics
inline int moneyMade = 0;
inline Stat QueueWaitTime[SIM_HOURS];

}; // namespace Waterpark

#endif