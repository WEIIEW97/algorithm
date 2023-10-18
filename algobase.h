#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>

// leetcode struct definition
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#define PRINT_VECTOR_2D(x)                                                     \
  for (auto& v : x) {                                                          \
    cout << "[";                                                               \
    for (auto& w : v) {                                                        \
      cout << w << ",";                                                        \
    }                                                                          \
    cout << "]"                                                                \
         << "\n";                                                              \
  }

#define PRINT_VECTOR_1D(x)                                                     \
  for (auto& v : x)                                                            \
  cout << "[" << v << ",]"                                                     \
       << "\n"

template <class T>
bool is_unique(std::vector<T>& x) {
  sort(x.begin(), x.end()); // O(N log N)
  return adjacent_find(x.begin(), x.end()) == x.end();
}

inline int NCR(int n, int r) {
  if (r == 0 || r == n)
    return 1;
  else {
    long long m = 1;
    for (int i = 1; i <= r; i++) {
      m *= (n - i + 1);
      m /= i;
    }
    return m;
  }
}