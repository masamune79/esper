#ifndef ESPER32
#define ESPER32
#endif

#include <inttypes.h>

typedef union _ULARGE_INTEGER32 {
  struct {
    uint16_t low;
    uint16_t high;
  };
  uint32_t dword_part;
}ULARGE_INTEGER32, *LPULARGE_INTEGER32;

static uint32_t esp32state = 0;
 
void init_esper32(uint32_t dwseed) {
  if (dwseed != 0) { esp32state = dwseed; }
  else { esp32state = 65535; }
  return;
}

uint32_t esper32(void) {
  ULARGE_INTEGER32 lpdata = {0};
  lpdata.dword_part = esp32state;
  
  lpdata.low ^= (lpdata.low | (((lpdata.high) >> 8) & 0xff));
  lpdata.high ^= (lpdata.low | (lpdata.low >> 8));
  
  return (uint32_t)(esp32state += ((esp32state += 0x7ffff) ^ (lpdata.dword_part >> lpdata.high)));
}
