#include <iostream>
#include <pulley/algorithms/take.hpp>
#include <pulley/algorithms/transform.hpp>
#include <pulley/algorithms/front.hpp>
#include <pulley/algorithms/back.hpp>
#include <pulley/algorithms/remove.hpp>

struct transformer
{
    template<typename T>
    constexpr auto operator()(T const &a)
    {
        return a + 1;
    }
};

template <typename T>
struct printer;

int main()
{
    constexpr std::tuple<int, int, int> t {1, 2, 3};
    constexpr auto f = pulley::algorithms::front(t);
    constexpr auto b = pulley::algorithms::back(t);
    constexpr auto tr = pulley::algorithms::transform(t, transformer {});
    constexpr auto ta = pulley::algorithms::take<2>(t);
    constexpr auto rm = pulley::algorithms::remove<float>(std::tuple<>{});
    constexpr auto tt = pulley::algorithms::remove<float>(std::make_tuple(1));
    constexpr auto tt1 = pulley::algorithms::remove<float>(std::make_tuple(1.0f, 1, 1.0f, 1));
    constexpr auto tt2 = pulley::algorithms::remove<float>(std::make_tuple(1, 1));
    
}