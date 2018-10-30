#ifndef PULLEY_TAKE_HPP
#define PULLEY_TAKE_HPP

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
            template<typename T, typename... Ts, size_t... Is>
            constexpr auto take_impl(std::tuple<T, Ts...> const &t, std::index_sequence<Is...> is)
            {
                return std::make_tuple(std::get<Is>(t)...);
            }
        }
    
        template<size_t N, typename TTuple>
        constexpr auto take(TTuple const &t)
        {
            return detail::take_impl(t, std::make_index_sequence<N> {});
        }
    }
}

#endif
