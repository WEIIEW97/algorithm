/**
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit =
6-3 = 3. Total profit is 4 + 3 = 7. Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4. Total profit is 4. Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the
stock to achieve the maximum profit of 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

source from: leetcode 122.
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

int maxProfit(vector<int>& prices) {
  int v = 0, prev = 0;
  int n = prices.size();
  bool hold = false;
  for (int i = 0; i < n; i++) {
    bool end = (i == (n - 1));
    if (!end) {
      if (!hold && prices[i] < prices[i + 1]) {
        v -= prices[i];
        prev = prices[i];
        hold = true;
      } else if (hold && prices[i] >= prices[i + 1]) {
        v += prices[i];
        hold = false;
      }
    } else if (hold) {
      if (prices.back() > prev)
        v += prices.back();
    }
  }
  return v;
}


// one line solution
int maxProfit1(vector<int>& prices) {
  int v = 0;
  int n = prices.size();
  for (int i = 1; i < n; i++) {
    if (prices[i] > prices[i - 1]) {
      v += prices[i] - prices[i - 1];
    }
  }
  return v;
}

int main() {
  vector<int> prices1, prices2, prices3, prices4;
  prices1 = parse_vector("[7,1,5,3,6,4]");
  prices2 = parse_vector("[1,2,3,4,5]");
  prices3 = parse_vector("[7,6,4,3,1]");
  prices4 = parse_vector("[1]");

  print_res(maxProfit1, prices1);
  print_res(maxProfit1, prices2);
  print_res(maxProfit1, prices3);
  print_res(maxProfit1, prices4);

  return 0;
}
