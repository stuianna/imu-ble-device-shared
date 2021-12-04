#ifndef __CONTAINERS_ROTATION_EULER_HPP
#define __CONTAINERS_ROTATION_EULER_HPP

#include <cstddef>
#include <cstdint>

struct RotationEuler {
  RotationEuler(const float x, const float y, const float z) : _x(_limitAngle(x)), _y(_limitAngle(y)), _z(_limitAngle(z)) {}

 private:
  union {
    struct {
      const float _x;
      const float _y;
      const float _z;
    };
    uint8_t _bytes[12];
  };

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

 public:
  constexpr float x() { return _x; };
  constexpr float y() { return _y; };
  constexpr float z() { return _z; };
  constexpr float roll() { return _x; };
  constexpr float pitch() { return _y; };
  constexpr float yaw() { return _z; };
  constexpr uint8_t* bytes() { return _bytes; }
  constexpr size_t length() { return 12; }
};
static_assert(sizeof(RotationEuler) == 12);

#endif  // __CONTAINERS_ROTATION_EULER_HPP