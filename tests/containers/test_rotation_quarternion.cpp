#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/rotation_euler.hpp>
#include <containers/rotation_quarternion.hpp>

bool approxEqual(float value, float expected) {
  return (expected > (value - 0.01f)) && (expected < (value + 0.01f));
}

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

  SUBCASE("Construction from Euler") {
    auto x = Angle::degrees(0);
    auto y = Angle::degrees(0);
    auto z = Angle::degrees(0);
    float qw, qx, qy, qz;
    auto quart = RotationQuarternion();

    SUBCASE("No rotation") {
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 1;
      qx = 0;
      qy = 0;
      qz = 0;
      CHECK(qw == quart.w());
      CHECK(qx == quart.x());
      CHECK(qy == quart.y());
      CHECK(qz == quart.z());
    }

    SUBCASE("X at 90") {
      x = Angle::degrees(90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = std::sqrt(2) / 2.f;
      qy = 0;
      qz = 0;
    }

    SUBCASE("Y at 90") {
      y = Angle::degrees(90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = 0;
      qy = std::sqrt(2) / 2.f;
      qz = 0;
    }

    SUBCASE("Z at 90") {
      z = Angle::degrees(90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = 0;
      qy = 0;
      qz = std::sqrt(2) / 2.f;
    }

    SUBCASE("X at -90") {
      x = Angle::degrees(-90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = -std::sqrt(2) / 2.f;
      qy = 0;
      qz = 0;
    }

    SUBCASE("Y at -90") {
      y = Angle::degrees(-90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = 0;
      qy = -std::sqrt(2) / 2.f;
      qz = 0;
    }

    SUBCASE("Z at -90") {
      z = Angle::degrees(-90);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = std::sqrt(2) / 2.f;
      qx = 0;
      qy = 0;
      qz = -std::sqrt(2) / 2.f;
    }

    SUBCASE("X at 180") {
      x = Angle::degrees(180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = 1;
      qy = 0;
      qz = 0;
    }

    SUBCASE("Y at 180") {
      y = Angle::degrees(180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = 0;
      qy = 1;
      qz = 0;
    }

    SUBCASE("Z at 180") {
      z = Angle::degrees(180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = 0;
      qy = 0;
      qz = 1;
    }

    SUBCASE("X at -180") {
      x = Angle::degrees(-180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = -1;
      qy = 0;
      qz = 0;
    }

    SUBCASE("Y at -180") {
      y = Angle::degrees(-180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = 0;
      qy = -1;
      qz = 0;
    }

    SUBCASE("Z at -180") {
      z = Angle::degrees(-180);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0;
      qx = 0;
      qy = 0;
      qz = -1;
    }

    SUBCASE("X, Y and Z at 45") {
      x = Angle::degrees(45);
      y = Angle::degrees(45);
      z = Angle::degrees(45);
      auto euler = RotationEuler(x, y, z);
      quart = RotationQuarternion(euler);
      qw = 0.8446;
      qx = 0.1913;
      qy = 0.4619;
      qz = 0.1913;
    }

    CHECK(approxEqual(qw, quart.w()));
    CHECK(approxEqual(qx, quart.x()));
    CHECK(approxEqual(qy, quart.y()));
    CHECK(approxEqual(qz, quart.z()));
  }
}