#ifndef PULLEY_TAIL_HPP
#define PULLEY_TAIL_HPP

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
            template<typename T, typename... Ts, size_t I, size_t... Is>
            constexpr T tail_impl(std::tuple<T, Ts...> const &t, std::index_sequence<Is...> is)
            {
                return std::make_tuple(std::get<Is>(t)...);
            }
        }
    
        template<typename TTuple>
        constexpr auto tail(TTuple const &t)
        {
            return detail::tail_impl(t, std::make_index_sequence<std::tuple_size<std::decay_t<TTuple>>::value> {});
        }
        
    }
}

#endif
