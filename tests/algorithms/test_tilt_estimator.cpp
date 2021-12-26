#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <algorithms/orientation_estimator/tilt_estimator.hpp>

TEST_CASE("Fixed zy plane.") {
  SUBCASE("Device is horizontal") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, 0.0f, 1.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.x().degrees() == 0.f);
  }

  SUBCASE("Device is at 30 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, -0.5, sqrt(3) / 2);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.x().degrees() == 30.f);
  }

  SUBCASE("Device is at 60 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, -sqrt(3) / 2, 0.5);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.x().degrees() == 60.f);
  }

  SUBCASE("Device is at 90 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, -1, 0.0);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.x().degrees() == 90.f);
  }

  SUBCASE("Device is at 120 degree inclination (second quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, -sqrt(3) / 2.f, -0.5f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.x().degrees() == 120.f);
  }

  SUBCASE("Device is at 210 degree inclination (third quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, 0.5f, -sqrt(3) / 2.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    // Expect -150 for 210 as the angles are limited between -180 and 180.
    CHECK(orientation.x().degrees() == -150.f);
  }

  SUBCASE("Device is at 330 degree inclination (fourth quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, 0.5f, sqrt(3) / 2.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    // Expect -30 for 330 as the angles are limited between -180 and 180.
    CHECK(orientation.x().degrees() == -30.f);
  }
}

TEST_CASE("Fixed zx plane.") {
  SUBCASE("Device is horizontal") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.0f, 0.0f, 1.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.y().degrees() == 0.f);
  }

  SUBCASE("Device is at 30 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(0.5, 0.0, sqrt(3) / 2);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.y().degrees() == 30.f);
  }

  SUBCASE("Device is at 60 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(sqrt(3) / 2, 0.0f, 0.5);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.y().degrees() == 60.f);
  }

  SUBCASE("Device is at 90 degree inclination.") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(1.0f, 0.0, 0.0);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.y().degrees() == 90.f);
  }

  SUBCASE("Device is at 120 degree inclination (second quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(sqrt(3) / 2.f, 0.0f, -0.5f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    CHECK(orientation.y().degrees() == 120.f);
  }

  SUBCASE("Device is at 210 degree inclination (third quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(-0.5f, 0.0f, -sqrt(3) / 2.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    // Expect -150 for 210 as the angles are limited between -180 and 180.
    CHECK(orientation.y().degrees() == -150.f);
  }

  SUBCASE("Device is at 330 degree inclination (fourth quadrant).") {
    auto estimator = TiltEstimator();
    auto reading = TriaxialReading(-0.5f, 0.0f, sqrt(3) / 2.0f);
    estimator.update(reading, reading, reading);
    auto orientation = estimator.orientationEuler();
    // Expect -30 for 330 as the angles are limited between -180 and 180.
    CHECK(orientation.y().degrees() == -30.f);
  }
}