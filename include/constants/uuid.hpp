#ifndef __CONSTANTS_UUID_HPP
#define __CONSTANTS_UUID_HPP

#include <cstddef>
#include <cstdint>

namespace UUID {
  /**
   * @brief Convert a two character hex string into a byte at compiile time.
   * @details Hex value must be supplied without leading '0x'. Upper and lower case hex values accepted.
   * @param input Two character hex string.
   * @return constexpr uint8_t The byte represeted by the string.
   */
  constexpr uint8_t sHexToU8(const char* input) {
    const uint8_t upper4 = input[0] > '9' ? (input[0] > 'F' ? input[0] - 87 : input[0] - 55) : (input[0] - 48);
    const uint8_t lower4 = input[1] > '9' ? (input[1] > 'F' ? input[1] - 87 : input[1] - 55) : (input[1] - 48);
    return (upper4 << 4) + lower4;
  }

  /**
   * @brief Convert a four character hex string into an uint16_t at compiile time.
   * @details Hex value must be supplied without leading '0x'. Upper and lower case hex values accepted.
   * @param input Four character hex string.
   * @return constexpr uint16_t The uint16_t represeted by the string.
   */
  constexpr uint16_t sHexToU16(const char* input) { return (sHexToU8(input) << 8) | sHexToU8(&input[2]); }

  /**
   * @brief Convert an eight character hex string into an uint32_t at compiile time.
   * @details Hex value must be supplied without leading '0x'. Upper and lower case hex values accepted.
   * @param input Eight character hex string.
   * @return constexpr uint32_t The uint32_t represeted by the string.
   */
  constexpr uint32_t sHexToU32(const char* input) { return (sHexToU16(input) << 16) | sHexToU16(&input[4]); }

  /**
   * @brief Convert a twelve character hex string into an uint48_t at compiile time.
   * @details Hex value must be supplied without leading '0x'. Upper and lower case hex values accepted.
   * @param input Twelve character hex string.
   * @return constexpr uint64_t The uint48_t represeted by the string.
   */
  constexpr uint64_t sHexToU48(const char* input) {
    const uint64_t u32 = sHexToU32(input);
    const uint32_t l16 = sHexToU16(&input[8]);
    return (u32 << 16) | l16;
  }

};  // namespace UUID

#endif  // __CONSTANTS_UUID_HPP