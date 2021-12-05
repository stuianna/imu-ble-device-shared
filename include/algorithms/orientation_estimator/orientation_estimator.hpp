#ifndef __ALGORITHMS_ORIENTATION_ESTIMATOR_HPP
#define __ALGORITHMS_ORIENTATION_ESTIMATOR_HPP

#include <containers/rotation_euler.hpp>
#include <containers/triaxal_reading.hpp>
#include <cstddef>
#include <cstdint>

class OrientationEstimator {
 public:
  virtual RotationEuler orientation() = 0;
  virtual void update(const TriaxalReading& acc, const TriaxalReading& gyr, const TriaxalReading& mag) = 0;
  virtual ~OrientationEstimator() = default;

 protected:
  OrientationEstimator(){};
};

#endif  // __ALGORITHMS_ORIENTATION_ESTIMAORN_HPP