#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
  // Let's initialize all of the variables here, and define them later.
  double outvec[3], invec1[2], invec2[3], this_norm;

  // Assume the following vectors come from another computation.
  invec1[0] = 3.0;
  invec1[1] = 4.0;
  invec1[2] = 5.0;

  invec2[0] = 6.0;
  invec2[1] = 7.0;
  invec2[2] = 8.0;

  // We know that the difference between these vectors should be [3.0, 3.0, 3.0]
  // whose norm is 3*sqrt(3).

  subv(invec1, invec2, outvec, 3);
  this_norm = norm(outvec, 3);

  printf("%p\n%p\n", &(invec1[2]), &(invec2[0]));
  printf("%f\n", this_norm);
  return 0;
}
