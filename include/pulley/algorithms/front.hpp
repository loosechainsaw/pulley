#ifndef PULLEY_FRONT_HPP
#define PULLEY_FRONT_HPP

#include <tuple>
#include <utility>

namespace pulley {
    namespace algorithms {
        namespace detail {
        
            template<typename T, typename... Ts>
            constexpr T &front_impl(std::tuple<T, Ts...> &t)
            {
                return std::get<0>(t);
            }
        
            template<typename T, typename... Ts>
            constexpr T const &front_impl(std::tuple<T, Ts...> const &t)
            {
                return std::get<0>(t);
            }
        
            template<typename T, typename... Ts>
            constexpr T front_impl(std::tuple<T, Ts...> &&t)
            {
                return std::get<0>(t);
            }
        }
    
        template<typename TTuple>
        constexpr decltype(auto) front(TTuple &&t)
        {
            return detail::front_impl(std::forward<TTuple>(t));
        }
    }
}

#endif
