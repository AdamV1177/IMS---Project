#include "Arguments.hpp"
#include <cstdlib>
#include "Waterpark.hpp"

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

  return EXIT_SUCCESS;
}