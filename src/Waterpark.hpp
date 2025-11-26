#ifndef WATERPARK_H
#define WATERPARK_H

#include <simlib.h>
#include "Constants.hpp"

namespace Waterpark {
  inline Store Capacity("Waterpark Capacity", DEFAULT_CAPACITY);
  inline bool summerMode = false;
  inline Facility SummerEntry[SUMMER_ENTRY_REGISTER_CNT];
  inline Queue SummerEntryQueue;
};

#endif