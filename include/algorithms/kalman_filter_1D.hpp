#ifndef __ALGORITHMS_KALMAN_FILTER_1D_HPP
#define __ALGORITHMS_KALMAN_FILTER_1D_HPP

#include <array>

// Adapted from https://thepoorengineer.com/en/angle-control-absolute/#kalman
// No licence provided.

class KalmanFilter1D {
 public:
  KalmanFilter1D(std::array<double, 2> xHat, std::array<std::array<double, 2>, 2> p, std::array<std::array<double, 2>, 2> q, double r,
                 double deltaT);

  void update(double angularVel, double angle);
  double getAngle();
  double deltaT() { return m_deltaT; }

 private:
  double m_r;
  double m_deltaT;
  double m_xHatBar[2];
  double m_pBar[2][2];
  double m_k[2];
  double m_xHat[2];
  double m_p[2][2];
  double m_q[2][2];
};

#endif  // __ALGORITHMS_KALMAN_FILTER_1D_HPP