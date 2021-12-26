#include <algorithms/orientation_estimator/kalman1D_estimator.hpp>
#include <algorithms/spacial_conversions.hpp>
#include <array>
#include <cmath>
using namespace std;

// clang-format off
KalmanEstimator1D::KalmanEstimator1D() :
  _pitch(
    array<double, 2>{0.00, 0.00},
    array<array<double,2>, 2>{
      array<double,2>{1.0, 1.0},
      array<double,2>{1.0, 1.0}
    }, 
    array<array<double,2>, 2>{
      array<double,2>{0.001, 0.001},
      array<double,2>{0.001, 0.001}
    }, 
    0.001, 
    10000),
  _roll(
    array<double, 2>{0.00, 0.00},
    array<array<double,2>, 2>{
      array<double,2>{1.0, 1.0},
      array<double,2>{1.0, 1.0}
    }, 
    array<array<double,2>, 2>{
      array<double,2>{0.001, 0.001},
      array<double,2>{0.001, 0.001}
    }, 
    0.001, 
    10000)
{
}
// clang-format on

RotationEuler KalmanEstimator1D::orientationEuler() {
  return _currentOrientation;
}

RotationQuarternion KalmanEstimator1D::orientationQuarternion() {
  return SpacialConversions::euler2Quarternion(_currentOrientation);
}

void KalmanEstimator1D::update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) {
  auto accelAngle_x = Angle::radians(atan2(acc.y(), acc.z()));
  auto gyrRate_x = Angle::radians(gyr.x());

  auto accelAngle_y = Angle::radians(atan2(acc.x(), acc.z()));
  auto gyrRate_y = Angle::radians(gyr.y());

  auto current_z = _currentOrientation.z().radians();
  current_z += gyr.z() * _pitch.deltaT();

  _pitch.update(gyrRate_y.degrees(), accelAngle_y.degrees());
  _roll.update(gyrRate_x.degrees(), accelAngle_x.degrees());


  _currentOrientation.y(Angle::degrees(_pitch.getAngle()));
  _currentOrientation.x(Angle::degrees(_roll.getAngle()));
  _currentOrientation.z(Angle::radians(current_z));
}