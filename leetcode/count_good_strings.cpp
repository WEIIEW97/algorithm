/**
Given the integers zero, one, low, and high, we can construct a string by
starting with an empty string, and then at each step perform either of the
following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length
between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying
these properties. Since the answer can be large, return it modulo 109 + 7.



Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


Constraints:

1 <= low <= high <= 105
1 <= zero, one <= low

source from: leetcode 2466.
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

int countGoodStrings(int low, int high, int zero, int one) {
  const int mod = 1e9 + 7;
  int dp[100001] = {0};
  dp[0] = 1;
  for (int i = 1; i <= high; i++) {
    long long ans = 1;
    if (i >= zero)
      ans += dp[i - zero];
    if (i >= one)
      ans += dp[i - one];
    dp[i] = ans % mod;
  }
  return (dp[high] - dp[low - 1] + mod) % mod;
}

int main() {
  print_res(countGoodStrings, 3, 3, 1, 1);
  print_res(countGoodStrings, 2, 3, 1, 2);
  return 0;
}
