#ifndef PULLEY_TYPE_BACK_HPP
#define PULLEY_TYPE_BACK_HPP

#include <tuple>
#include <pulley/utitlities/null_type.hpp>

namespace pulley {
    namespace algorithms {
        namespace types {
            
            template<typename T>
            struct back;
            
            template<>
            struct back<std::tuple<>>
            {
                typedef utilities::null_type type;
            };
            
            template<typename T>
            struct back<std::tuple<T>>
            {
                typedef utilities::null_type type;
            };
            
            template<typename T, typename U>
            struct back<std::tuple<T, U>>
            {
                typedef U type;
            };
            
            template<typename T, typename... Ts>
            struct back<std::tuple<T, Ts...>>
            {
                typedef typename back<std::tuple<Ts...>>::type type;
            };
            
        }
    }
}

#endif
