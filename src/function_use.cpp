#include <array>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

namespace {
struct Button {
  std::vector<std::function<int(int)>> signals;

  template <typename T> const Button &operator+=(T &&f) {
    signals.push_back(f);
    return *this;
  }
};

} // namespace
int main_fu() {
  Button b;
  b += [](int i) {
    std::cout << " -> " << i << std::endl;
    return i;
  };
  b += [](int j) {
    std::cout << " -> " << j << std::endl;
    return j;
  };

  std::cout << b.signals[0](3) << std::endl;
  std::cout << b.signals[1](4) << std::endl;

  return 0;
}