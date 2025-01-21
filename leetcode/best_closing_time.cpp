/**
You are given the customer visit log of a shop represented by a 0-indexed string
customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as
follows:

For every hour when the shop is open and no customers come, the penalty
increases by 1. For every hour when the shop is closed and customers come, the
penalty increases by 1. Return the earliest hour at which the shop must be
closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the
hour j.



Example 1:

Input: customers = "YYNY"
Output: 2
Explanation:
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier,
the optimal closing time is 2. Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers
arrive. Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at
each hour.


Constraints:

1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.

source from: leetcode 2483.
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

int bestClosingTime(string customers) {
  int n = customers.size();
  vector<int> Y(n + 1, 0);
  vector<int> N(n + 1, 0);
  for (int i = 0; i < n; i++) {
    N[i + 1] = N[i] + (customers[i] == 'N' ? 1 : 0);
  }
  for (int j = n - 1; j >= 0; j--) {
    Y[j] = Y[j + 1] + (customers[j] == 'Y' ? 1 : 0);
  }

  int min_cost = INT_MAX, min_i = -1;
  for (int k = 0; k <= n; k++) {
    auto cur_sum = Y[k] + N[k];
    if (cur_sum < min_cost) {
      min_cost = cur_sum;
      min_i = k;
    }
  }
  return min_i;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  print_res(bestClosingTime, "YYNY");
  print_res(bestClosingTime, "NNNNN");
  print_res(bestClosingTime, "YYYY");

  return 0;
}
