#include <iostream>
#include <pulley/algorithms/take.hpp>
#include <pulley/algorithms/transform.hpp>
#include <pulley/algorithms/front.hpp>
#include <pulley/algorithms/back.hpp>


template<typename P>
struct type_printer;

struct transformer
{
    template<typename T>
    constexpr auto operator()(T const &a)
    {
        return a + 1;
    }
};

int main()
{
    constexpr std::tuple<int, int, int> t {1, 2, 3};
    constexpr auto f = pulley::algorithms::front(t);
    constexpr auto b = pulley::algorithms::back(t);
    constexpr auto tr = pulley::algorithms::transform(t, transformer {});
    constexpr auto ta = pulley::algorithms::take<2>(t);
}