#include <array>
#include <bits/c++config.h>
#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>

namespace 
{
    
using MyArray = std::array<int, 6>;

template <typename F, typename Array, std::size_t... Is>
void array_sum_imp(F &&f, Array &&arr, std::index_sequence<Is...>) 
{
  (std::forward<F>(f)(std::integral_constant<int, Is>{}), ...);
}

template <typename F, typename Array> void array_sum(F &&f, Array &&arr) 
{
  // static_assert(std::is_array<C>::value, "No an arary");
  array_sum_imp(std::forward<F>(f), std::forward<Array>(arr),
                std::make_index_sequence<arr.size()>{});
}

} // namespace

int main() {
  MyArray myarray{1, 2, 3, 4, 5, 6};

  array_sum([](auto &&element) { std::cout << element; }, myarray);
  // assert(21 == sum);
  return 0;
}