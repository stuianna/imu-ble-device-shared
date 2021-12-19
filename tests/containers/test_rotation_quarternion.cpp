#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/rotation_quarternion.hpp>

TEST_CASE("Creating from units") {
  SUBCASE("Using no arg constructor") {
    auto reading = RotationQuarternion();
    CHECK_EQ(1.0f, reading.w());
    CHECK_EQ(0.0f, reading.x());
    CHECK_EQ(0.0f, reading.y());
    CHECK_EQ(0.0f, reading.z());
  }

  SUBCASE("Using specified units") {
    // Not actually a valid value
    auto reading = RotationQuarternion(1, 2, 3, 4);
    CHECK_EQ(1.0f, reading.w());
    CHECK_EQ(2.0f, reading.x());
    CHECK_EQ(3.0f, reading.y());
    CHECK_EQ(4.0f, reading.z());
  }
}