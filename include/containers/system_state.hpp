#ifndef __CONTAINERS_SYSTEM_STATE_HPP
#define __CONTAINERS_SYSTEM_STATE_HPP

#include <array>
#include <cstdint>
#include <cstring>

#include "rotation/euler.hpp"
#include "rotation/quarternion.hpp"
#include "triaxial_reading.hpp"
/**
 * @brief Class for storing internal system states.
 * @details This class contains an internal packed structure, intended for transmitting notifications.
 */

struct SystemState {
  /**
   * @brief Construct a new empty System State object.
   * @details All fields are set to zerol
   */
  SystemState() { raw.fill(0); }
  /**
   * @brief Construct a new System State object from an array of bytes.
   * @param data Array of 64 bytes to store internally.
   */
  explicit SystemState(std::array<uint8_t, 64> data) { raw = data; }
  /**
   * @brief Construct a new System State object from raw bytes
   * @param bytes A raw pointer to the start of the byte array.
   * @param length The length of the passed byte array. Expected to be 64.
   */
  SystemState(uint8_t* bytes, const size_t length) {
    size_t _length = length >= sizeof(raw) ? raw.size() : length;
    std::memcpy(raw.data(), bytes, _length);
  }
  /**
   * @brief Get the Accelerometer object readings.
   * @return TriaxialReading Accelerometer readings.
   */
  TriaxialReading getAccelerometer() const { return orientation.raw.acc; }
  /**
   * @brief Get the Gyroscope object readings.
   * @return TriaxialReading Gyroscope readings.
   */
  TriaxialReading getGyroscope() const { return orientation.raw.gyr; }
  /**
   * @brief Get the Magnometer object readings.
   * @return TriaxialReading Magnometer readings.
   */
  TriaxialReading getMagnometer() const { return orientation.raw.mag; }
  /**
   * @brief Get the Euler object readings
   * @return Rotation::Euler current euler angle readings.
   */
  Rotation::Euler getEuler() const { return orientation.euler; }
  /**
   * @brief Get the Quarternion object readings
   * @return Rotation::Quarternion current quarternion readings.
   */
  Rotation::Quarternion getQuarternion() const { return orientation.quarts; }
  /**
   * @brief Get a raw pointer to the start of the internal data structure.
   * @return uint8_t* raw pointer.
   */
  uint8_t* data() { return raw.data(); }
  /**
   * @brief Get the length of the internally stored data structure.
   * @return size_t length in bytes.
   */
  size_t length() const { return sizeof(raw); }
  /**
   * @brief Set the Accelerometer object readings
   * @param acc Readings to store;
   */
  void setAccelerometer(const TriaxialReading& acc) { orientation.raw.acc = acc; };
  /**
   * @brief Set the Gyroscope object readings
   * @param acc Readings to store;
   */
  void setGyroscope(const TriaxialReading& gyr) { orientation.raw.gyr = gyr; };
  /**
   * @brief Set the Magnometer object readings
   * @param acc Readings to store;
   */
  void setMagnometer(const TriaxialReading& mag) { orientation.raw.mag = mag; };
  /**
   * @brief Set the Euler object readings
   * @param acc Readings to store;
   */
  void setEuler(const Rotation::Euler& euler) { orientation.euler = euler; };
  /**
   * @brief Set the Quarternion object readings
   * @param acc Readings to store;
   */
  void setQuarternion(const Rotation::Quarternion& quarts) { orientation.quarts = quarts; };

 protected:
  union {
    struct {
      struct {
        TriaxialReading acc;
        TriaxialReading gyr;
        TriaxialReading mag;
      } raw;
      Rotation::Euler euler;
      Rotation::Quarternion quarts;
    } orientation;
    std::array<uint8_t, 64> raw;
  };
};
static_assert(sizeof(SystemState) == 64, "Unexpected packing of system state structure.");

#endif  // __CONTAINERS_SYSTEM_STATE_HPP