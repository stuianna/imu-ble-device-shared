#ifndef __ALGORITHMS_ORIENTATION_ESTIMATOR_HPP
#define __ALGORITHMS_ORIENTATION_ESTIMATOR_HPP

#include <containers/rotation/euler.hpp>
#include <containers/rotation/quarternion.hpp>
#include <containers/triaxial_reading.hpp>
#include <cstddef>
#include <cstdint>

class OrientationEstimator {
 public:
  virtual Rotation::Euler orientationEuler() = 0;
  virtual Rotation::Quarternion orientationQuarternion() = 0;
  virtual void update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) = 0;
  virtual ~OrientationEstimator() = default;

 protected:
  OrientationEstimator(){};
};

#endif  // __ALGORITHMS_ORIENTATION_ESTIMAORN_HPP