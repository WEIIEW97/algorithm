/**
You are given an integer array banned and two integers n and maxSum. You are
choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned
rules.



Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum
is 6, which did not exceed maxSum. Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned
conditions. Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is
28, which did not exceed maxSum.


Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109

source from: leetcode 2554.
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

int maxCount(vector<int>& banned, int n, int maxSum) {
  set<int> bset(banned.begin(), banned.end());
  vector<int> N(n);
  iota(N.begin(), N.end(), 1);
  set<int> nset(N.begin(), N.end());

  for (auto v : bset)
    nset.erase(v);

  int sum = 0, cnt = 0;
  for (auto v : nset) {
    if (sum + v > maxSum)
      break;
    sum += v;
    cnt++;
  }
  return cnt;
}


// faster approach
int maxCount1(vector<int>& banned, int n, int maxSum) {
  vector<int> mp(1e4+1, 1);
  for(auto v:banned) mp[v]=0;
  int cnt=0;
  for(int i=1; i<=n; i++) {
    if(mp[i]==0) continue;
    if(maxSum>=i) {
      cnt++;
      maxSum-=i;
      mp[i]=0;
    }
  }
  return cnt;
}

int main() {
  vector<int> banned1 = {1, 6, 5};
  vector<int> banned2 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> banned3 = {11};

  cout << maxCount(banned1, 5, 6) << endl;
  cout << maxCount(banned2, 8, 1) << endl;
  cout << maxCount(banned3, 7, 50) << endl;

  return 0;
}
