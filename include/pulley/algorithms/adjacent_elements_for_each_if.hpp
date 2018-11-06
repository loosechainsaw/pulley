#ifndef PULLEY_ADJACENT_ELEMENTS_FOR_EACH_IF_H
#define PULLEY_ADJACENT_ELEMENTS_FOR_EACH_IF_H

#include <pulley/algorithms/skip.hpp>

namespace pulley {
    namespace algorithms {
        namespace detail {
            
            template<typename P,typename F>
            constexpr void adjacent_elements_for_each_if(std::tuple<> t, P&& p, F &&f)
            {
            }
    
            template< typename T, typename P, typename F>
            constexpr void adjacent_elements_for_each_if(std::tuple<T> t, P&& p, F &&f)
            {
            }
            
            template<typename T, typename U, typename P, typename F>
            constexpr void adjacent_elements_for_each_if(std::tuple<T, U> t, P&& p, F &&f)
            {
                if(p(std::get<0>(t), std::get<1>(t)))
                    f(std::get<0>(t), std::get<1>(t));
            }
            
            template<typename T, typename U, typename... Ts, typename P, typename F>
            constexpr void adjacent_elements_for_each_if(std::tuple<T, U, Ts...> t, P&& p, F &&f)
            {
                if(p(std::get<0>(t), std::get<1>(t)))
                    f(std::get<0>(t), std::get<1>(t));

                adjacent_elements_for_each_if(tail(t), std::forward<P>(p), std::forward<F>(f));
            }
            
        }
        
        template< typename... Ts, typename P, typename F>
        constexpr void adjacent_elements_for_each_if(std::tuple<Ts...> t, P&& p, F &&f)
        {
            detail::adjacent_elements_for_each_if(t, std::forward<P>(p), std::forward<F>(f));
        }
    }
}

#endif
