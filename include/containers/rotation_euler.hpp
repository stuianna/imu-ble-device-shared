#ifndef __CONTAINERS_ROTATION_EULER_HPP
#define __CONTAINERS_ROTATION_EULER_HPP

#include <cstddef>
#include <cstdint>

#include "angle.hpp"

struct RotationEuler {
  /**
   * @brief Construct a new Rotation Euler object
   *
   * @details The euler angles for each axis have a range of -180 to 180 degrees.
   * @param x The rotation in degrees around the x axis (roll)
   * @param y The rotation in degrees around the y axis (pitch)
   * @param z The rotatio in degreesn around the z axis (yaw)
   */
  RotationEuler(const Angle x, const Angle y, const Angle z) : angles{x, y, z} {}

 private:
  union {
    struct {
      const Angle _x;
      const Angle _y;
      const Angle _z;
    } angles;
    uint8_t _bytes[12];
  };

 public:
  /**
   * @brief Get the rotation around the x axis (roll)
   * @return constexpr Angle The rotation.
   */
  Angle x() { return angles._x; };
  /**
   * @brief Get the rotation around the y axis (pitch)
   * @return constexpr Angle The rotation.
   */
  Angle y() { return angles._y; };
  /**
   * @brief Get the rotation around the z axis (yaw)
   * @return constexpr Angle The rotation.
   */
  Angle z() { return angles._z; };
  /**
   * @brief Get the roll in degrees.
   * @return constexpr Angle The rotation.
   */
  Angle roll() { return angles._x; };
  /**
   * @brief Get the pitch in degrees.
   * @return constexpr Angle The rotation.
   */
  Angle pitch() { return angles._y; };
  /**
   * @brief Get the yaw in degrees.
   * @return constexpr Angle The rotation.
   */
  Angle yaw() { return angles._z; };
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