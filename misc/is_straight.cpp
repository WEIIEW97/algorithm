/**
In a deck of cards, the Jokers represent any number, and J, Q, K represent 10,
11, and 12 respectively. Given five cards, we need to design an algorithm to
determine if they form a "straight" (a sequence of consecutive numbers), taking
into account that Jokers can represent any number.
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

bool isStraight(vector<int>& hand) {
  sort(hand.begin(), hand.end());
  int king_cnt = 0;
  unordered_set<int> seen;

  for (int i = 0; i < 5; i++) {
    if (hand[i] == 0)
      king_cnt++;
    else if (seen.count(hand[i]))
      return false;
    else
      seen.insert(hand[i]);
  }

  int minv = 14, maxv = -1;
  for (int i = 0; i < 5; ++i) {
    if (hand[i] != 0) {
      minv = min(minv, hand[i]);
      maxv = max(maxv, hand[i]);
    }
  }
  if (maxv - minv <= 4)
    return true;
  return (king_cnt >= maxv - minv - 4);
}

int main() {
  // Example input: five cards, 0 represents a Joker, J, Q, K are 11, 12, 13
  vector<int> hand = {0, 5, 4, 3, 2};

  print_res(isStraight, hand);

  return 0;
}