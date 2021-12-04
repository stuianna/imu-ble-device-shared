#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/rotation_euler.hpp>

TEST_CASE("Creating from angles") {
  SUBCASE("Angles within bounds") {
    auto reading = RotationEuler(1, 2, 3);
    SUBCASE("Getting x,y,z angles.") {
      CHECK_EQ(1, reading.x());
      CHECK_EQ(2, reading.y());
      CHECK_EQ(3, reading.z());
    }

    SUBCASE("Getting yaw, pitch, roll") {
      CHECK_EQ(1, reading.roll());
      CHECK_EQ(2, reading.pitch());
      CHECK_EQ(3, reading.yaw());
    }
  }

  SUBCASE("Angles out of bounds") {
    SUBCASE("X Axis") {
      SUBCASE("Below -180 degrees") {
        auto reading = RotationEuler(-180.1f, 2, 3);
        CHECK_EQ(179.9f, reading.x());
      }

      SUBCASE("Above 180 degrees") {
        auto reading = RotationEuler(180.1f, 2, 3);
        CHECK_EQ(-179.9f, reading.x());
      }

      SUBCASE("Multiple rotations above (even)") {
        auto reading = RotationEuler(520.f, 2, 3);
        CHECK_EQ(160.f, reading.x());
      }

      SUBCASE("Multiple rotations above (odd)") {
        auto reading = RotationEuler(550.f, 2, 3);
        CHECK_EQ(-170.f, reading.x());
      }

      SUBCASE("Multiple rotations below (even)") {
        auto reading = RotationEuler(-510.f, 2, 3);
        CHECK_EQ(-150.f, reading.x());
      }

      SUBCASE("Multiple rotations below (odd)") {
        auto reading = RotationEuler(-560.f, 2, 3);
        CHECK_EQ(160.f, reading.x());
      }
    }
  }
}