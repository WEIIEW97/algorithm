/**
Given a non-negative integer x, return the square root of x rounded down to the
nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to
the nearest integer, 2 is returned.


Constraints:

0 <= x <= 231 - 1

source from: leetcode 69.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// macOS-specific optimizations with Clang
#if defined(__APPLE__) && defined(__MACH__)
#if defined(__clang__)
#pragma clang optimize on
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// Windows-specific optimizations with MSVC
#if defined(_WIN32)
#if defined(_MSC_VER)
#include <cstdlib>
#pragma optimize("t", on)
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

int mySqrt(int x) {
  int l = 1, r = x, m, x_div_m;
  while (l <= r) {
    m = l + (r - l) / 2;
    x_div_m = x / m;
    if (m == x_div_m)
      return m;
    if (m < x_div_m)
      l = m + 1;
    else
      r = m - 1;
  }
  return r;
}

int mySqrt_newton(int x) {
  long t = x;
  while (t * t > x) {
    t = (t + x / t) / 2;
  }
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(mySqrt_newton, 4);
  print_res(mySqrt_newton, 8);
  return 0;
}
