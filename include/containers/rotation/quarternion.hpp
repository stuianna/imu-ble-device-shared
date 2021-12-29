#ifndef __CONTAINERS_ROTATION_QUARTERNION_HPP
#define __CONTAINERS_ROTATION_QUARTERNION_HPP

#include <cmath>
#include <containers/rotation/euler.hpp>
#include <cstddef>
#include <cstdint>

namespace Rotation {
  struct Quarternion {
    /**
     * @brief Construct a new  Quarternion object
     * @param w The real or scaler part.
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     * @param z The z component of the vector.
     */
    Quarternion(const float w, const float x, const float y, const float z) : quarts{w, x, y, z} {}
    Quarternion& operator=(Quarternion&& rhs) {
      if(this != &rhs) {
        this->quarts._w = rhs.quarts._w;
        this->quarts._x = rhs.quarts._x;
        this->quarts._y = rhs.quarts._y;
        this->quarts._z = rhs.quarts._z;
      }
      return *this;
    }
    Quarternion& operator=(const Quarternion& rhs) {
      quarts._w = rhs.quarts._w;
      quarts._x = rhs.quarts._x;
      quarts._y = rhs.quarts._y;
      quarts._z = rhs.quarts._z;
      return *this;
    }
    constexpr Quarternion(const Quarternion& rhs) : quarts(rhs.quarts) {}
    Quarternion() : quarts{1, 0, 0, 0} {}
    float& operator[](int index) { return reinterpret_cast<float*>(_bytes)[index]; }

    Quarternion operator+(const Quarternion& rhs) {
      quarts._w += rhs.w();
      quarts._x += rhs.x();
      quarts._y += rhs.y();
      quarts._z += rhs.z();
      return *this;
    }
    Quarternion operator-(const Quarternion& rhs) {
      quarts._w -= rhs.w();
      quarts._x -= rhs.x();
      quarts._y -= rhs.y();
      quarts._z -= rhs.z();
      return *this;
    }
    Quarternion operator*(const Quarternion& rhs) {
      auto _w = w() * rhs.w() - x() * rhs.x() - y() * rhs.y() - z() * rhs.z();
      auto _x = w() * rhs.x() + x() * rhs.w() + y() * rhs.z() - z() * rhs.y();
      auto _y = w() * rhs.y() - x() * rhs.z() + y() * rhs.w() + z() * rhs.x();
      auto _z = w() * rhs.z() + x() * rhs.y() - y() * rhs.x() + z() * rhs.w();
      return Quarternion(_w, _x, _y, _z);
    }
    /**
     * @brief Calculate the normalised reading, such that the magnitude is 1
     * @return Quarternion Normalised reading.
     */
    Quarternion normalise() {
      auto mag = magnitude();
      return Quarternion(quarts._w / mag, quarts._x / mag, quarts._y / mag, quarts._z / mag);
    }
    /**
     * @brief Calculate the magnitude of the quarternion.
     * @return float Magnitude
     */
    float magnitude() { return std::sqrt(quarts._w * quarts._w + quarts._x * quarts._x + quarts._y * quarts._y + quarts._z * quarts._z); }
    /**
     * @brief Calculate the conjugate of the quarternion.
     * @return Quarternion The conjugate of the quarternion.
     */
    Quarternion conjugate() { return Quarternion(w(), -x(), -y(), -z()); }
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
  };
  static_assert(sizeof(Quarternion) == 16);

}  // namespace Rotation

#endif  // __CONTAINERS_ROTATION_QUARTERNION_HPP