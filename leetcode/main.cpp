/*
 * Copyright (c) 2022-${year}, William Wei. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>
using namespace std;

class Base {
public:
  int a_, b_;
  Base(int a, int b) : a_(a), b_(b) {}
  ~Base() = default;
  int add() {
    int res = a_ + b_;
    return res;
  }
};

class Inhert : public Base {
public:
  Inhert(int a, int b) : Base(a, b) {}
  ~Inhert() = default;
  int multipy() { return a_ * b_; }
};

int main() {
  auto calculator1 = Base(3, 5);
  auto calculator2 = Inhert(4, 5);
  auto add_number1 = calculator1.add();
  auto add_number2 = calculator2.add();
  auto time_number2 = calculator2.multipy();

  cout << add_number1 << add_number2 << time_number2 << endl;
  return 0;
}