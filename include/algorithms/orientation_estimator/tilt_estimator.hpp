#ifndef __ALGORITHMS_TILT_ESTIMATOR_HPP
#define __ALGORITHMS_TILT_ESTIMATOR_HPP

#include <cstddef>
#include <cstdint>

#include "orientation_estimator.hpp"

class TiltEstimator : public OrientationEstimator {
 public:
  Rotation::Euler orientationEuler() override;
  Rotation::Quarternion orientationQuarternion() override;
  void update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) override;

 private:
  Rotation::Euler _currentOrientation;
};

#endif  // __ALGORITHMS_TILT_ESTIMAORN_HPP