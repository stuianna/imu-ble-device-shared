#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <containers/angle.hpp>

TEST_CASE("Creating from degrees") {
  SUBCASE("Positive values") {
    SUBCASE("Not above 180") {
      auto angle = Angle::degrees(2);
      CHECK_EQ(angle.degrees(), 2.f);
    }

    SUBCASE("In negative half") {
      auto angle = Angle::degrees(190);
      CHECK_EQ(angle.degrees(), -170.f);
    }

    SUBCASE("Full 360") {
      auto angle = Angle::degrees(390);
      CHECK_EQ(angle.degrees(), 30.f);
    }

    SUBCASE("Above 1.5 rotations") {
      auto angle = Angle::degrees(580);
      CHECK_EQ(angle.degrees(), -140.f);
    }
  }

  SUBCASE("Negative values") {
    SUBCASE("Not below -180") {
      auto angle = Angle::degrees(-23);
      CHECK_EQ(angle.degrees(), -23.f);
    }

    SUBCASE("In positive half") {
      auto angle = Angle::degrees(-200);
      CHECK_EQ(angle.degrees(), 160.f);
    }

    SUBCASE("Full 360") {
      auto angle = Angle::degrees(-400);
      CHECK_EQ(angle.degrees(), -40.f);
    }

    SUBCASE("Above 1.5 rotations") {
      auto angle = Angle::degrees(-545);
      CHECK_EQ(angle.degrees(), 175.f);
    }
  }
}

TEST_CASE("Angle converstion from degrees and radians") {
  SUBCASE("Creating from degrees") {
    auto angle = Angle::degrees(60.f);
    CHECK_EQ(angle.degrees(), 60.f);
    CHECK_EQ(angle.radians(), static_cast<float>(M_PI) / 3.f);
  }

  SUBCASE("Creating from radians") {
    auto angle = Angle::radians(static_cast<float>(M_PI) / 2.f);
    CHECK_EQ(angle.degrees(), 90.f);
    CHECK_EQ(angle.radians(), static_cast<float>(M_PI) / 2.f);
  }

  SUBCASE("Negative radians") {
    auto angle = Angle::radians(static_cast<float>(-M_PI) / 4.f);
    CHECK_EQ(angle.degrees(), -45.f);
  }

  SUBCASE("2 PI") {
    auto angle = Angle::radians(static_cast<float>(2 * M_PI));
    CHECK_EQ(angle.degrees(), -0.f);
  }

  SUBCASE("3 PI") {
    auto angle = Angle::radians(static_cast<float>(3 * M_PI));
    CHECK_EQ(angle.degrees(), -180.f);
  }
}