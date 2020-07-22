#pragma once


#include <doctest/doctest.h>
#include <uformat/texter.hpp>



TEST_CASE("texter::texter") {
  uformat::dynamic_texter target;
  REQUIRE(target.size() == 0);
  REQUIRE(target.empty());
  REQUIRE(target.data()[0] == '\0');
  REQUIRE(target.string().size() == 0);
  REQUIRE(target.string().empty());
  REQUIRE(target.string().data()[0] == '\0');
}


TEST_CASE("texter::print(char)") {
  uformat::dynamic_texter target;
  target << 'a';
  REQUIRE(target.string() == "a");
  target.print('x');
  REQUIRE(target.string() == "ax");
}


TEST_CASE("texter::clear") {
  uformat::dynamic_texter target;
  target << 'a';
  target.clear();
  REQUIRE(target.size() == 0);
  REQUIRE(target.empty());
  REQUIRE(target.data()[0] == '\0');
  REQUIRE(target.string().size() == 0);
  REQUIRE(target.string().empty());
  REQUIRE(target.string().data()[0] == '\0');
}


TEST_CASE("texter::print(char[])") {
  uformat::dynamic_texter target;
  target << "ok";
  REQUIRE(target.string() == "ok");
  target.print("ko");
  REQUIRE(target.string() == "okko");
}


TEST_CASE("texter::print(int)") {
  uformat::dynamic_texter target;
  target << 127;
  REQUIRE(target.string() == "127");
  target.print(562);
  REQUIRE(target.string() == "127562");
}


TEST_CASE("texter::quoted") {
  uformat::dynamic_texter target;
  target.quoted(127562);
  REQUIRE(target.string() == "'127562'");
}


TEST_CASE("texter::dquoted") {
  uformat::dynamic_texter target;
  target.dquoted(127562);
  REQUIRE(target.string() == "\"127562\"");
}


TEST_CASE("texter::char_n") {
  uformat::dynamic_texter target;
  target.char_n('*', 7);
  REQUIRE(target.string() == "*******");
}


TEST_CASE("texter::attributes") {
  uformat::dynamic_texter target;
  target.attributes("a1", 127562, "a2", "title");
  REQUIRE(target.string() == "{a1 = 127562, a2 = \"title\"}");
}


TEST_CASE("texter::left/1") {
  uformat::dynamic_texter target;
  target.left(4, -1);
  REQUIRE(target.string() == "-1  ");
}


TEST_CASE("texter::left/2") {
  uformat::dynamic_texter target;
  target.left(2, -10);
  REQUIRE(target.string() == "-10");
}


TEST_CASE("texter::right/1") {
  uformat::dynamic_texter target;
  target.right(15, "Paracletes");
  REQUIRE(target.string() == "     Paracletes");
}


TEST_CASE("texter::right/2") {
  uformat::dynamic_texter target;
  target.right(2, -10);
  REQUIRE(target.string() == "-10");
}
