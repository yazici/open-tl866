#ifndef AT28_H
#define AT28_H

#include "ezzif.h"

/// Sets up all pins for the PLCC package.
void at28_plcc_setup();

unsigned char at28_read(unsigned int addr);

// Flip clock pin directly from TL866
#define at28_pin_flip_clock() \
  do {                        \
    PORTE ^= 0x4;             \
  } while (0)

#endif
