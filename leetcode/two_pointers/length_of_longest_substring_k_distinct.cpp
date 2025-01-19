/**
Given a string s and an integer k, return the length of the longest substring of
s that contains at most k distinct characters.

source from: leetcode 340.
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

int lengthOfLongestSubstringKDistinct(string s, int k) {
  unordered_map<char, int> freq;
  int max_len = 0;
  int l = 0; // left index of our window
  for (int r = 0; r < s.size(); r++) {
    char c = s[r];
    freq[c]++;

    // Shrink from the left until we have only k distinct
    while (freq.size() > k) {
      freq[s[l]]--;
      if (freq[s[l]] == 0)
        freq.erase(s[l]);
      l++;
    }

    max_len = max(max_len, r - l + 1);
  }
  return max_len;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(lengthOfLongestSubstringKDistinct, "eceba", 2);
  print_res(lengthOfLongestSubstringKDistinct, "aa", 1);

  return 0;
}
