#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "Constants.hpp"

struct Parameters {
    int summerRegisterCnt = SUMMER_ENTRY_REGISTER_CNT;
    int summerSmartCnt = SUMMER_ENTRY_SMART_CNT;
    int mainRegisterCnt = MAIN_ENTRY_REGISTER_CNT;
    int mainSmartCnt = MAIN_ENTRY_SMART_CNT;
    double visitorScale = 1.0;
};

#endif