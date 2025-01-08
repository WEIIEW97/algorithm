/**
You have a long flowerbed in which some of the plots are planted, and some are
not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and
1 means not empty, and an integer n, return true if n new flowers can be planted
in the flowerbed without violating the no-adjacent-flowers rule and false
otherwise.

source from: leetcode 605.
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

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int k = flowerbed.size();
  for (int i = 0; i < k; i++) {
    if (flowerbed[i] == 0) {
      bool el = (i == 0) || (flowerbed[i - 1] == 0);
      bool er = (i == k - 1) || (flowerbed[i + 1] == 0);
      if (el && er) {
        flowerbed[i] = 1;
        n--;
        if (n == 0)
          return true;
      }
    }
  }
  return n <= 0;
}

int main() {
  vector<int> flowerbed1, flowerbed2;
  flowerbed1 = parse_vector("[1,0,0,0,1]");
  flowerbed2 = parse_vector("[1,0,0,0,1,0,0]");

  print_res(canPlaceFlowers, flowerbed1, 1);
  print_res(canPlaceFlowers, flowerbed2, 2);

  return 0;
}
