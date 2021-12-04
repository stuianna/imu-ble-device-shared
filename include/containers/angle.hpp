#ifndef __CONTAINERS_ANGLE__HPP
#define __CONTAINERS_ANGLE__HPP

#include <cmath>

struct Angle {
  static Angle degrees(const float value) { return Angle(value); };
  static Angle radians(const float value) { return Angle(_toDegrees(value)); };

  /**
   * @brief Get the angle value in degrees.
   * @return float Angle in degrees.
   */
  float degrees() { return _value; }

  /**
   * @brief Get the angle value in radians.
   * @return float Angle in radians.
   */
  float radians() { return _toRadians(_value); };

 private:
  explicit Angle(const float value) : _value(_limitAngle(value)){};
  // The actual value of the angle in degrees.
  const float _value;
  static constexpr float _toRadians(const float value) { return value * (M_PI / 180.f); }
  static constexpr float _toDegrees(const float value) { return value * (180.f / M_PI); }
  static constexpr float _limitAngle(const float _in) {
    const float offset = 180.f;
    if((_in <= offset) && (_in >= -offset)) {
      return _in;
    }
    // The euler angle range chosen is -180 to +180.
    // This fixes the angles within this range.
    const int divisor = static_cast<int>(_in / offset);
    const float remainder = _in - (divisor * offset);
    return ((divisor % 2) * -offset) + remainder;
  }
};
static_assert(sizeof(Angle) == 4, "Expected structure to have size of 4");

#endif  // __CONTAINERS_ANGLE__HPP