/**
Given a string s, return true if the s can be palindrome after deleting at most
one character from it.



Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

source from: leetcode 680.
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

bool check(const string& s, int l, int r) {
  while (l < r) {
    if (s[l++] != s[r--])
      return false;
  }
  return true;
}

bool validPalindrome(string s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      bool skip_l = check(s, l + 1, r);
      bool skip_r = check(s, l, r - 1);
      return skip_l || skip_r;
    }
    l++, r--;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(validPalindrome, "aba");
  print_res(validPalindrome, "abca");
  print_res(validPalindrome, "abc");
  return 0;
}
