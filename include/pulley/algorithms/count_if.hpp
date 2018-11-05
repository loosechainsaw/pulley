#ifndef PULLEY_COUNT_IF_HPP
#define PULLEY_COUNT_IF_HPP

#include <pulley/algorithms/tail.hpp>

namespace pulley {
    namespace algorithms {
        namespace detail {
            
            template<typename F>
            constexpr int count_if(std::tuple<> const& t, F&& f) {
                return 0;
            }
            
            template<typename T, typename... Ts, typename F>
            constexpr int count_if(std::tuple<T, Ts...> const& t, F&& f){
                return f(std::get<0>(t)) ? 1 + count_if(tail(t), std::forward<F>(f)) : count_if(tail(t), std::forward<F>(f));
            }
            
        }
        
        template<typename TTuple, typename F>
        constexpr int count_if(TTuple const& t, F&& f){
            return detail::count_if(t, std::forward<F>(f));
        }
    }
}

#endif
