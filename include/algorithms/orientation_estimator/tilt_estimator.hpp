#ifndef __ALGORITHMS_TILT_ESTIMATOR_HPP
#define __ALGORITHMS_TILT_ESTIMATOR_HPP

#include <cstddef>
#include <cstdint>

#include "orientation_estimator.hpp"

class TiltEstimator : public OrientationEstimator {
 public:
  RotationEuler orientation() override;
  void update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) override;

 private:
  RotationEuler _currentOrientation;
};

#endif  // __ALGORITHMS_TILT_ESTIMAORN_HPP