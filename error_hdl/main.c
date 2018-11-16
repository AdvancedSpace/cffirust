#include <stdio.h>
#include <stdlib.h>

#define NO_ERROR -1
#define HAS_ERRORED 159

void read_tm1(int *errno, double *stor, const uint pos) {
  (*errno) = HAS_ERRORED;
}

void read_tm2(int *errno, double *stor, const uint pos) {
  (*errno) = NO_ERROR;
  stor[pos] = 753.12;
}

int main() {
  const uint num_tms = 2;
  uint cur_stor_pos = 0;
  int read_tm_errno;
  double read_tm_storage[num_tms];

  read_tm1(&read_tm_errno, read_tm_storage, cur_stor_pos);

  if (read_tm_errno == NO_ERROR) {
    printf("TM #1: no error -- value = %f\n", read_tm_storage[cur_stor_pos]);
  } else {
    printf("TM #1: errored -- no value to report\n");
  }
  cur_stor_pos++;

  read_tm2(&read_tm_errno, read_tm_storage, cur_stor_pos);

  if (read_tm_errno == NO_ERROR) {
    printf("TM #2: no error -- value = %f\n", read_tm_storage[cur_stor_pos]);
  } else {
    printf("TM #2: errored -- no value to report\n");
  }

  // At this point, nothing prevents a programmer from coding some logic based
  // on the value of telemetry reading, even if it has failed. This seemingly
  // minor error may have drastic consequences.

  // For example:
  printf("\nTo recap, all telemetry to be downlinked includes:\n");
  for (cur_stor_pos = 0; cur_stor_pos<num_tms; cur_stor_pos++) {
    // Will eventually use an uninitialized value.
    printf("TM #%d = %f\n", cur_stor_pos+1, read_tm_storage[cur_stor_pos]);
  }

  return 0;
}
