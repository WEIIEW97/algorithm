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

int main() {{
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
