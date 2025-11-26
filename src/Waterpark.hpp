#ifndef WATERPARK_H
#define WATERPARK_H

#include "Constants.hpp"
#include <simlib.h>

namespace Waterpark {
    inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);
    inline bool summerMode = false;
    inline Facility SummerEntry[SUMMER_ENTRY_REGISTER_CNT];
    inline Facility MainEntry[MAIN_ENTRY_REGISTER_CNT];
    inline Facility SmartRegisterEntry[MAIN_ENTRY_SMART_CNT];
    inline Queue SummerEntryQueue;
    inline Queue MainEntryQueue;
    inline Queue SmartRegisterQueue;

    // Statistics
    inline int moneyMade = 0;

};

#endif