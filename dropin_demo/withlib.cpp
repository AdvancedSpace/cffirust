#include <iostream>
#include <random>

#ifdef USE_RUST_LIB
#include "rustlinalg.h"
#else
#include "clinalg.h"
#endif

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-2.0e-16, 2e16);

  /*
    Generate 2 vectors of size 3, compute the norm of their difference,
    repeat 50 million times, print the total of norms, and return.
   */
  uint i;
  double totals = 0; // Avoids optimizing out the loop.
  for (i = 0; i < 5e7; i++) {
    double a[] = {dis(gen), dis(gen), dis(gen)};
    double b[] = {dis(gen), dis(gen), dis(gen)};
    double o[] = {0, 0, 0};
    subv(a, b, o, 3);
    totals += norm(o, 3);
  }
  std::cout << totals << std::endl;
  return 0;
}
