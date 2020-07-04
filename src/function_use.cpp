#include <cstdio>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

struct Button
{
    std::vector<std::function<int(int)>> signals;

    template <typename T>
    const Button &operator+=(T &&f)
    {
        signals.push_back(f);
        return *this;
    }
};

int main_fu()
{
    Button b;
    b += [](int i) { std::cout << " -> " << i << std::endl; return i; };
    b += [](int j) { std::cout << " -> " << j << std::endl; return j; };

    std::cout << b.signals[0](3) << std::endl;
    std::cout << b.signals[1](4) << std::endl;

    return 0;
}