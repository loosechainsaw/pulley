#ifndef PULLEY_TYPE_TRANSFORM_HPP
#define PULLEY_TYPE_TRANSFORM_HPP

#include <tuple>

namespace pulley {
    namespace algorithms {
        namespace types {
    
            template<typename T, typename F>
            struct transform;
    
            template<typename F>
            struct transform<std::tuple<>, F>
            {
                typedef std::tuple<> type;
            };
    
            template<typename... Ts, typename F>
            struct transform<std::tuple<Ts...>, F>
            {
                typedef std::tuple<typename F::template apply<Ts>::type...> type;
            };
        }
    }
}
#endif
