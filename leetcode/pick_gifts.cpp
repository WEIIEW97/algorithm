/**
You are given an integer array gifts denoting the number of gifts in various
piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile.
Take the rest of the gifts. Return the number of gifts remaining after k
seconds.



Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts
remaining is 29. Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift
in each pile. That is, you can't take any pile with you. So, the total gifts
remaining are 4.


source from: leetcode 2558.
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

// brutal force
long long pickGiftsV1(vector<int>& gifts, int k) {
  long long ans;
  while (k > 0) {
    sort(gifts.begin(), gifts.end());
    gifts.back() = floor(sqrt(gifts.back()));
    k--;
  }
  ans = accumulate(gifts.begin(), gifts.end(), 0LL);
  return ans;
}

long long pickGifts(vector<int>& gifts, int k) {
  priority_queue<int> q;
  long long ans = 0;
  for (auto v : gifts) {
    q.push(v);
    ans += v;
  }

  while (k--) {
    int v = q.top();
    ans -= (v - sqrt(v));
    q.pop();
    q.push(sqrt(v));
  }
  return ans;
}

int main() {
  vector<int> gifts1, gifts2;
  gifts1 = parse_vector("[25,64,9,4,100]");
  gifts2 = parse_vector("[1,1,1,1]");

  print_res(pickGifts, gifts1, 4);
  print_res(pickGifts, gifts2, 4);

  return 0;
}
