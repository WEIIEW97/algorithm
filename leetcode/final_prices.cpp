/**
You are given an integer array prices where prices[i] is the price of the ith
item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then
you will receive a discount equivalent to prices[j] where j is the minimum index
such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any
discount at all.

Return an integer array answer where answer[i] is the final price you will pay
for the ith item of the shop, considering the special discount.



Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to
prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. For item 1
with price[1]=4 you will receive a discount equivalent to prices[3]=2,
therefore, the final price you will pay is 4 - 2 = 2. For item 2 with price[2]=6
you will receive a discount equivalent to prices[3]=2, therefore, the final
price you will pay is 6 - 2 = 4. For items 3 and 4 you will not receive any
discount at all. Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at
all. Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]


Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 1000

source from: leetcode 1475.
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

vector<int> finalPrices(vector<int>& prices) {
  int n = prices.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (prices[i] >= prices[j]) {
        prices[i] -= prices[j];
        break;
      }
    }
  }
  return prices;
}

int main() {
  vector<int> prices1, prices2, prices3;
  prices1 = parse_vector("[8,4,6,2,3]");
  prices2 = parse_vector("[1,2,3,4,5]");
  prices3 = parse_vector("[10,1,1,6]");

  print_res(finalPrices, prices1);
  print_res(finalPrices, prices2);
  print_res(finalPrices, prices3);

  return 0;
}
