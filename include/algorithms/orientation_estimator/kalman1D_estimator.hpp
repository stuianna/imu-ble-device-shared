#ifndef __ALGORITHMS_KALMAN1D_ESTIMATOR_HPP
#define __ALGORITHMS_KALMAN1D_ESTIMATOR_HPP

#include <algorithms/kalman_filter_1D.hpp>
#include <cstddef>
#include <cstdint>

#include "orientation_estimator.hpp"

class KalmanEstimator1D : public OrientationEstimator {
 public:
  RotationEuler orientation() override;
  void update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) override;
  KalmanEstimator1D();

 private:
  RotationEuler _currentOrientation;
  KalmanFilter1D _pitch;
  KalmanFilter1D _roll;
};

#endif  // __ALGORITHMS_KALMAN1D_ESTIMAORN_HPP