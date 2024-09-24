/**
You are given a string allowed consisting of distinct characters and an array of
strings words. A string is consistent if all characters in the string appear in
the string allowed.

Return the number of consistent strings in the array words.



Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain
characters 'a' and 'b'. Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.


Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

source from: leetcode 1684.
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

int countConsistentStrings(string allowed, vector<string>& words) {
  unordered_set<char> allowed_chars(allowed.begin(), allowed.end());
  int cnt = 0;
  for (auto& word : words) {
    bool is_consistent = true;
    for (auto& c : word) {
      if (allowed_chars.find(c) == allowed_chars.end()) {
        is_consistent = false;
        break;
      }
    }
    if (is_consistent)
      cnt++;
  }
  return cnt;
}

int main() {
  auto words1 = vector<string>({"ad", "bd", "aaab", "baa", "badab"});
  auto words2 = vector<string>({"a", "b", "c", "ab", "ac", "bc", "abc"});
  auto words3 =
      vector<string>({"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"});

  print_res(countConsistentStrings, "ab", words1);
  print_res(countConsistentStrings, "abc", words2);
  print_res(countConsistentStrings, "cad", words3);

  return 0;
}
