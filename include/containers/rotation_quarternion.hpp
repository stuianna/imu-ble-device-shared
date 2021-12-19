#ifndef __CONTAINERS_ROTATION_QUARTERNION_HPP
#define __CONTAINERS_ROTATION_QUARTERNION_HPP

#include <cmath>
#include <containers/rotation_euler.hpp>
#include <cstddef>
#include <cstdint>

// struct RotationEuler;

struct RotationQuarternion {
  /**
   * @brief Construct a new Rotation Quarternion object
   * @param w The real or scaler part.
   * @param x The x component of the vector.
   * @param y The y component of the vector.
   * @param z The z component of the vector.
   */
  RotationQuarternion(const float w, const float x, const float y, const float z) : quarts{w, x, y, z} {}
  RotationQuarternion& operator=(RotationQuarternion&& rhs) {
    if(this != &rhs) {
      this->quarts._w = rhs.quarts._w;
      this->quarts._x = rhs.quarts._x;
      this->quarts._y = rhs.quarts._y;
      this->quarts._z = rhs.quarts._z;
    }
    return *this;
  }
  constexpr RotationQuarternion(const RotationQuarternion& rhs) : quarts(rhs.quarts) {}
  RotationQuarternion() : quarts{1, 0, 0, 0} {}

 private:
  union {
    struct {
      float _w;
      float _x;
      float _y;
      float _z;
    } quarts;
    uint8_t _bytes[16];
  };

 public:
  /**
   * @brief Set the w (real) quarternion component
   * @param w Real part.
   */
  void w(float w) { quarts._w = w; };
  /**
   * @brief Set the x quarternion component.
   * @param x x component.
   */
  void x(float x) { quarts._x = x; };
  /**
   * @brief Set the y quarternion component.
   * @param y y component.
   */
  void y(float y) { quarts._y = y; };
  /**
   * @brief Set the z quarternion component.
   * @param z z component.
   */
  void z(float z) { quarts._z = z; };
  /**
   * @brief Get the w (real) quarternion component.
   */
  float w() const { return quarts._w; };
  /**
   * @brief Get the x quarternion component.
   */
  float x() const { return quarts._x; };
  /**
   * @brief Get the y quarternion component.
   */
  float y() const { return quarts._y; };
  /**
   * @brief Get the z quarternion component.
   */
  float z() const { return quarts._z; };

  constexpr uint8_t* bytes() { return _bytes; }
  /**
   * @brief Get the length of the pointer pointed to by bytes()
   *
   * @return constexpr size_t Length of the array.
   */
  constexpr size_t length() { return 16; }
};
static_assert(sizeof(RotationQuarternion) == 16);

#endif  // __CONTAINERS_ROTATION_QUARTERNION_HPP