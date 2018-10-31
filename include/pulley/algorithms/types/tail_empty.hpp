#ifndef PULLEY_TYPES_TAIL_EXISTS_HPP
#define PULLEY_TYPES_TAIL_EXISTS_HPP

#include <tuple>

namespace pulley {
    namespace algorithms{
        namespace types {
            
            template<typename TTuple>
            struct tail_empty;
            
            template<typename... Ts>
            struct tail_empty<std::tuple<Ts...>> {
                static const bool value = std::tuple_size<std::tuple<Ts...>>::value < 2;
            };
            
        }
    }
}

#endif
