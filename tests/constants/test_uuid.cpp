#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <constants/uuid.hpp>
#include <iomanip>
#include <string>

TEST_CASE("Converting 2 character hex strings to a byte") {
  // Test every valid 2 hexidecimal byte (eg. A0, fe), upper and lower case variants
  for(auto i = 0; i < 256; i++) {
    std::stringstream streamUpperCase;
    std::stringstream streamLowerCase;
    streamUpperCase << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << i;
    streamLowerCase << std::setfill('0') << std::setw(2) << std::hex << i;
    CHECK(UUID::sHexToU8(streamUpperCase.str().c_str()) == i);
    CHECK(UUID::sHexToU8(streamLowerCase.str().c_str()) == i);
  }
}

TEST_CASE("Converting 4 character hex strings to 2-bytes.") {
  CHECK(UUID::sHexToU16("1234") == 0x1234);
  CHECK(UUID::sHexToU16("0000") == 0x0);
  CHECK(UUID::sHexToU16("FFFF") == 0xFFFF);
  CHECK(UUID::sHexToU16("2323") == 0x2323);
  CHECK(UUID::sHexToU16("DEAD") == 0xDEAD);
  CHECK(UUID::sHexToU16("BEEF") == 0xBEEF);
}

TEST_CASE("Converting 8 character hex strings to a 4-bytes.") {
  CHECK(UUID::sHexToU32("12345678") == 0x12345678);
  CHECK(UUID::sHexToU32("00000000") == 0x0);
  CHECK(UUID::sHexToU32("FFFFFFFF") == 0xFFFFFFFF);
  CHECK(UUID::sHexToU32("DEADBEEF") == 0xDEADBEEF);
  CHECK(UUID::sHexToU32("af837bca") == 0xaf837bca);
}

TEST_CASE("Converting 12 character hex strings to a 6-bytes.") {
  CHECK(UUID::sHexToU48("1234567890AB") == 0x1234567890AB);
  CHECK(UUID::sHexToU48("000000000000") == 0x0);
  CHECK(UUID::sHexToU48("FFFFFFFFFFFF") == 0xFFFFFFFFFFFF);
  CHECK(UUID::sHexToU48("DEADBEEFEA71") == 0xDEADBEEFEA71);
  CHECK(UUID::sHexToU48("af837bca7812") == 0xaf837bca7812);
}