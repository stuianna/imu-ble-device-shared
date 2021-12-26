#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/rotation/quarternion.hpp>

TEST_CASE("Creating from units") {
  SUBCASE("Using no arg constructor") {
    auto reading = Rotation::Quarternion();
    CHECK_EQ(1.0f, reading.w());
    CHECK_EQ(0.0f, reading.x());
    CHECK_EQ(0.0f, reading.y());
    CHECK_EQ(0.0f, reading.z());
  }

  SUBCASE("Using specified units") {
    // Not actually a valid value
    auto reading = Rotation::Quarternion(1, 2, 3, 4);
    CHECK_EQ(1.0f, reading.w());
    CHECK_EQ(2.0f, reading.x());
    CHECK_EQ(3.0f, reading.y());
    CHECK_EQ(4.0f, reading.z());
  }
}

TEST_CASE("Conjugate") {
    auto reading = Rotation::Quarternion(1, 2, 3, 4);
    reading = reading.conjugate();
    CHECK(reading[0] == 1.0f);
    CHECK(reading[1] == -2.0f);
    CHECK(reading[2] == -3.0f);
    CHECK(reading[3] == -4.0f);
}

TEST_CASE("Operator overloading") {
  SUBCASE("Accessing elements with [] operator.") {
    auto reading = Rotation::Quarternion(1, 2, 3, 4);
    CHECK(reading[0] == 1.0f);
    CHECK(reading[1] == 2.0f);
    CHECK(reading[2] == 3.0f);
    CHECK(reading[3] == 4.0f);
  }

  SUBCASE("+ operator") {
    auto reading1 = Rotation::Quarternion(1, 2, 3, 4);
    auto reading2 = Rotation::Quarternion(1, 2, 3, 4);
    auto result = reading1 + reading2;
    CHECK(result[0] == 2.f);
    CHECK(result[1] == 4.f);
    CHECK(result[2] == 6.f);
    CHECK(result[3] == 8.f);
  }

  SUBCASE("- operator") {
    auto reading1 = Rotation::Quarternion(1, 2, 3, 4);
    auto reading2 = Rotation::Quarternion(1, 2, 3, 4);
    auto result = reading1 - reading2;
    CHECK(result[0] == 0.f);
    CHECK(result[1] == 0.f);
    CHECK(result[2] == 0.f);
    CHECK(result[3] == 0.f);
  }

  SUBCASE("* operator") {
    auto reading1 = Rotation::Quarternion(1, 2, 3, 4);
    auto reading2 = Rotation::Quarternion(1, 2, 3, 4);
    auto result = reading1 * reading2;
    CHECK(result[0] == -28.f);
    CHECK(result[1] == 4.f);
    CHECK(result[2] == 6.f);
    CHECK(result[3] == 8.f);
  }
}