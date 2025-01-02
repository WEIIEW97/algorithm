/**
You are given a 0-indexed array of strings words and a 2D array of integers
queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present
in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the
ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa"
and "e". The answer to the query [0,2] is 2 (strings "aba" and "ece"). to query
[1,4] is 3 (strings "ece", "aa", "e"). to query [1,1] is 0. We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].


Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length

source from: leetcode 2559.
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

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
  int n = words.size();
  vector<int> check(n, 0);
  for (int i = 0; i < n; i++) {
    if (vowels.find(words[i][0]) != vowels.end() &&
        vowels.find(words[i].back()) != vowels.end())
      check[i] = 1;
  }

  vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + check[i];
  }

  int i = 0;
  vector<int> ans(queries.size(), 0);
  for (auto& q : queries) {
    int s = q[0], e = q[1];
    int cnt = prefix[e + 1] - prefix[s];
    ans[i++] = cnt;
  }
  return ans;
}

// optimized version
vector<int> vowelStringsV1(vector<string>& words,
                           vector<vector<int>>& queries) {
  const unsigned isVowel = 1 + (1 << ('e' - 'a')) + (1 << ('i' - 'a')) +
                           (1 << ('o' - 'a')) + (1 << ('u' - 'a'));
  const int n = words.size(), qz = queries.size();
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < n; i++) {
    string& w = words[i];
    cnt[i + 1] = cnt[i] + (((1 << (w[0] - 'a')) & isVowel) &&
                           ((1 << (w.back() - 'a')) & isVowel));
  }
  vector<int> ans(qz, 0);
  int i = 0;
  for (auto& q : queries) {
    ans[i++] = cnt[q[1] + 1] - cnt[q[0]];
  }
  return ans;
}

int main() {
  vector<string> words1, words2;
  vector<vector<int>> queries1, queries2;

  words1 = {"aba", "bcb", "ece", "aa", "e"}, words2 = {"a", "e", "i"};
  queries1 = parse_matrix("[[0,2],[1,4],[1,1]]"),
  queries2 = parse_matrix("[[0,2],[0,1],[2,2]]");

  print_res(vowelStrings, words1, queries1);
  print_res(vowelStrings, words2, queries2);

  return 0;
}
