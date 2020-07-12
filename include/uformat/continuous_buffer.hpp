#pragma once


#include <cstdint>

#if defined(_WIN32)

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
  

template<std::uint32_t MCAP>
class continuous_buffer {
public:

  using size_type = std::uint32_t;
  
  
  continuous_buffer() noexcept {
#if defined(_WIN32)
    
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    page_size_ = si.dwPageSize;
    auto const pages_count = MCAP / page_size_ + 1;
    max_capacity_ = nearest_power_of_2(pages_count * page_size_);     
    data_ = VirtualAlloc(nullptr, max_capacity_, MEM_RESERVE, PAGE_NOACCESS);
    
    
#endif
  }
  
  
  continuous_buffer(continuous_buffer const&) = default;
  continuous_buffer& operator = (continuous_buffer const&) = default;
  
  explicit operator bool() const noexcept { return max_capacity_ != 0; }
  bool empty() const noexcept { return size_ == 0; }
  char const* data() const noexcept { return data_; }
  size_type size() const noexcept { return size_; }

private:

  size_type size_{0};
  size_type page_size_{0};
  size_type max_capacity_{0};
  size_type capacity_{0};
  char* data_{nullptr};
  
  
  static std::uint32_t nearest_power_of_2(std::uint32_t n) {
      if(n < 2)
        return 2;
      n--;
      n |= n >> 1;
      n |= n >> 2;
      n |= n >> 4;
      n |= n >> 8;
      n |= n >> 16;
      n++;
      return n;
    }

};


}
