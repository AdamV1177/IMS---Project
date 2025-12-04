#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include "Constants.hpp"

#define OPTSTRING ":shwm:r:t:v:o"

struct Config {
    // Entry register counts
    int summerEntryRegisterCnt = SUMMER_ENTRY_REGISTER_CNT;
    int summerEntrySmartCnt = SUMMER_ENTRY_SMART_CNT;
    int mainEntrySmartCnt = MAIN_ENTRY_SMART_CNT;          
    int mainEntryRegisterCnt = MAIN_ENTRY_REGISTER_CNT;      

	double visitorScale = 1.0;	// Scaling of incoming visitors
    
    // Waterpark mode flags
    bool summerMode = false;
    bool holiday = false;
	bool forceSummerEntry = false;
};

struct Arguments {
	Config config;	// Parsed configuration of watepark (see above)

	// Possible argument parsing results
	enum Result {
		ERROR = -1,
		SUCCESS,
		HELP,
	};

	Result parse(int argc, char **argv); // Function parsing command line arguments

	void printUsage(); // Function outputting program usage help

};

#endif