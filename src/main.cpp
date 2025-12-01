#include "Arguments.hpp"
#include "Arrivals.hpp"
#include "OpeningTime.hpp"
#include "Waterpark.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "OccupancySampler.hpp"

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
	Waterpark::holidayMode = args.holiday;
	if (Waterpark::summerMode)
		Waterpark::Capacity.SetCapacity(SUMMER_CAPACITY);

	// Initialize and run simulation
	RandomSeed(time(NULL));
	Init(START_TIME_SIMULATION, END_TIME_SIMULATION);
	(new Arrivals(args.summerMode, args.holiday))->Activate();
	(new OpeningTime)->Activate(OPENING_TIME);
	(new OccupancySampler)->Activate(START_TIME_SIMULATION + HOUR - 1);	// Start sampling occupancy at end of first hour
	Run();

	// Statistic outputs
	Waterpark::outputStatistics();

	return EXIT_SUCCESS;
}