#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <algorithms/spacial_conversions.hpp>

using namespace SpacialConversions;
using namespace Rotation;

bool approxEqual(float value, float expected) {
  return (expected > (value - 0.02f)) && (expected < (value + 0.02f));
}

TEST_CASE("Euler to quarternion") {
  auto x = Angle::degrees(0);
  auto y = Angle::degrees(0);
  auto z = Angle::degrees(0);
  float qw, qx, qy, qz;
  auto quart = Quarternion();

  SUBCASE("No rotation") {
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 1;
    qx = 0;
    qy = 0;
    qz = 0;
  }

  SUBCASE("X at 90") {
    x = Angle::degrees(90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = std::sqrt(2) / 2.f;
    qy = 0;
    qz = 0;
  }

  SUBCASE("Y at 90") {
    y = Angle::degrees(90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = std::sqrt(2) / 2.f;
    qz = 0;
  }

  SUBCASE("Z at 90") {
    z = Angle::degrees(90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = 0;
    qz = std::sqrt(2) / 2.f;
  }

  SUBCASE("X at -90") {
    x = Angle::degrees(-90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = -std::sqrt(2) / 2.f;
    qy = 0;
    qz = 0;
  }

  SUBCASE("Y at -90") {
    y = Angle::degrees(-90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = -std::sqrt(2) / 2.f;
    qz = 0;
  }

  SUBCASE("Z at -90") {
    z = Angle::degrees(-90);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = 0;
    qz = -std::sqrt(2) / 2.f;
  }

  SUBCASE("X at 180") {
    x = Angle::degrees(180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = 1;
    qy = 0;
    qz = 0;
  }

  SUBCASE("Y at 180") {
    y = Angle::degrees(180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = 0;
    qy = 1;
    qz = 0;
  }

  SUBCASE("Z at 180") {
    z = Angle::degrees(180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = 0;
    qy = 0;
    qz = 1;
  }

  SUBCASE("X at -180") {
    x = Angle::degrees(-180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = -1;
    qy = 0;
    qz = 0;
  }

  SUBCASE("Y at -180") {
    y = Angle::degrees(-180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = 0;
    qy = -1;
    qz = 0;
  }

  SUBCASE("Z at -180") {
    z = Angle::degrees(-180);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
    qw = 0;
    qx = 0;
    qy = 0;
    qz = -1;
  }

  SUBCASE("X, Y and Z at 45") {
    x = Angle::degrees(45);
    y = Angle::degrees(45);
    z = Angle::degrees(45);
    auto euler = Euler(x, y, z);
    quart = euler2Quarternion(euler);
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

TEST_CASE("Quarternion to euler") {
  float qw = 1;
  float qx = 0;
  float qy = 0;
  float qz = 0;
  auto euler = Euler();
  float x = 0;
  float y = 0;
  float z = 0;

  SUBCASE("No rotation") {
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("X at 90") {
    qw = std::sqrt(2) / 2.f;
    qx = std::sqrt(2) / 2.f;
    qy = 0;
    qz = 0;
    x = 90;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("Y at 90") {
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = std::sqrt(2) / 2.f;
    qz = 0;
    y = 90;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("Z at 90") {
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = 0;
    qz = std::sqrt(2) / 2.f;
    z = 90;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("X at -90") {
    x = -90;
    qw = std::sqrt(2) / 2.f;
    qx = -std::sqrt(2) / 2.f;
    qy = 0;
    qz = 0;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("Y at -90") {
    y = -90;
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = -std::sqrt(2) / 2.f;
    qz = 0;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("Z at -90") {
    z = -90;
    qw = std::sqrt(2) / 2.f;
    qx = 0;
    qy = 0;
    qz = -std::sqrt(2) / 2.f;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  SUBCASE("X, Y and Z at 45") {
    qw = 0.8446;
    qx = 0.1913;
    qy = 0.4619;
    qz = 0.1913;
    x = 45;
    y = 45;
    z = 45;
    auto quart = Quarternion(qw, qx, qy, qz);
    euler = quarternion2Euler(quart);
  }

  CHECK(approxEqual(x, euler.x().degrees()));
  CHECK(approxEqual(y, euler.y().degrees()));
  CHECK(approxEqual(z, euler.z().degrees()));
}