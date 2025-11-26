#include "Arguments.hpp"
#include <cstdlib>
#include "Waterpark.hpp"
#include "Arrivals.hpp"
#include <ctime>

int main(int argc, char** argv) {

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

  RandomSeed(time(NULL));
  Init(START_TIME_SIMULATION, END_TIME_SIMULATION);
  Arrivals* arrivals = new Arrivals(args.summerMode, args.holiday);
  arrivals->Activate();
  
  Run();
  
  arrivals->arrivalHist.Output();

  return EXIT_SUCCESS;
}