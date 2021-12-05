#include <algorithms/orientation_estimator/tilt_estimator.hpp>
#include <cmath>

RotationEuler TiltEstimator::orientation() {
  return _currentOrientation;
}

void TiltEstimator::update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) {
  (void)gyr;
  (void)mag;
  auto x = Angle::radians(atan2(-acc.y(), acc.z()));
  auto y = Angle::radians(atan2(acc.x(), acc.z()));
  _currentOrientation.x(x);
  _currentOrientation.y(y);
  _currentOrientation.z(Angle::radians(0));
}
