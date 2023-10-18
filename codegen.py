import argparse
import os

CURWCPATH = os.path.dirname(__file__)


def generate_cpp_template(filename):
    template_code = """\
    /**
    The problem description goes here.
    */
    
    #include "algobase.h"
    using namespace std;

    int main() {
        // Your code here
        return 0;
    }
    """
    with open(os.path.join(CURWCPATH, filename), "w") as f:
        f.write(template_code)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="codegen")
    parser.add_argument(
        "--name", type=str, help="cpp file name", default="template.cpp"
    )
    args = parser.parse_args()

    generate_cpp_template(args.name)
    print(f"C++ template code has been generated in {args.name}")
