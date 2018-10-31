#ifndef PULLEY_AT_HPP
#define PULLEY_AT_HPP

#include <tuple>

namespace pulley {
    namespace algorithms {
        namespace detail {
            
            template<typename T, typename TTuple>
            struct remove;
            
            template<typename T >
            struct remove<T, std::tuple<>>
            {
                template<size_t... Is>
                static constexpr decltype(auto) apply(std::tuple<> const& t, std::index_sequence <Is...> is){
                    return t;
                }
            };
    
            template<typename R, typename T, typename... Ts >
            struct remove<R, std::tuple<T, Ts...>>
            {
                template<size_t I, size_t... Is>
                static constexpr auto apply(std::tuple<T, Ts...> const& t, std::index_sequence <I, Is...> is){
                    return std::tuple_cat(std::make_tuple(std::get<I>(t)),
                            remove<R, std::tuple<Ts...>>::apply( std::make_tuple(std::get<Is>(t)...),
                                                                 std::make_index_sequence<std::tuple_size<std::tuple<Ts...>>::value>{}));
                }
            };
    
            template<typename T, typename... Ts >
            struct remove<T, std::tuple<T, Ts...>>
            {
                template<size_t I, size_t... Is>
                static constexpr auto apply(std::tuple<T, Ts...> const& t, std::index_sequence <I, Is...> is){
                    return remove<T, std::tuple<Ts...>>::apply( std::make_tuple(std::get<Is>(t)...),
                                                                std::make_index_sequence<std::tuple_size<std::tuple<Ts...>>::value>{});
                }
            };
        }
        
        template<typename R, typename TTuple>
        constexpr auto remove(TTuple const &t)
        {
            return detail::remove<R, TTuple>::apply(t, std::make_index_sequence<std::tuple_size<TTuple>::value>{});
        }
        
    }
}

#endif
