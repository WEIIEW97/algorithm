/**
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the
left of index i that is equal to s[i], and at least one character to the right
that is also equal to s[i]. Delete the closest character to the left of index i
that is equal to s[i]. Delete the closest character to the right of index i that
is equal to s[i]. Return the minimum length of the final string s that you can
achieve.



Example 1:

Input: s = "abaacbcbb"

Output: 5

Explanation:
We do the following operations:

Choose index 2, then remove the characters at indices 0 and 3. The resulting
string is s = "bacbcbb". Choose index 3, then remove the characters at indices 0
and 5. The resulting string is s = "acbcb". Example 2:

Input: s = "aa"

Output: 2

Explanation:
We cannot perform any operations, so we return the length of the original
string.



Constraints:

1 <= s.length <= 2 * 105
s consists only of lowercase English letters.

source from: leetcode 3223.
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

int minimumLength(string s) {
  vector<int> freq(26, 0);
  for (auto& c : s)
    freq[c - 'a']++;
  int rem = 0;
  for (auto& x : freq) {
    if (x < 3) {
      rem += x;
    } else {
      if (x % 2 == 1) {
        rem += 1;
      } else {
        rem += 2;
      }
    }
  }
  return rem;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  print_res(minimumLength, "abaacbcbb");
  print_res(minimumLength, "aa");
  return 0;
}
