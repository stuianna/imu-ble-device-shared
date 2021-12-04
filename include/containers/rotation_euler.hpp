#ifndef __CONTAINERS_ROTATION_EULER_HPP
#define __CONTAINERS_ROTATION_EULER_HPP

#include <cstddef>
#include <cstdint>

struct RotationEuler {
  /**
   * @brief Construct a new Rotation Euler object
   *
   * @details The euler angles for each axis have a range of -180 to 180 degrees.
   * @param x The rotation in degrees around the x axis (roll)
   * @param y The rotation in degrees around the y axis (pitch)
   * @param z The rotatio in degreesn around the z axis (yaw)
   */
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
  /**
   * @brief Get the rotation around the x axis (roll)
   * @return constexpr float The rotation in degress.
   */
  constexpr float x() { return _x; };
  /**
   * @brief Get the rotation around the y axis (pitch)
   * @return constexpr float The rotation in degress.
   */
  constexpr float y() { return _y; };
  /**
   * @brief Get the rotation around the z axis (yaw)
   * @return constexpr float The rotation in degress.
   */
  constexpr float z() { return _z; };
  /**
   * @brief Get the roll in degrees.
   * @return constexpr float The rotation in degress.
   */
  constexpr float roll() { return _x; };
  /**
   * @brief Get the pitch in degrees.
   * @return constexpr float The rotation in degress.
   */
  constexpr float pitch() { return _y; };
  /**
   * @brief Get the yaw in degrees.
   * @return constexpr float The rotation in degress.
   */
  constexpr float yaw() { return _z; };
  /**
   * @brief Get rotation (x, y, z) as a buffer of 12 bytes.
   * @return byte buffer.
   */
  constexpr uint8_t* bytes() { return _bytes; }
  /**
   * @brief Get the length of the pointer pointed to by bytes()
   *
   * @return constexpr size_t Length of the array.
   */
  constexpr size_t length() { return 12; }
};
static_assert(sizeof(RotationEuler) == 12);

#endif  // __CONTAINERS_ROTATION_EULER_HPP