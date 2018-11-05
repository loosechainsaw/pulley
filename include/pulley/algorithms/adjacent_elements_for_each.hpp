#ifndef PULLEY_ADJACENT_ELEMENTS_FOR_EACH_H
#define PULLEY_ADJACENT_ELEMENTS_FOR_EACH_H

#include <pulley/algorithms/skip.hpp>

namespace pulley {
    namespace algorithms {
        namespace detail {
    
            template<typename F>
            constexpr auto adjacent_elements_for_each(std::tuple<> t, F&& f) {
            }
            
            template<typename T, typename U, typename F>
            constexpr auto adjacent_elements_for_each(std::tuple<T, U> t, F&& f) {
                f(std::get<0>(t), std::get<1>(t));
            }
    
            template<typename T, typename U, typename... Ts, typename F>
            constexpr auto adjacent_elements_for_each(std::tuple<T, U, Ts...> t, F&& f) {
                f(std::get<0>(t), std::get<1>(t));
                adjacent_elements_for_each(skip<2>(t), std::forward<F>(f));
            }
            
        }
    }
    
    template<typename... Ts, typename F>
    constexpr auto adjacent_elements_for_each(std::tuple<Ts...> t, F&& f) {
        detail::adjacent_elements_for_each(t, std::forward<F>(f));
    }
}

#endif
