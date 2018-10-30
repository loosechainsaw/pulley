#ifndef PULLEY_BACK_HPP
#define PULLEY_BACK_HPP

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
        
            template<typename T, typename... Ts>
            constexpr T &back_impl(std::tuple<T, Ts...> &t)
            {
                using type = std::decay_t<decltype(t)>;
                return std::get<std::tuple_size<type>::value - 1>(t);
            }
        
            template<typename T, typename... Ts>
            constexpr T const &back_impl(std::tuple<T, Ts...> const &t)
            {
                using type = std::decay_t<decltype(t)>;
                return std::get<std::tuple_size<type>::value - 1>(t);
            }
        
            template<typename T, typename... Ts>
            constexpr T back_impl(std::tuple<T, Ts...> &&t)
            {
                using type = std::decay_t<decltype(t)>;
                return std::get<std::tuple_size<type>::value - 1>(t);
            }
        }
    
        template<typename TTuple>
        constexpr decltype(auto) back(TTuple &&t)
        {
            return detail::back_impl(std::forward<TTuple>(t));
        }
    }
}

#endif
