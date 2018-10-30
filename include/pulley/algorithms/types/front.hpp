#ifndef PULLEY_TYPES_FRONT_HPP
#define PULLEY_TYPES_FRONT_HPP

#include <tuple>
#include <pulley/utitlities/null_type.hpp>

namespace pulley {
    namespace algorithms {
        namespace types {
    
            template<typename T>
            struct front;
    
            template<>
            struct front<std::tuple<>>
            {
                typedef utilities::null_type type;
            };
    
            template<typename T, typename... Ts>
            struct front<std::tuple<T, Ts...>>
            {
                typedef T type;
            };
        }
    }
}

#endif
