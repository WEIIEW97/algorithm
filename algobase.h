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
    std::cout << "[";                                                          \
    for (auto& w : v) {                                                        \
      std::cout << w << ",";                                                   \
    }                                                                          \
    std::cout << "]"                                                           \
              << "\n";                                                         \
  }

#define PRINT_VECTOR_1D(x)                                                     \
  for (auto& v : x)                                                            \
    std::cout << "[" << v << ",]"                                              \
              << "\n";

#define PRINT_MAP(x)                                                           \
  for (auto& kv : x) {                                                         \
    std::cout << "key: " << kv.first << " value: " << kv.second << "\n";       \
  }

#define ll  long long
#define ull unsigned long long

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

inline ull f(int n) {
  ull res = 1;
  if (n == 0)
    return res;
  for (int i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

inline ull NPR(int n, int r) {
  if (r >= n)
    return f(r) / f(r - n);
  return f(n) / f(n - r);
}

std::vector<std::vector<int>> parse_matrix(const std::string& input) {
  std::vector<std::vector<int>> result;
  std::vector<int> row;
  std::string number;

  for (char ch : input) {
    if (isdigit(ch) || ch == '-') {
      number.push_back(ch);
    } else if (ch == ',' || ch == ']') {
      if (!number.empty()) {
        row.push_back(std::stoi(number));
        number.clear();
      }
      if (ch == ']' && !row.empty()) {
        result.push_back(row);
        row.clear();
      }
    }
  }

  return result;
}