#pragma once


#include <doctest/doctest.h>
#include <uformat/fixed_string.hpp>


TEST_CASE("fixed_string::fixed_string") {
  uformat::string target;
  REQUIRE(target.empty());
  REQUIRE(target.size() == 0);
  REQUIRE(target.length() == 0);
}



TEST_CASE("fixed_string(\"test\")") {
  uformat::string target("test");
  REQUIRE(!target.empty());
  REQUIRE(target.size() == sizeof("test") - 1);
  REQUIRE(target.length() == sizeof("test") - 1);
}
