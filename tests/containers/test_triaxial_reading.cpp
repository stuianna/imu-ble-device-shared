#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/triaxial_reading.hpp>

bool approxEqual(float value, float expected) {
  return (expected > (value - 0.02f)) && (expected < (value + 0.02f));
}

TEST_CASE("Set and fetch") {
  auto reading = TriaxialReading(1, 2, 3);
  CHECK_EQ(1, reading.x());
  CHECK_EQ(2, reading.y());
  CHECK_EQ(3, reading.z());
}

TEST_CASE("Checking raw data") {
  auto reading = TriaxialReading(4, 5, 6);
  auto raw = reading.bytes();
  CHECK_EQ(4, *reinterpret_cast<float*>(&raw[0]));
  CHECK_EQ(5, *reinterpret_cast<float*>(&raw[4]));
  CHECK_EQ(6, *reinterpret_cast<float*>(&raw[8]));
}

TEST_CASE("Getting container length") {
  auto reading = TriaxialReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}

TEST_CASE("Static compiled size") {
  auto reading = TriaxialReading(4.234, 2332.5, -123.6);
  CHECK_EQ(12, sizeof(reading));
}

TEST_CASE("Normailsed reading") {
  SUBCASE("Valid values") {
    auto reading = TriaxialReading(0.24, 233.5, -13.6);
    auto norm = reading.normalise();
    CHECK(approxEqual(norm.x(), 0.00102609f));
    CHECK(approxEqual(norm.y(), 0.998307f));
    CHECK(approxEqual(norm.z(), -0.05814f));
  }
}

TEST_CASE("Check if empty.") {
  SUBCASE("Initialised value") {
    auto reading = TriaxialReading();
    CHECK_EQ(reading.empty(), true);
  }
}

TEST_CASE("Operator overloading") {
  SUBCASE("Accessing elements with [] operator.") {
    auto reading = TriaxialReading(4.234, 2332.5, -123.6);
    CHECK(reading[0] == 4.234f);
    CHECK(reading[1] == 2332.5);
    CHECK(reading[2] == -123.6f);
  }

  SUBCASE("+ operator") {
    auto reading1 = TriaxialReading(1, 2, 3);
    auto reading2 = TriaxialReading(1, 2, 3);
    auto result = reading1 + reading2;
    CHECK(result[0] == 2.f);
    CHECK(result[1] == 4.f);
    CHECK(result[2] == 6.f);
  }

  SUBCASE("- operator") {
    auto reading1 = TriaxialReading(1, 2, 3);
    auto reading2 = TriaxialReading(1, 2, 3);
    auto result = reading1 - reading2;
    CHECK(result[0] == 0.f);
    CHECK(result[1] == 0.f);
    CHECK(result[2] == 0.f);
  }
}