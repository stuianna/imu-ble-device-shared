#ifndef __CONTAINERS_TRIAXAL_READING_HPP
#define __CONTAINERS_TRIAXAL_READING_HPP

#include <cstddef>
#include <cstdint>

struct TriaxalReading {
  TriaxalReading(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {}
  TriaxalReading() : _x(0), _y(0), _z(0) {}
  TriaxalReading& operator=(const TriaxalReading& rhs) {
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;
    return *this;
  }

 private:
  union {
    struct {
      float _x;
      float _y;
      float _z;
    };
    uint8_t _bytes[12];
  };

 public:
  constexpr float x() const { return _x; };
  constexpr float y() const { return _y; };
  constexpr float z() const { return _z; };
  constexpr uint8_t* bytes() { return _bytes; }
  constexpr size_t length() { return 12; }
};
static_assert(sizeof(TriaxalReading) == 12);

#endif  // __CONTAINERS_TRIAXAL_READING_HPP