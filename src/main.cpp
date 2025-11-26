#include "Arguments.hpp"
#include <cstdlib>

int main(int argc, char** argv) {

  // Parse command line arguments
  Arguments args;
  Arguments::Result parseRes = args.parse(argc, argv);

  if (parseRes == Arguments::HELP)
    return EXIT_SUCCESS;
  else if (parseRes == Arguments::ERROR)
    return EXIT_FAILURE;

  // TODO Start simulation

  return EXIT_SUCCESS;
}