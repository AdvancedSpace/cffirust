#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

double norm(const double vector[]) {
  double val = 0;
  ushort i;
  for (i = 0; i < 3; i++) {
    val += vector[i] * vector[i];
  }
  return sqrt(val);
}

void subv(const double A[], const double B[], double C[]) {
  ushort i;
  for (i = 0; i < 3; i++) {
    C[i] = A[i] - B[i];
  }
}
