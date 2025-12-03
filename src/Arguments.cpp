#include "Arguments.hpp"
#include <getopt.h>
#include <iostream>
#include <string>

Arguments::Result Arguments::parse(int argc, char **argv) {

	// Parse command line arguments
	int opt;
	while ((opt = getopt(argc, argv, OPTSTRING)) != -1) {
		opterr = 0; // Disable default getopt errors

		switch (opt) {
		// Summer mode
		case 's':
			config.summerMode = true;
			break;

		// Weekend/national holiday mode
		case 'w':
			config.holiday = true;
			break;

		// Main entry registers: -m <regular>,<smart>
		case 'm': {
            int regular, smart;
            if (sscanf(optarg, "%d,%d", &regular, &smart) == 2) {
                if (regular >= 0 && smart >= 0) {
                    config.mainEntryRegisterCnt = regular;
                    config.mainEntrySmartCnt = smart;
                } else {
                    std::cerr << "Error: Register counts must be positive\n";
                    return ERROR;
                }
            } else {
                std::cerr << "Error: Invalid format for -m. Use: -m <regular>,<smart>\n";
                printUsage();
                return ERROR;
            }
            break;
        }

        // Summer entry registers: -r <regular>,<smart>
        case 'r': {
            int regular, smart;
            if (sscanf(optarg, "%d,%d", &regular, &smart) == 2) {
                if (regular >= 0 && smart >= 0) {
                    config.summerEntryRegisterCnt = regular;
                    config.summerEntrySmartCnt = smart;
                } else {
                    std::cerr << "Error: Register counts must be positive\n";
                    return ERROR;
                }
            } else {
                std::cerr << "Error: Invalid format for -r. Use: -r <regular>,<smart>\n";
                printUsage();
                return ERROR;
            }
            break;
        }

		// Help text
		case 'h':
			printUsage();
			return HELP;
			

		// Visitor scale
		case 'v':
			try {
				this->config.visitorScale = std::stof(optarg);
				if (this->config.visitorScale < 0) {
					std::cerr << "Only provide non-negative values to -v: " << optarg << std::endl;
					printUsage();
					return ERROR;
				}
				break;
			}
			catch(const std::invalid_argument&) {
				std::cerr << "Invalid float passed to -v: " << optarg << std::endl;
				printUsage();
				return ERROR;
			}
			catch(const std::out_of_range&) {
				std::cerr << "Float out of range for -v: " << optarg << "\n";
				printUsage();
				return ERROR;
			}

		// Open summer entry in non-mode
		case 'o':
			config.forceSummerEntry = true;
			break;

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
    std::cout << "\nUsage: ./aqualand [OPTIONS]\n\n";
    std::cout << "Options:\n";
    std::cout << "  -h              Show this help message\n";
    std::cout << "  -w              Weekend/national holiday mode\n";
    std::cout << "  -s              Summer mode\n";
    std::cout << "  -m <reg>,<smart> Main entry registers (default: 6,8)\n";
    std::cout << "  -r <reg>,<smart> Summer entry registers (default: 3,3)\n";
    std::cout << "  -v <visitor_scale> Multiplier, with which to scale the incoming visitor counts (default: 1.0)\n";
    std::cout << "\nExamples:\n";
    std::cout << "  ./aqualand -s -m 8,10        # Summer mode with 8 regular, 10 smart at main\n";
    std::cout << "  ./aqualand -w -s -r 4,4 -m 8,12 # Summer weekend with custom registers\n";
    std::cout << "  ./aqualand -v 0.5 # The incoming amount of visitor halves\n";
}