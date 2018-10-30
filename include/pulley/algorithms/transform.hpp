#ifndef PULLEY_TRANSFORM_HPP
#define PULLEY_TRANSFORM_HPP

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
            template<typename F, typename T, typename... Ts, size_t... Is>
            constexpr auto transform_impl(std::tuple<T, Ts...> const &t, std::index_sequence<Is...> is, F &&f)
            {
                return std::make_tuple(f(std::get<Is>(t))...);
            }
        }
    
        template<typename TTuple, typename F>
        constexpr decltype(auto) transform(TTuple const &t, F &&f)
        {
            return detail::transform_impl(t, std::make_index_sequence<std::tuple_size<std::decay_t<TTuple>>::value> {},
                                          std::forward<F>(f));
        }
    }
}

#endif
