#ifndef BCDH
#define BCDH

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include <stddef.h>
#include <stdint.h>

//------------------------------------------------------------------------------
// function
//------------------------------------------------------------------------------
uint32_t BcdToBin(const uint8_t bcd[], uint8_t len);
uint8_t  BcdToBin1(uint8_t bcd);
void     BinToBcd(uint32_t bin, uint8_t bcd[], uint8_t len);
uint8_t  BinToBcd1(uint8_t bin);

#ifdef __cplusplus
}
#endif

#endif
