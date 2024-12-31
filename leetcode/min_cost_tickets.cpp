/**
You have planned some train traveling one year in advance. The days of the year
in which you will travel are given as an integer array days. Each day is an
integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2,
3, 4, 5, 6, 7, and 8. Return the minimum number of dollars you need to travel
every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel
your travel plan: On day 1, you bought a 1-day pass for costs[0] = $2, which
covered day 1. On day 3, you bought a 7-day pass for costs[1] = $7, which
covered days 3, 4, ..., 9. On day 20, you bought a 1-day pass for costs[0] = $2,
which covered day 20. In total, you spent $11 and covered all the days of your
travel. Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel
your travel plan: On day 1, you bought a 30-day pass for costs[2] = $15 which
covered days 1, 2, ..., 30. On day 31, you bought a 1-day pass for costs[0] = $2
which covered day 31. In total, you spent $17 and covered all the days of your
travel.


Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

source from: leetcode 983.
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

// recursive DP
vector<int> dp_;
int mincostTicketsDP(vector<int>& days, vector<int>& costs) {
  int n = days.size();
  dp_.assign(n, -1);
  function<int(int)> f = [&](int i) mutable {
    if (i >= n)
      return 0;
    if (dp_[i] != -1)
      return dp_[i];
    int ans = INT_MAX;
    int j = i;
    int d = days[i];

    while (j < n && days[j] < d + 1)
      j++;
    ans = min(ans, f(j) + costs[0]);
    while (j < n && days[j] < d + 7)
      j++;
    ans = min(ans, f(j) + costs[1]);
    while (j < n && days[j] < d + 30)
      j++;
    ans = min(ans, f(j) + costs[2]);
    return dp_[i] = ans;
  };
  return f(0);
}

// recursion with memory
bitset<366> need = 0;
int dp[366]; // It stores the minimum cost to cover the first d days. dp[d]
             // represents the minimum cost to cover the travel from day 1 to
             // day d
int f(int d, int d0, vector<int>& costs) {
  if (d < d0)
    return 0;
  if (!need[d])
    return f(d - 1, d0, costs);
  if (dp[d] != -1)
    return dp[d];
  return dp[d] = min({
             costs[0] + f(d - 1, d0, costs),
             costs[1] + f(d - 7, d0, costs),
             costs[2] + f(d - 30, d0, costs),
         });
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
  memset(dp, -1, sizeof(dp));
  for (auto& d : days)
    need[d] = 1;
  return f(days.back(), days[0], costs);
}

int main() {
  vector<int> days1, costs1, days2, costs2;
  days1 = parse_vector("[1,4,6,7,8,20]");
  costs1 = parse_vector("[2,7,15]");
  days2 = parse_vector("[1,2,3,4,5,6,7,8,9,10,30,31]");
  costs2 = costs1;

  print_res(mincostTickets, days1, costs1);
  print_res(mincostTickets, days2, costs2);

  return 0;
}
