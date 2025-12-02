#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#define OPTSTRING ":shwm:r:t:"


struct Config {
    // Entry register counts
    int summerEntryRegisterCnt = 3;
    int summerEntrySmartCnt = 3;         
    int mainEntrySmartCnt = 8;          
    int mainEntryRegisterCnt = 6;       
    
    // Mode flags
    bool summerMode = false;
    bool holiday = false;
};

struct Arguments {
	Config config;
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