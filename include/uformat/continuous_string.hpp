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

#include <cstdio>
#include <string_view>
#include <iosfwd>
#include <stdexcept>


#ifdef _WIN32

#if !defined(_X86_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_)
#if defined(_M_IX86)
#define _X86_
#elif defined(_M_AMD64)
#define _AMD64_
#elif defined(_M_ARM)
#define _ARM_
#elif defined(_M_ARM64)
#define _ARM64_
#endif
#endif

#include <minwindef.h>
#include <memoryapi.h>
#include <handleapi.h>

#else
  
#error Unsupported system

#endif // WIN32


namespace uformat {
  
  namespace detail {
    
    class continuous_buffer {
    public:
    
      using size_type = std::size_t;
      
      continuous_buffer() noexcept = default;
      continuous_buffer(continuous_buffer const&) noexcept = default;
      continuous_buffer& operator = (continuous_buffer const&) noexcept = default;
      
    private:
    
      size_type capacity_{0};
      char* buffer_{nullptr};
    };
    
  } // detail
  
  
  class continuous_string {
  public:
  
    using value_type = char;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = char*;
    using const_pointer = char const*;
    using reference = char&;
    using const_reference = char const&;
    using iterator = char*;
    using const_iterator = char const*;
    
    static constexpr size_type npos = size_type(-1);
    
    
    continuous_string() noexcept = default;
    continuous_string(continuous_string const&) noexcept = default;
    continuous_string& operator = (continuous_string const&) noexcept = default;
  
  private:

    size_type capacity_{0};
    size_type size_{0};
    char* buffer_{nullptr};
  };
  
}
