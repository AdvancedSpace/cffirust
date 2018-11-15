#include <math.h>
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
