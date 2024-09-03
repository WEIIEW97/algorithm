/**
You are given a string s consisting of lowercase English letters, and an integer
k.

First, convert s into an integer by replacing each letter with its position in
the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then,
transform the integer by replacing it with the sum of its digits. Repeat the
transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by
the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.



Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝
12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8


Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.

source from: leetcode 1945.
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

int getLucky(string s, int k) {
  int ret;
  string tmp = "";
  for (auto& c : s) {
    tmp += to_string(c - 'a' + 1);
  }
  while (k) {
    auto ss = accumulate(tmp.begin(), tmp.end(), 0,
                         [](int acc, char c) { return acc + (c - '0'); });
    tmp = to_string(ss);
    ret = ss;
    k--;
  }
  return ret;
}

int main() {
  string s1, s2, s3;
  s1 = "iiii";
  s2 = "leetcode";
  s3 = "zbax";
  print_res(getLucky, s1, 1);
  print_res(getLucky, s2, 2);
  print_res(getLucky, s3, 2);

  return 0;
}
