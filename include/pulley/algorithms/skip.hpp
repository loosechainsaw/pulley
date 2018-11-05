#ifndef PULLEY_SKIP_HPP
#define PULLEY_SKIP_HPP

#include <tuple>

namespace pulley {
    namespace algorithms {
        namespace detail {
            
            template<int N, typename... Ts, size_t... Is>
            constexpr auto skip(std::tuple<Ts...> const &t, std::index_sequence<Is...> is)
            {
                return std::make_tuple(std::get<N + Is>(t)...);
            }
        }
        
        template<int N, typename TTuple>
        constexpr auto skip(TTuple const &t)
        {
            return detail::skip<N>(t, std::make_index_sequence<std::tuple_size<TTuple>::value - N> {});
        }
        
    }
}

#endif
