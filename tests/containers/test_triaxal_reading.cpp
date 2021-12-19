#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/triaxal_reading.hpp>

bool approxEqual(float value, float expected) {
  return (expected > (value - 0.02f)) && (expected < (value + 0.02f));
}

TEST_CASE("Set and fetch") {
  auto reading = TriaxalReading(1, 2, 3);
  CHECK_EQ(1, reading.x());
  CHECK_EQ(2, reading.y());
  CHECK_EQ(3, reading.z());
}

TEST_CASE("Checking raw data") {
  auto reading = TriaxalReading(4, 5, 6);
  auto raw = reading.bytes();
  CHECK_EQ(4, *reinterpret_cast<float*>(&raw[0]));
  CHECK_EQ(5, *reinterpret_cast<float*>(&raw[4]));
  CHECK_EQ(6, *reinterpret_cast<float*>(&raw[8]));
}

TEST_CASE("Getting container length") {
  auto reading = TriaxalReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}

TEST_CASE("Static compiled size") {
  auto reading = TriaxalReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}

TEST_CASE("Normailsed reading") {
  SUBCASE("Valid values") {
    auto reading = TriaxalReading(0.24, 233.5, -13.6);
    auto norm = reading.normalise();
    CHECK(approxEqual(norm.x(), 0.00102609f));
    CHECK(approxEqual(norm.y(), 0.998307f));
    CHECK(approxEqual(norm.z(), -0.05814f));
  }
}