#include "Arguments.hpp"
#include <getopt.h>
#include <iostream>

Arguments::Result Arguments::parse(int argc, char **argv) {

	// Parse command line arguments
	int opt;
	while ((opt = getopt(argc, argv, OPTSTRING)) != -1) {
		opterr = 0; // Disable default getopt errors

		switch (opt) {
		// Summer mode
		case 's':
			this->summerMode = true;
			break;

		// Weekend/national holiday mode
		case 'w':
			this->holiday = true;
			break;

		// Help text
		case 'h':
			printUsage();
			return HELP;

		// Missing required value
		case ':':
			std::cerr << "Missing required value for option -" << (char)optopt << std::endl;
			printUsage();
			return ERROR;

		// Unknown option
		case '?':
			std::cerr << "Unknown option -" << (char)optopt << std::endl;
			printUsage();
			return ERROR;
		}
	}

	return SUCCESS;
}

void Arguments::printUsage() {
	std::cout << "\nUsage: ./aqualand [-h] [-w] [-s]\n\n";
	std::cout << "Options:\n";
	std::cout << "\t-h: Prints this message.\n";
	std::cout << "\t-w: Runs the model in weekend/national holiday mode.\n";
	std::cout << "\t-s: Runs the model in summer mode.\n";
}