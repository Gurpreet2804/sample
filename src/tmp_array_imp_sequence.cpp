#include <bits/c++config.h>
#include <iostream>
#include <array>
#include <type_traits>
#include <utility>
#include <cassert>
using MyArray = std::array<int, 6>;

template<typename F, typename Array, std::size_t... Is>
std::size_t array_sum_imp(F&& f, Array&& arr, std::index_sequence<Is...>)
{
    return std::forward<F>(f)(arr[Is]...);
}

template<typename F, typename Array>
std::size_t  array_sum(F&& f, Array&& arr)
{
    //static_assert(std::is_array<C>::value, "No an arary");
    return array_sum_imp(
        std::forward<F>(f), 
        std::forward<Array>(arr),
        std::make_index_sequence<arr.size()>{});
}

int main()
{
    MyArray myarray{1,2,3,4,5,6};

    std::size_t sum = array_sum([](auto&&... element) { return (element + ... );}, myarray);
    assert(21 == sum);    
    return 0;
}