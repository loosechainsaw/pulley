#ifndef PROJECT_FIND_HPP
#define PROJECT_FIND_HPP

#include <pulley/utitlities/null_type.hpp>
#include <pulley/algorithms/tail.hpp>

namespace pulley {
    namespace algorithms {
        namespace detail {
            template<typename TTuple, typename R>
            struct find;
            
            template<typename R>
            struct find<R, std::tuple<>>{
                constexpr static auto apply(std::tuple<> t){
                    return pulley::utilities::null_type{};
                };
            };
    
            template<typename T, typename R>
            struct find<R, std::tuple<T>>{
                constexpr static auto apply(std::tuple<T> t){
                    return pulley::utilities::null_type{};
                };
            };
        
            template<typename T, typename... Ts>
            struct find<T, std::tuple<T, Ts...>>{
                constexpr static auto apply(std::tuple<T,Ts...> t){
                    return std::get<0>(t);
                }
            };
    
            template<typename T, typename... Ts, typename R>
            struct find<R, std::tuple<T, Ts...>> {
                constexpr static auto apply(std::tuple<T, Ts...> t){
                    return find<R,std::tuple<Ts...>>::apply(tail(t));
                }
            };
        }
        
        template<typename T, typename TTuple>
        constexpr auto find(TTuple t)
        {
            return detail::find<T, std::decay_t<decltype(t)>>::apply(t);
        }
    }
}

#endif
