#ifndef __CONTAINERS_TRIAXIAL_READING_HPP
#define __CONTAINERS_TRIAXIAL_READING_HPP

#include <cmath>
#include <cstddef>
#include <cstdint>

struct TriaxialReading {
  TriaxialReading(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {}
  TriaxialReading() : _x(0), _y(0), _z(0) {}
  TriaxialReading& operator=(const TriaxialReading& rhs) {
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;
    return *this;
  }
  float& operator[](int index) { return reinterpret_cast<float*>(_bytes)[index]; }
  TriaxialReading operator+(const TriaxialReading& rhs) {
    _x += rhs.x();
    _y += rhs.y();
    _z += rhs.z();
    return *this;
  }
  TriaxialReading operator-(const TriaxialReading& rhs) {
    _x -= rhs.x();
    _y -= rhs.y();
    _z -= rhs.z();
    return *this;
  }
  /**
   * @brief Calculate the normalised reading, such that the magnitude is 1
   * @return TriaxialReading Normalised reading.
   */
  TriaxialReading normalise() const {
    auto mag = magnitude();
    return TriaxialReading(_x / mag, _y / mag, _z / mag);
  }
  /**
   * @brief Calculate the magnitude of the reading.
   * @return float Magnitude
   */
  float magnitude() const { return std::sqrt(_x * _x + _y * _y + _z * _z); }
  /**
   * @brief Query if the set of readys are empty. (0,0,0)
   * @return bool True if empty.
   */
  bool empty() const { return (_x == 0.0f) && (_y == 0.0f) && (_z == 0.0f); }
  /**
   * @brief Retrieve the x comonent of the reading.
   * @return float x component.
   */
  constexpr float x() const { return _x; };
  /**
   * @brief Retrieve the z comodfffent of the reading.
   * @return float z component.
   */
  constexpr float y() const { return _y; };
  /**
   * @brief Retrieve the z comonent of the reading.,
   * @return float z component.
   */
  constexpr float z() const { return _z; };
  /**
   * @brief Retreive a raw pointer to the start of the internal data.
   * @details The internal data is the equivelent of an array of floats in the x, y and z order.
   * @return uint8_t raw pointer.
   */
  constexpr uint8_t* bytes() { return _bytes; }
  /**
   * @brief Retrieve the length of the internal data.
   * @return size_t length in bytes.
   */
  constexpr size_t length() const { return sizeof(float) * 3; }

 private:
  union {
    struct {
      float _x;
      float _y;
      float _z;
    };
    uint8_t _bytes[sizeof(float) * 3];
  };
};
static_assert(sizeof(TriaxialReading) == (sizeof(float) * 3));

#endif  // __CONTAINERS_TRIAXIAL_READING_HPP