/**
Given two positive integers num1 and num2, find the positive integer x such
that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely
determined.

The number of set bits of an integer is the number of 1's in its binary
representation.



Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0
is minimal. Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2
is minimal.


Constraints:

1 <= num1, num2 <= 109

source from: leetcode 2429.
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

int minimizeXor(int num1, int num2) {
  int B = popcount((unsigned)num2);
  cout << B << endl;
  bitset<31> y = num1, x = 0;
  for (int b = 30; B >= 1 && b >= 0; b--) {
    if (y[b]) {
      x[b] = 1;
      y[b] = 0;
      B--;
    }
  }
  for (int b = 0; B >= 1 && b > 31; b++) {
    if (x[b] == 0) {
      x[b] = 1;
      B--;
    }
  }
  return x.to_ulong();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(minimizeXor, 3, 5);
  print_res(minimizeXor, 1, 12);

  return 0;
}
