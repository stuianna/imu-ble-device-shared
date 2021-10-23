#ifndef __CONTAINERS_TRIAXAL_READING_HPP
#define __CONTAINERS_TRIAXAL_READING_HPP

#include <cstddef>
#include <cstdint>

struct TriaxalReading {
  TriaxalReading(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {}

 private:
  union {
    struct {
      const float _x;
      const float _y;
      const float _z;
    };
    uint8_t _bytes[12];
  };

 public:
  constexpr float x() { return _x; };
  constexpr float y() { return _y; };
  constexpr float z() { return _z; };
  constexpr uint8_t* bytes() { return _bytes; }
  constexpr size_t length() { return 12; }
};
static_assert(sizeof(TriaxalReading) == 12);

#endif  // __CONTAINERS_TRIAXAL_READING_HPP