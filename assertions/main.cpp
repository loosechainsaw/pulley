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
#include <pulley/algorithms/adjacent_elements_for_each.hpp>
#include <pulley/algorithms/adjacent_elements_for_each_if.hpp>
#include <pulley/algorithms/any_pairs.hpp>

template<typename T>
struct printer;

struct greater_5{
    constexpr bool operator()(int v){
        return v > 5;
    }
};

struct greater_0{
    constexpr bool operator()(int v){
        return v > 0;
    }
};

struct compare_double_integer_pairs{
    template<typename T, typename U>
    constexpr bool operator()(T a, U b){
        return std::is_same<decltype(a), double>::value && std::is_same<decltype(b), int>::value;
    }
};

struct compare_float_integer_pairs{
    template<typename T, typename U>
    constexpr bool operator()(T a, U b){
        return std::is_same<decltype(a), float>::value && std::is_same<decltype(b), int>::value;
    }
};

struct compare_integer_integer_pairs{
    template<typename T, typename U>
    constexpr bool operator()(T a, U b){
        return std::is_same<decltype(a), int>::value && std::is_same<decltype(b), int>::value;
    }
};

struct print_element {
    template<typename T>
    constexpr void operator()(T arg1){
        std::cout << "[" << arg1 << "]" << std::endl;
    }
};

struct print_pair {
    template<typename T, typename U>
    constexpr void operator()(T arg1, U arg2){
        std::cout << "[" << arg1 << "," << arg2 << "]" << std::endl;
    }
};

struct first_double_second_int {
    template<typename T, typename U>
    constexpr bool operator()(T const& arg1, U const& arg2){
            return std::is_same<double, std::decay_t<decltype(arg1)>>::value &&
                   std::is_same<int, std::decay_t<decltype(arg2)>>::value;
        }
};

int main()
{
    using namespace pulley::algorithms;
    
    constexpr auto t1 = std::make_tuple(1.0, 2, 3, 6, 99.0);

#if defined(__GNUC__) && (__GNUC___ > 7 || (__GNUC__ == 7 && __GNUC_MINOR__ >= 1))
    constexpr auto t2 = count_if(t1, [](auto const &arg) { return arg > 5; });
#else
    constexpr auto t2 = count_if(t1, greater_5{});
#endif
    static_assert(t2 == 2);

#if defined(__GNUC__) && (__GNUC___ > 7 || (__GNUC__ == 7 && __GNUC_MINOR__ >= 1))
    constexpr auto t3 = all_of(t1, [](auto const &arg) { return arg > 0; });
#else
    constexpr auto t3 = all_of(t1, greater_0{});
#endif
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
    static_assert(std::is_same<decltype(t9), const pulley::utilities::null_type>::value);
    
    pulley::algorithms::for_each(t1, print_element{});
    
    pulley::algorithms::adjacent_elements_for_each(t1, print_pair{});

    pulley::algorithms::adjacent_elements_for_each_if(t1, first_double_second_int{}, print_pair{});

    constexpr auto t10 = pulley::algorithms::any_pairs(t1, compare_double_integer_pairs{});

    static_assert(t10);

    constexpr auto t11 = pulley::algorithms::any_pairs(t1, compare_float_integer_pairs{});

    static_assert(!t11);

    constexpr auto t12 = pulley::algorithms::any_pairs(t1, compare_integer_integer_pairs{});

    static_assert(t12);
}

