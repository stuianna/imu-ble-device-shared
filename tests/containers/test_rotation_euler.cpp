#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/rotation_euler.hpp>

TEST_CASE("Creating from angles") {
  SUBCASE("Angles within bounds") {
    auto reading = RotationEuler(Angle::degrees(1), Angle::degrees(2), Angle::degrees(3));
    SUBCASE("Getting x,y,z angles.") {
      CHECK_EQ(1.f, reading.x().degrees());
      CHECK_EQ(2.f, reading.y().degrees());
      CHECK_EQ(3.f, reading.z().degrees());
    }

    SUBCASE("Getting yaw, pitch, roll") {
      CHECK_EQ(1.f, reading.roll().degrees());
      CHECK_EQ(2.f, reading.pitch().degrees());
      CHECK_EQ(3.f, reading.yaw().degrees());
    }

    SUBCASE("Fetching byte array") {
      CHECK_EQ(reading.length(), 12);
      uint8_t* bytes = reading.bytes();
      CHECK_EQ(*reinterpret_cast<float*>(&bytes[0]), 1.f);
      CHECK_EQ(*reinterpret_cast<float*>(&bytes[4]), 2.f);
      CHECK_EQ(*reinterpret_cast<float*>(&bytes[8]), 3.f);
    }
  }
}