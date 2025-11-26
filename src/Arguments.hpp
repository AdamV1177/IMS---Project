#ifndef ARGUMENTS_H
#define ARGUMENTS_H

// Options -s, -h, -w
#define OPTSTRING ":swh"

struct Arguments {

	// Initial values
	bool summerMode = false;
	bool holiday = false;

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