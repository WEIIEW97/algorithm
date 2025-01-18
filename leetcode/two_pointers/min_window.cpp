/**
Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t. Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?

source from: leetcode 76.
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

string minWindow(string s, string t) {
  // set to 128 since there are only 128 characters in ASCII
  vector<bool> valid(128, false);
  vector<int> freq(128, 0);

  for(int i=0; i<t.length(); ++i) {
    valid[t[i]]=true;
    ++freq[t[i]];
  }

  int cnt=0;
  int min_l=-1, min_len=-1;
  for(int l=0, r=0; r<s.length();++r) {
    if(!valid[s[r]]) continue;
    if(--freq[s[r]]>=0) ++cnt;
    while(cnt == t.length()) {
      if (min_l==-1||r-l+1<min_len) {
        min_l=l;
        min_len=r-l+1;
      }
      if (valid[s[l]]&&++freq[s[l]]>0) {
        --cnt;
      }
      ++l;
    }
  }
  return min_l==-1?"":s.substr(min_l, min_len);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(minWindow, string("ADOBECODEBANC"), string("ABC"));
  print_res(minWindow, string("a"), string("a"));
  print_res(minWindow, string("a"), string("aa"));

  return 0;
}
