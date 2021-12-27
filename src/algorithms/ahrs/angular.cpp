#include <Eigen/Dense>
#include <algorithms/ahrs/angular.hpp>
#include <algorithms/spacial_conversions.hpp>
#include <cmath>

using Eigen::Matrix;
using namespace Rotation;
using namespace AHRS;

Rotation::Euler Angular::euler() {
  return SpacialConversions::quarternion2Euler(_currentOrientation);
}

Rotation::Quarternion Angular::quarternion() {
  return _currentOrientation;
}

Angular::Angular() {
  setParameters(defaultParameters.raw);
  reset();
}

Angular::Angular(Parameters parameters) {
  setParameters(parameters.raw);
  reset();
}

void Angular::reset() {
  _currentOrientation = Quarternion(1.0f, 0.0f, 0.0f, 0.0f);
}

Angular::rawParameters Angular::getParameters() {
  return _parameters.raw;
}

void Angular::setParameters(const rawParameters& parameters) {
  std::copy(parameters.begin(), parameters.end(), _parameters.raw.begin());
}

void Angular::update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) {
  auto Dt = _parameters.samplingPeriod;
  const Matrix<double, 4, 4> eye{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};


  auto w = gyr.magnitude();

  // clang-format off
  Matrix<double, 4, 4> Omega{
    {0.0    ,   -gyr.x(),   -gyr.y(), -gyr.z()},
    {gyr.x(),    0.0    ,    gyr.z(), -gyr.y()},
    {gyr.y(),   -gyr.z(),    0.0    ,  gyr.x()},
    {gyr.z(),    gyr.y(),   -gyr.x(),  0.0    },
  };
  // clang-format on

  auto A = std::cos(w * Dt / 2.0) * eye + std::sin(w * Dt / 2.0) * Omega / w;
  Matrix<double, 4, 1> q{_currentOrientation.w(), _currentOrientation.x(), _currentOrientation.y(), _currentOrientation.z()};
  q = A * q;
  _currentOrientation = Rotation::Quarternion(q(0, 0), q(1, 0), q(2, 0), q(3, 0)).normalise();
}
