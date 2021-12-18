#include <algorithms/kalman_filter_1D.hpp>
using namespace std;

KalmanFilter1D::KalmanFilter1D(array<double, 2> xHat, array<array<double, 2>, 2> p, array<array<double, 2>, 2> q, double r, double deltaT) :
  m_r(r), m_deltaT(deltaT / 1000000.0), m_xHatBar{0.0, 0.0}, m_pBar{{0.0, 0.0}, {0.0, 0.0}}, m_k{0.0, 0.0} {
  for(auto i = 0; i < 2; i++) {
    m_xHat[i] = xHat[i];
    for(auto j = 0; j < 2; j++) {
      m_p[i][j] = p[i][j];
      m_q[i][j] = q[i][j];
    }
  }
}

void KalmanFilter1D::update(double angularVel, double angle) {
  // Prediction
  m_xHatBar[0] = m_xHat[0] + m_deltaT * (angularVel - m_xHat[1]);
  m_xHatBar[1] = m_xHat[1];

  m_pBar[0][0] = m_p[0][0] + m_deltaT * ((m_deltaT * m_p[1][1]) - m_p[1][0] - m_p[0][1] + m_q[0][0]);
  m_pBar[0][1] = m_p[0][1] + m_deltaT * (m_q[0][1] - m_p[1][1]);
  m_pBar[1][0] = m_p[1][0] + m_deltaT * (m_q[1][0] - m_p[1][1]);
  m_pBar[1][1] = m_p[1][1] + m_deltaT * (m_q[1][1]);

  // Update
  m_k[0] = m_pBar[0][0] / (m_pBar[0][0] + m_r);
  m_k[1] = m_pBar[1][0] / (m_pBar[0][0] + m_r);

  m_xHat[0] = m_xHatBar[0] + m_k[0] * (angle - m_xHatBar[0]);
  m_xHat[1] = m_xHatBar[1] + m_k[1] * (angle - m_xHatBar[0]);

  m_p[0][0] = m_pBar[0][0] - (m_k[0] * m_pBar[0][0]);
  m_p[0][1] = m_pBar[0][1] - (m_k[0] * m_pBar[0][1]);
  m_p[1][0] = m_pBar[1][0] - (m_k[1] * m_pBar[0][0]);
  m_p[1][1] = m_pBar[1][1] - (m_k[1] * m_pBar[0][1]);
}

double KalmanFilter1D::getAngle() {
  return m_xHat[0];
}
