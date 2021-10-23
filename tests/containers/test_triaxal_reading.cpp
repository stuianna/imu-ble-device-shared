#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/triaxal_reading.hpp>

TEST_CASE("Set and fetch") {}

void test_set_and_fetch(void) {
  auto reading = TriaxalReading(1, 2, 3);
  CHECK_EQ(1, reading.x());
  CHECK_EQ(2, reading.y());
  CHECK_EQ(3, reading.z());
}

TEST_CASE("Checking raw data") {}

void test_raw_data(void) {
  auto reading = TriaxalReading(4, 5, 6);
  auto raw = reading.bytes();
  CHECK_EQ(4, *reinterpret_cast<float *>(&raw[0]));
  CHECK_EQ(5, *reinterpret_cast<float *>(&raw[4]));
  CHECK_EQ(6, *reinterpret_cast<float *>(&raw[8]));
}

TEST_CASE("Getting container length") {}

void test_get_length() {
  auto reading = TriaxalReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}

TEST_CASE("Static compiled size") {}

void test_sizeof() {
  auto reading = TriaxalReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}