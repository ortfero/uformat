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


#include "texter.hpp"


namespace uformat {
  
  namespace detail::printer {

    inline std::mutex sync;
    inline dynamic_texter buffer;

  }


  template<typename... Args>
  void print(Args&&... args) {
    std::unique_lock g{detail::printer::sync};
    detail::printer::buffer.clear();
    detail::printer::buffer.print(std::forward<Args>(args)...);
    std::fputs(detail::printer::buffer.data(), stdout);
    std::fputc('\n', stdout);
  }


  template<typename R, typename... Args>
  R print_with(R&& result, Args&&... args) {
    print(std::forward<Args>(args)...);
    return std::move(std::forward<R>(result));
  }


  template<typename... Args>
  void error(Args&&... args) {
    std::unique_lock g{detail::printer::sync};
    detail::printer::buffer.clear();
    detail::printer::buffer.print(std::forward<Args>(args)...);
    std::fputs(detail::printer::buffer.data(), stderr);
    std::fputc('\n', stderr);
  }


  template<typename R, typename... Args>
  R error_with(R&& result, Args&&... args) {
    error(std::forward<Args>(args)...);
    return std::move(std::forward<R>(result));
  }
  
  
}
