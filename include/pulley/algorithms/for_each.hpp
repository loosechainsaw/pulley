#ifndef PULLEY_FOR_EACH_H
#define PULLEY_FOR_EACH_H

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
            template<typename... Ts, size_t... Is, typename F>
            constexpr void for_each(std::tuple<Ts...> const& t, std::index_sequence<Is...> is, F&& f) {
                std::initializer_list<int> i{(f(std::get<Is>(t)), 0)... };
            }
        
        }
        
        template<typename... Ts, typename F>
        constexpr void for_each(std::tuple<Ts...> const& t, F&& f) {
            detail::for_each(t, std::make_index_sequence<std::tuple_size<std::tuple<Ts...>>::value>{}, std::forward<F>(f));
        }
    }
}

#endif
