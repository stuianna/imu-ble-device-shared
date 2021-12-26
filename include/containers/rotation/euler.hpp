#ifndef __CONTAINERS_ROTATION_EULER_HPP
#define __CONTAINERS_ROTATION_EULER_HPP

#include <cstddef>
#include <cstdint>

#include "../angle.hpp"

namespace Rotation {
  struct Euler {
    /**
     * @brief Construct a new Euler object
     *
     * @details The euler angles for each axis have a range of -180 to 180 degrees.
     * @param x The rotation in degrees around the x axis (roll)
     * @param y The rotation in degrees around the y axis (pitch)
     * @param z The rotatio in degreesn around the z axis (yaw)
     */
    Euler(const Angle& x, const Angle& y, const Angle& z) : angles{x, y, z} {}
    Euler& operator=(Euler&& rhs) {
      if(this != &rhs) {
        this->angles._x = rhs.angles._x;
        this->angles._y = rhs.angles._y;
        this->angles._z = rhs.angles._z;
      }
      return *this;
    }
    constexpr Euler(const Euler& rhs) : angles(rhs.angles) {}
    Euler() : angles{Angle::degrees(0), Angle::degrees(0), Angle::degrees(0)} {}

   private:
    union {
      struct {
        Angle _x;
        Angle _y;
        Angle _z;
      } angles;
      uint8_t _bytes[12];
    };

   public:
    /**
     * @brief Set the x (roll) angle.
     * @param x Angle.
     */
    void x(Angle x) { angles._x = x; };
    /**
     * @brief Set the y (pitch) angle.
     * @param x Angle.
     */
    void y(Angle y) { angles._y = y; };
    /**
     * @brief Set the z (yaw) angle.
     * @param x Angle.
     */
    void z(Angle z) { angles._z = z; };
    /**
     * @brief Get the rotation around the x axis (roll)
     * @return constexpr Angle The rotation.
     */
    Angle x() const { return angles._x; };
    /**
     * @brief Get the rotation around the y axis (pitch)
     * @return constexpr Angle The rotation.
     */
    Angle y() const { return angles._y; };
    /**
     * @brief Get the rotation around the z axis (yaw)
     * @return constexpr Angle The rotation.
     */
    Angle z() const { return angles._z; };
    /**
     * @brief Get the roll in degrees.
     * @return constexpr Angle The rotation.
     */
    Angle roll() const { return angles._x; };
    /**
     * @brief Get the pitch in degrees.
     * @return constexpr Angle The rotation.
     */
    Angle pitch() const { return angles._y; };
    /**
     * @brief Get the yaw in degrees.
     * @return constexpr Angle The rotation.
     */
    Angle yaw() const { return angles._z; };
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
  static_assert(sizeof(Euler) == 12);
}  // namespace Rotation

#endif  // __CONTAINERS_ROTATION_EULER_HPP