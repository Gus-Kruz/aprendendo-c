#include "grains.h"

uint64_t square(uint8_t index)
{
    return 1ULL << (index - 1);
}

uint64_t total(void)
{
    return (1ULL << 64) - 1;
}