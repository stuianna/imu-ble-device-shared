#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/system_state.hpp>


TEST_CASE("Initial values") {
  SystemState state;
  CHECK_EQ(state.getAccelerometer().x(), 0.0f);
  CHECK_EQ(state.getAccelerometer().y(), 0.0f);
  CHECK_EQ(state.getAccelerometer().z(), 0.0f);
  CHECK_EQ(state.getGyroscope().x(), 0.0f);
  CHECK_EQ(state.getGyroscope().y(), 0.0f);
  CHECK_EQ(state.getGyroscope().z(), 0.0f);
  CHECK_EQ(state.getMagnometer().x(), 0.0f);
  CHECK_EQ(state.getMagnometer().y(), 0.0f);
  CHECK_EQ(state.getMagnometer().z(), 0.0f);
  CHECK_EQ(state.getEuler().x().degrees(), 0.0f);
  CHECK_EQ(state.getEuler().y().degrees(), 0.0f);
  CHECK_EQ(state.getEuler().z().degrees(), 0.0f);
  CHECK_EQ(state.getQuarternion().w(), 0.0f);
  CHECK_EQ(state.getQuarternion().x(), 0.0f);
  CHECK_EQ(state.getQuarternion().y(), 0.0f);
  CHECK_EQ(state.getQuarternion().z(), 0.0f);
  CHECK_EQ(state.length(), 64);
}

TEST_CASE("Getting and setting") {
  SystemState state;

  SUBCASE("Acccelerometer") {
    TriaxialReading acc(1, 2, 3);
    state.setAccelerometer(acc);
    CHECK_EQ(state.getAccelerometer().x(), 1.0f);
    CHECK_EQ(state.getAccelerometer().y(), 2.0f);
    CHECK_EQ(state.getAccelerometer().z(), 3.0f);
  }

  SUBCASE("Gyroscope") {
    TriaxialReading gyr(4, 5, 6);
    state.setGyroscope(gyr);
    CHECK_EQ(state.getGyroscope().x(), 4.0f);
    CHECK_EQ(state.getGyroscope().y(), 5.0f);
    CHECK_EQ(state.getGyroscope().z(), 6.0f);
  }

  SUBCASE("Magnometer") {
    TriaxialReading mag(7, 8, 9);
    state.setMagnometer(mag);
    CHECK_EQ(state.getMagnometer().x(), 7.0f);
    CHECK_EQ(state.getMagnometer().y(), 8.0f);
    CHECK_EQ(state.getMagnometer().z(), 9.0f);
  }

  SUBCASE("Euler Rotation") {
    Rotation::Euler euler(Angle::degrees(1), Angle::degrees(2), Angle::degrees(3));
    state.setEuler(euler);
    CHECK_EQ(state.getEuler().x().degrees(), 1.0f);
    CHECK_EQ(state.getEuler().y().degrees(), 2.0f);
    CHECK_EQ(state.getEuler().z().degrees(), 3.0f);
  }

  SUBCASE("Quarternion Rotation") {
    Rotation::Quarternion quarternion(1, 2, 3, 4);
    state.setQuarternion(quarternion);
    CHECK_EQ(state.getQuarternion().w(), 1.0f);
    CHECK_EQ(state.getQuarternion().x(), 2.0f);
    CHECK_EQ(state.getQuarternion().y(), 3.0f);
    CHECK_EQ(state.getQuarternion().z(), 4.0f);
  }
}

TEST_CASE("Setting from raw bytes") {
  SystemState original;
  TriaxialReading acc(1, 2, 3);
  TriaxialReading gyr(4, 5, 6);
  TriaxialReading mag(7, 8, 9);
  Rotation::Euler euler(Angle::degrees(1), Angle::degrees(2), Angle::degrees(3));
  Rotation::Quarternion quarternion(1, 2, 3, 4);

  original.setAccelerometer(acc);
  original.setGyroscope(gyr);
  original.setMagnometer(mag);
  original.setEuler(euler);
  original.setQuarternion(quarternion);

  SystemState copied(original.data(), original.length());
  CHECK_EQ(copied.getAccelerometer().x(), 1.0f);
  CHECK_EQ(copied.getAccelerometer().y(), 2.0f);
  CHECK_EQ(copied.getAccelerometer().z(), 3.0f);
  CHECK_EQ(copied.getGyroscope().x(), 4.0f);
  CHECK_EQ(copied.getGyroscope().y(), 5.0f);
  CHECK_EQ(copied.getGyroscope().z(), 6.0f);
  CHECK_EQ(copied.getMagnometer().x(), 7.0f);
  CHECK_EQ(copied.getMagnometer().y(), 8.0f);
  CHECK_EQ(copied.getMagnometer().z(), 9.0f);
  CHECK_EQ(copied.getEuler().x().degrees(), 1.0f);
  CHECK_EQ(copied.getEuler().y().degrees(), 2.0f);
  CHECK_EQ(copied.getEuler().z().degrees(), 3.0f);
  CHECK_EQ(copied.getQuarternion().w(), 1.0f);
  CHECK_EQ(copied.getQuarternion().x(), 2.0f);
  CHECK_EQ(copied.getQuarternion().y(), 3.0f);
  CHECK_EQ(copied.getQuarternion().z(), 4.0f);
}