#pragma once

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// leetcode struct definition
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define PRINT_VECTOR_2D(x)                                                     \
  for (auto &v : x) {                                                          \
    cout << "[";                                                               \
    for (auto &w : v) {                                                        \
      cout << w << ",";                                                        \
    }                                                                          \
    cout << "]"                                                                \
         << "\n";                                                              \
  }

#define PRINT_VECTOR_1D(x)                                                     \
  for (auto &v : x)                                                            \
  cout << "[" << v << ",]"                                                     \
       << "\n"