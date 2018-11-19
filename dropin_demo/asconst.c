#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef USE_RUST_LIB
#include "rustlinalg.h"
#else
#include "clinalg.h"
#endif

int main() {
  time_t t;
  srand((unsigned)time(&t));

  /*
    Generate 2 vectors of size 3, compute the norm of their difference,
    repeat 50 million times, print the total of norms, and return.
   */
  uint i;
  double totals = 0; // Avoids optimizing out the loop.
  for (i = 0; i < 5e7; i++) {
    double a[] = {2.0, 5.0, 6.0};
    double b[] = {3.0, 4.0, 7.0};
    double o[] = {0, 0, 0};
    subv(a, b, o, 3);
    totals += norm(o, 3);
  }
  printf("%f\n", totals);
  return 0;
}
