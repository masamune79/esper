#ifndef ESPER64
#define ESPER64
#endif

#include <inttypes.h>

typedef union _ULARGE_INTEGER64 {
  struct {
    uint32_t low;
    uint32_t high;
  };
  uint64_t qword_part;
}ULARGE_INTEGER64;

static uint64_t esp64state = 0;
 
void init_esper64(uint64_t qwseed) {
  if (qwseed != 0) { esp64state = qwseed; }
  else { esp64state = 65535; }
  return;
}

uint64_t esper64(void) {
  ULARGE_INTEGER64 lpdata = {0};
  lpdata.qword_part = esp64state;
  
  lpdata.low ^= (lpdata.low | (lpdata.high >> 16));
  lpdata.high ^= (lpdata.low | (lpdata.qword_part >> 16));
  
  return (uint64_t)(esp64state += ((esp64state += 0x7ffffffff) ^ (lpdata.qword_part << lpdata.high)));
}
