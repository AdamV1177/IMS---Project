#include "Arguments.hpp"
#include "Arrivals.hpp"
#include "OpeningTime.hpp"
#include "Waterpark.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char **argv) {

	// Parse command line arguments
	Arguments args;
	Arguments::Result parseRes = args.parse(argc, argv);

	if (parseRes == Arguments::HELP)
		return EXIT_SUCCESS;
	else if (parseRes == Arguments::ERROR)
		return EXIT_FAILURE;

	// Set summer mode and capacity
	Waterpark::summerMode = args.summerMode;
	if (Waterpark::summerMode)
		Waterpark::Capacity.SetCapacity(SUMMER_CAPACITY);

	// Initialize and run simulation
	RandomSeed(time(NULL));
	Init(START_TIME_SIMULATION, END_TIME_SIMULATION);
	(new Arrivals(args.summerMode, args.holiday))->Activate();
	(new OpeningTime)->Activate(OPENING_TIME);
	Run();

	// Statistic outputs
	std::cout << "-------------------------MONEY MADE------------------------\n";
	std::cout << "Money made: " << Waterpark::moneyMade << " Kč" << std::endl;
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "\n-------------------------ARRIVAL HISTOGRAM------------------------\n";
	arrivalHist.Output();
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "\n-------------------------TIME IN QUEUE------------------------\n";
	for (int i = 0; i < SIM_HOURS; i++){
		std::cout << "Mean time in queue when arriving at " << i + 9 << ": ";
		if (Waterpark::QueueWaitTime[i].Number() != 0)
			std::cout << Waterpark::QueueWaitTime[i].MeanValue() << " minutes" << std::endl;
		else 
			std::cout << "No arrivals at this hour" << std::endl;
	}
	std::cout << "-----------------------------------------------------------\n";

	return EXIT_SUCCESS;
}