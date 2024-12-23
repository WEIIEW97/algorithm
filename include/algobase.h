#pragma once

#include <algorithm>
#include <bitset>
#include <string>
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
#include <utility>
#include <vector>
#include <functional>
#include <type_traits>

#define PRINT_VECTOR_2D(x)                                                     \
  for (auto& v : x) {                                                          \
    std::cout << "[";                                                          \
    for (auto& w : v) {                                                        \
      std::cout << w << ",";                                                   \
    }                                                                          \
    std::cout << "]" << "\n";                                                  \
  }

#define PRINT_VECTOR_1D(x)                                                     \
  for (auto& v : x)                                                            \
    std::cout << "[" << v << ",]" << "\n";

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

inline std::vector<int> parse_vector(const std::string& input) {
  std::vector<int> result;
  std::string number, token;

  for (auto& ch : input) {
    if (ch == '[' || std::isspace(static_cast<unsigned char>(ch)))
      continue;
    else if (ch == 'n' || ch == 'u' || ch == 'l')
      token.push_back(ch);
    else if (isdigit(ch) || ch == '-') {
      number.push_back(ch);
    } else if (ch == ',' || ch == ']') {
      if (!number.empty()) {
        result.push_back(std::stoi(number));
        number.clear();
      }
      if (token == "null") {
        result.push_back(-1);
        token.clear();
      }
    }
  }
  return result;
}

inline std::vector<std::vector<int>> parse_matrix(const std::string& input) {
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

// Helper to determine if a type is a std::vector
template <typename T>
struct is_vector : std::false_type {};

template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc>> : std::true_type {};

// Helper to print elements of a container
template <typename Container>
void printContainer(const Container& container) {
  for (const auto& elem : container) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

template <typename Func, typename... Args>
void print_res(Func func, Args&&... args) {
  // Deduce the return type of the function
  using ReturnType = typename std::invoke_result<Func, Args...>::type;

  if constexpr (std::is_void<ReturnType>::value) {
    func(std::forward<Args>(args)...);
  } else {
    // Execute the function with forwarded arguments
    ReturnType result = func(std::forward<Args>(args)...);

    // Use if constexpr to handle different types at compile time
    if constexpr (std::is_same<ReturnType, bool>::value) {
      std::cout << (result ? "true" : "false") << std::endl;
    } else if constexpr (is_vector<ReturnType>::value) {
      std::cout << "Vector elements: ";
      printContainer(result);
    } else if constexpr (std::is_integral<ReturnType>::value ||
                         std::is_floating_point<ReturnType>::value) {
      std::cout << "The result is: " << result << std::endl;
    } else {
      // Generic print for types that support std::ostream operator<<
      std::cout << "The result is: " << result << std::endl;
    }
  }
}