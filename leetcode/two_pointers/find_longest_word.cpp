/**
Given a string s and a string array dictionary, return the longest string in the
dictionary that can be formed by deleting some of the given string characters.
If there is more than one possible result, return the longest word with the
smallest lexicographical order. If there is no possible result, return the empty
string.



Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"


Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.

source from: leetcode 524.
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

bool check(const string& s, const string& d) {
  int i = 0, j = 0;
  while (i < s.size() && j < d.size()) {
    if (s[i] == d[j])
      j++;
    i++;
  }
  return j == d.size();
}

string findLongestWord(string s, vector<string>& dictionary) {
  sort(dictionary.begin(), dictionary.end(),
       [](const std::string& a, const std::string& b) {
         if (a.size() != b.size())
           return a.size() > b.size();
         return a < b;
       });

  for (const auto& d : dictionary) {
    if (check(s, d))
      return d;
  }
  return "";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<string> d1, d2;
  d1 = {"ale", "apple", "monkey", "plea"};
  d2 = {"apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf"};
  print_res(findLongestWord, "abpcplea", d1);
  print_res(findLongestWord, "aewfafwafjlwajflwajflwafj", d2);

  return 0;
}
