import argparse
import os

CURWCPATH = os.path.dirname(__file__)


def generate_cpp_template(filename, num):
    template_code = """\
/**
The problem description goes here.

source from: leetcode {}.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto __optimize = []() {{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}}();
#endif
#endif

// macOS-specific optimizations with Clang
#if defined(__APPLE__) && defined(__MACH__)
#if defined(__clang__)
#pragma clang optimize on
static auto __optimize = []() {{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}}();
#endif
#endif

// Windows-specific optimizations with MSVC
#if defined(_WIN32)
#if defined(_MSC_VER)
#include <cstdlib>
#pragma optimize("t", on)
static auto __optimize = []() {{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}}();
#endif
#endif

int main() {{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Your code here
    return 0;
}}
    """.format(num)
    with open(os.path.join(CURWCPATH, filename), "w") as f:
        f.write(template_code)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="codegen")
    parser.add_argument(
        "--name", type=str, help="cpp file name", default="template.cpp"
    )
    parser.add_argument(
        "--num", type=int, help="leetcode question number", default="-1"
    )
    args = parser.parse_args()

    generate_cpp_template(args.name, args.num)
    print(f"C++ template code has been generated in {args.name}, which is from leetcode {args.num}")
