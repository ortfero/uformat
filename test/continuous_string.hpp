/* This file is part of uformat library
 * Copyright 2020 Andrei Ilin <ortfero@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once


#include <doctest/doctest.h>
#include <uformat/continuous_string.hpp>


TEST_CASE("continuous_string::continuous_string") {
  uformat::continuous_string<> target;
  REQUIRE(target.empty());
  REQUIRE(target.size() == 0);
  REQUIRE(target.length() == 0);
}


TEST_CASE("continuous_string(\"test\")") {
  uformat::continuous_string<> target("test");
  REQUIRE(!target.empty());
  REQUIRE(target.size() == sizeof("test") - 1);
  REQUIRE(target.length() == sizeof("test") - 1);
  REQUIRE(target == "test");
  REQUIRE(strcmp(target.data(), "test") == 0);
}