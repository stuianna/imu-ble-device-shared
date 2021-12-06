#include <algorithms/orientation_estimator/tilt_estimator.hpp>
#include <cmath>

RotationEuler TiltEstimator::orientation() {
  return _currentOrientation;
}

void TiltEstimator::update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) {
  (void)gyr;
  (void)mag;
  auto x = Angle::radians(-atan2(acc.y(), acc.z()));
  auto y = Angle::radians(-atan2(-acc.x(), sqrt(acc.z() * acc.z() + acc.y() * acc.y())));

  if(acc.z() < 0.f) {
    if(acc.x() > 0.f) {
      y = y.degrees(180 - y.degrees());
    }
    else {
      y = y.degrees(-180 - y.degrees());
    }
  }

  _currentOrientation.x(x);
  _currentOrientation.y(y);
  _currentOrientation.z(Angle::radians(0));
}
