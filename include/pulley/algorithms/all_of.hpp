#ifndef PULLEY_ALL_OF_HPP
#define PULLEY_ALL_OF_HPP

#include <pulley/algorithms/count_if.hpp>

namespace pulley {
    namespace algorithms {
        
        template<typename TTuple, typename F>
        constexpr int all_of(TTuple const &t, F &&f)
        {
            return detail::count_if(t, std::forward<F>(f)) == std::tuple_size<TTuple>::value;
        }
    }
}

#endif
