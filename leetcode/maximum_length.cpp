/**
You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For
example, the string "abc" is not special, whereas the strings "ddd", "zz", and
"f" are special.

Return the length of the longest special substring of s which occurs at least
thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.



Example 1:

Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa":
substrings "aaaa", "aaaa", and "aaaa". It can be shown that the maximum length
achievable is 2. Example 2:

Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice.
Hence return -1. Example 3:

Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a":
substrings "abcaba", "abcaba", and "abcaba". It can be shown that the maximum
length achievable is 1.


Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters.

source from: leetcode 2981.
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

int maximumLength(string s) {
  int n=s.size();
  unordered_map<string, int> freq;
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      freq[s.substr(i, j-i+1)]++;
    }
  }

  auto is_special = [&](const string& s) {
    for (int i=0; i<s.size()-1; ++i){
      if (s[i]!=s[i+1]) return false;
    }
    return true;
  };

  int ans=0;
  for(auto f:freq) {
    if (f.second >=3 && is_special(f.first)) {
      ans=max(ans, (int)f.first.size());
    }
  }
   return !ans ? -1: ans;
}

int main() {
  string s1 = "aaaa";
  string s2 = "abcdef";
  string s3 = "abcaba";

  print_res(maximumLength, s1);
  print_res(maximumLength, s2);
  print_res(maximumLength, s3);

  return 0;
}
