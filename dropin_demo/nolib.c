#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double norm(const double vector[], const uint vsize) {
  double val = 0;
  ushort i;
  for (i = 0; i < vsize; i++) {
    val += vector[i] * vector[i];
  }
  return sqrt(val);
}

void subv(const double A[], const double B[], double C[], const uint vsize) {
  ushort i;
  for (i = 0; i < vsize; i++) {
    C[i] = A[i] - B[i];
  }
}

int main() {
  time_t t;
  srand((unsigned)time(&t));

  /*
    Generate 100 million vectors of size 3, sub two adjacent generations
    compute the norm, print the total of norms, and return.
   */
  uint i;
  double totals = 0; // Avoids optimizing out the loop.
  for (i = 0; i < 5e7; i++) {
    double a[] = {rand(), rand(), rand()};
    double b[] = {rand(), rand(), rand()};
    double o[] = {0, 0, 0};
    subv(a, b, o, 3);
    totals += norm(o, 3);
  }
  printf("%f\n", totals);
  return (0);
}
