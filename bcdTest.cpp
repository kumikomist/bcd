#include "CppUTest/TestHarness.h"

#include "bcd.h"

// clang-format off
TEST_GROUP(bcd){
  TEST_SETUP(){
  }

  TEST_TEARDOWN(){
  }
};
// clang-format on

TEST(bcd, Test_BcdToBin)
{
  uint8_t  bcd[4];
  uint32_t bin;

  bcd[0] = 0x12;
  bcd[1] = 0x34;
  bcd[2] = 0x56;
  bcd[3] = 0x78;

  bin = BcdToBin(bcd, 1);
  UNSIGNED_LONGS_EQUAL(bin, 12);

  bin = BcdToBin(bcd, 2);
  UNSIGNED_LONGS_EQUAL(bin, 1234);

  bin = BcdToBin(bcd, 3);
  UNSIGNED_LONGS_EQUAL(bin, 123456);

  bin = BcdToBin(bcd, 4);
  UNSIGNED_LONGS_EQUAL(bin, 12345678);
}

TEST(bcd, Test_BcdToBin1)
{
  uint8_t bin;

  bin = BcdToBin1(0x00);
  UNSIGNED_LONGS_EQUAL(bin, 0);

  bin = BcdToBin1(0x12);
  UNSIGNED_LONGS_EQUAL(bin, 12);

  bin = BcdToBin1(0x34);
  UNSIGNED_LONGS_EQUAL(bin, 34);

  bin = BcdToBin1(0x56);
  UNSIGNED_LONGS_EQUAL(bin, 56);

  bin = BcdToBin1(0x78);
  UNSIGNED_LONGS_EQUAL(bin, 78);

  bin = BcdToBin1(0x99);
  UNSIGNED_LONGS_EQUAL(bin, 99);
}

TEST(bcd, Test_BinToBcd)
{
  uint8_t bcd[4];

  BinToBcd(1234, bcd, 4);
  UNSIGNED_LONGS_EQUAL(bcd[0], 0x00);
  UNSIGNED_LONGS_EQUAL(bcd[1], 0x00);
  UNSIGNED_LONGS_EQUAL(bcd[2], 0x12);
  UNSIGNED_LONGS_EQUAL(bcd[3], 0x34);
}

TEST(bcd, Test_BinToBcd1)
{
  uint8_t bcd;

  bcd = BinToBcd1(0);
  UNSIGNED_LONGS_EQUAL(bcd, 0x00);

  bcd = BinToBcd1(1);
  UNSIGNED_LONGS_EQUAL(bcd, 0x01);

  bcd = BinToBcd1(12);
  UNSIGNED_LONGS_EQUAL(bcd, 0x12);

  bcd = BinToBcd1(34);
  UNSIGNED_LONGS_EQUAL(bcd, 0x34);

  bcd = BinToBcd1(99);
  UNSIGNED_LONGS_EQUAL(bcd, 0x99);

  bcd = BinToBcd1(100);
  UNSIGNED_LONGS_EQUAL(bcd, 0xff);
}
