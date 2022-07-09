#include <stdio.h>
#include <inttypes.h>
#include <time.h>

#include "esper32.h"
#include "esper64.h"

int main(int argc, char *argv[]) {
  init_esper32((uint32_t)time(0));
  init_esper64((uint64_t)time(0));
  
  printf("esper32 test\n");
  int i = 0;
  for (; i < 100; i++) {
  printf("%" PRIu32 "\n", esper32());
  }
  
  printf("esper64 test\n");
  for (i = 0; i < 100; i++) {
    printf("%" PRIu64 "\n", esper64());
  }
  return 0;
}
