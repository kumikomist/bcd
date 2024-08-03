/**
 * @file bcd.c
 * @brief BCD処理
 */

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include "bcd.h"

//------------------------------------------------------------------------------
// private variable
//------------------------------------------------------------------------------
static const uint8_t m_hex_high[10] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90};

/** ----------------------------------------------------------------------------
 * @brief BCDからバイナリーに変換
 *
 * @param [in] bcd : BCD
 * @param len : BCDバイト長
 * @return バイナリー
 */
uint32_t BcdToBin(const uint8_t bcd[], uint8_t len)
{
  uint32_t bin = 0;

  for (uint8_t i = 0; i < len; i++) {
    bin *= 100;
    bin += BcdToBin1(bcd[i]);
  }

  return bin;
}

/** ----------------------------------------------------------------------------
 * @brief BCDからバイナリーに変換 (1バイト)
 *
 * @param bcd : BCD
 * @return バイナリー
 */
uint8_t BcdToBin1(uint8_t bcd)
{
  uint8_t high, low;
  uint8_t bin;

  high = bcd >> 4;
  low  = bcd & 0x0F;
  bin  = high * 10 + low;

  return bin;
}

/** ----------------------------------------------------------------------------
 * @brief バイナリーからBCDに変換
 *
 * @param bin : バイナリー
 * @param [out] bcd : BCD
 * @param len : BCDバイト長
 */
void BinToBcd(uint32_t bin, uint8_t bcd[], uint8_t len)
{
  uint8_t high, low;

  for (uint8_t i = 0; i < len; i++) {
    low = bin % 10;
    bin /= 10;
    high = bin % 10;
    bin /= 10;
    bcd[len - i - 1] = m_hex_high[high] | low;
  }
}

/** ----------------------------------------------------------------------------
 * @brief バイナリーからBCDに変換 (1バイト)
 *
 * @param bin : バイナリー [0-99]
 * @return BCD (1バイト)
 */
uint8_t BinToBcd1(uint8_t bin)
{
  uint8_t bcd;

  if (bin < 10) {
    bcd = bin;
  } else if (bin < 20) {
    bcd = bin + 6;
  } else if (bin < 30) {
    bcd = bin + 12;
  } else if (bin < 40) {
    bcd = bin + 18;
  } else if (bin < 50) {
    bcd = bin + 24;
  } else if (bin < 60) {
    bcd = bin + 30;
  } else if (bin < 70) {
    bcd = bin + 36;
  } else if (bin < 80) {
    bcd = bin + 42;
  } else if (bin < 90) {
    bcd = bin + 48;
  } else if (bin < 100) {
    bcd = bin + 54;
  } else {
    bcd = 0xff;
  }

  return bcd;
}
