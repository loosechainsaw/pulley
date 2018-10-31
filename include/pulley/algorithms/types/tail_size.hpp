#ifndef PULLEY_TYPE_TAIL_LENGTH_HPP
#define PULLEY_TYPE_TAIL_LENGTH_HPP

#include <tuple>
#include <type_traits>

namespace pulley {
    namespace algorithms {
        namespace types {
            
            template<typename TTuple>
            struct tail_size;
            
            template<>
            struct tail_size<std::tuple<>> : public std::integral_constant<int, 0>
            {
            };
            
            template<typename T>
            struct tail_size<std::tuple<T>> : public std::integral_constant<int, 0>
            {
            };
            
            template<typename T, typename... Ts>
            struct tail_size<std::tuple<T, Ts...>> : public std::integral_constant<int, sizeof...(Ts)>
            {
            };
        }
    }
}

#endif
