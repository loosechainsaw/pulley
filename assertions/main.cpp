#include <iostream>
#include <pulley/algorithms/take.hpp>
#include <pulley/algorithms/transform.hpp>
#include <pulley/algorithms/front.hpp>
#include <pulley/algorithms/back.hpp>
#include <pulley/algorithms/remove.hpp>
#include <pulley/algorithms/skip.hpp>
#include <pulley/algorithms/tail.hpp>
#include <pulley/algorithms/count_if.hpp>
#include <pulley/algorithms/all_of.hpp>
#include <pulley/algorithms/find.hpp>
#include <pulley/algorithms/for_each.hpp>

template<typename T>
struct printer;

int main()
{
    using namespace pulley::algorithms;
    
    constexpr auto t1 = std::make_tuple(1.0, 2, 3, 6, 99.0);
    
    constexpr auto t2 = count_if(t1, [](auto const &arg) { return arg > 5; });
    static_assert(t2 == 2);
    
    constexpr auto t3 = all_of(t1, [](auto const &arg) { return arg > 0; });
    static_assert(t3);
    
    constexpr auto t4 = tail(t1);
    static_assert(std::is_same<decltype(t4), const std::tuple<int, int, int, double>>::value);
    
    constexpr auto t5 = back(t1);
    static_assert(std::is_same<decltype(t5), const double>::value);
    
    constexpr auto t6 = front(t1);
    static_assert(std::is_same<decltype(t6), const double>::value);
    
    constexpr auto t7 = remove<double>(t1);
    static_assert(std::is_same<decltype(t7), const std::tuple<int, int, int>>::value);
    
    constexpr auto t8 = pulley::algorithms::find<int>(t1);
    static_assert(t8 == 2);
    
    constexpr auto t9 = pulley::algorithms::find<float>(t1);
    static_assert(std::is_same_v<decltype(t9), const pulley::utilities::null_type>);
    
    pulley::algorithms::for_each(t1, [](auto const& arg){
    
    });
    
}

