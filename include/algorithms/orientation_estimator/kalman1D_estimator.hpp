#ifndef __ALGORITHMS_KALMAN1D_ESTIMATOR_HPP
#define __ALGORITHMS_KALMAN1D_ESTIMATOR_HPP

#include <algorithms/kalman_filter_1D.hpp>
#include <cstddef>
#include <cstdint>

#include "orientation_estimator.hpp"

class KalmanEstimator1D : public OrientationEstimator {
 public:
  Rotation::Euler orientationEuler() override;
  Rotation::Quarternion orientationQuarternion() override;
  void update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) override;
  KalmanEstimator1D();

 private:
  Rotation::Euler _currentOrientation;
  KalmanFilter1D _pitch;
  KalmanFilter1D _roll;
};

#endif  // __ALGORITHMS_KALMAN1D_ESTIMAORN_HPP