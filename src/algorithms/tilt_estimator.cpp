#include <algorithms/orientation_estimator/tilt_estimator.hpp>
#include <cmath>

RotationEuler TiltEstimator::orientation() {
  return _current;
}

void TiltEstimator::update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) {
  (void)gyr;
  (void)mag;
  auto x = Angle::radians(atan2(-acc.y(), acc.z()));
  auto y = Angle::radians(atan2(acc.x(), acc.z()));
  _current.x(x);
  _current.y(y);
  _current.z(Angle::radians(0));
}
