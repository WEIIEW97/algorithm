/**
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including
multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a
subset of a.

Return an array of all the universal strings in words1. You may return the
answer in any order.



Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
["e","o"] Output: ["facebook","google","leetcode"] Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
["l","e"] Output: ["apple","google","leetcode"]


Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.

source from: leetcode 916.
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
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
  vector<int> cnt(26, 0);
  for (auto& x : words2) {
    vector<int> tmp(26, 0);
    for (auto& y : x)
      tmp[y - 'a'] += 1;
    for (int i = 0; i < 26; i++)
      cnt[i] = max(cnt[i], tmp[i]);
  }
  vector<string> ans;
  for (auto& x : words1) {
    vector<int> tmp(26, 0);
    for (auto& y : x)
      tmp[y - 'a'] += 1;
    bool isValid = true;
    for (int i = 0; i < 26; i++)
      isValid &= tmp[i] >= cnt[i];
    if (isValid)
      ans.push_back(x);
  }
  return ans;
}

int main() {
  vector<string> w11, w12;
  vector<string> w21, w22;

  w11 = {"amazon", "apple", "facebook", "google", "leetcode"}, w21 = {"e", "o"};
  w12 = {"amazon", "apple", "facebook", "google", "leetcode"},
  w22 = {"lo", "eo"};
  print_res(wordSubsets, w11, w21);
  print_res(wordSubsets, w12, w22);

  return 0;
}
