#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <algorithms/ahrs/angular.hpp>

using namespace AHRS;

bool approxEqual(float value, float expected) {
  return (expected > (value - 0.01f)) && (expected < (value + 0.01f));
}

TEST_CASE("Using AHRS Python values") {
  // Results generaged with Python using:
  // >>> from ahrs.filters import AngularRate
  // >>> f = AngularRate()
  // >>> g = np.array([1,2,3])
  // >>> q = np.array([1,0,0,0])
  // >>> f.update(q,g)
  // array([0.99982501, 0.00499971, 0.00999942, 0.01499913])
  SUBCASE("Check with initial values.") {
    auto estimator = Angular();
    auto gyr = TriaxialReading(1, 2, 3);

    estimator.update(TriaxialReading(), gyr, TriaxialReading());
    auto q = estimator.quarternion();

    CHECK_MESSAGE(approxEqual(q.w(), 0.99982501), "w: " << q.w());
    CHECK_MESSAGE(approxEqual(q.x(), 0.00499971), "x: " << q.x());
    CHECK_MESSAGE(approxEqual(q.y(), 0.00999942), "y: " << q.y());
    CHECK_MESSAGE(approxEqual(q.z(), 0.01499913), "z: " << q.z());

    SUBCASE("Repeat sample") {
      estimator.update(TriaxialReading(), gyr, TriaxialReading());
      q = estimator.quarternion();
      CHECK_MESSAGE(approxEqual(q.w(), 0.99930008), "w: " << q.w());
      CHECK_MESSAGE(approxEqual(q.x(), 0.00999767), "x: " << q.x());
      CHECK_MESSAGE(approxEqual(q.y(), 0.01999533), "y: " << q.y());
      CHECK_MESSAGE(approxEqual(q.z(), 0.029993), "z: " << q.z());
    }
  }
}

TEST_CASE("Setting parameters") {
  Angular::Parameters parameters;
  parameters.samplingPeriod = 0.1;
  auto estimator = Angular(parameters);

  Angular::Parameters savedParameters;
  savedParameters.raw = estimator.getParameters();
  CHECK(savedParameters.samplingPeriod == parameters.samplingPeriod);

  SUBCASE("Estimator uses updated sampling rate.") {
    auto gyr = TriaxialReading(1, 2, 3);
    estimator.update(TriaxialReading(), gyr, TriaxialReading());
    auto q = estimator.quarternion();
    CHECK_MESSAGE(approxEqual(q.w(), 0.98255098), "w: " << q.w());
    CHECK_MESSAGE(approxEqual(q.x(), 0.04970884), "x: " << q.x());
    CHECK_MESSAGE(approxEqual(q.y(), 0.09941769), "y: " << q.y());
    CHECK_MESSAGE(approxEqual(q.z(), 0.14912653), "z: " << q.z());
  }
}