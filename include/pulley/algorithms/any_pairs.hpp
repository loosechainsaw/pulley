#ifndef PULLEY_ANY_PAIRS_HPP
#define PULLEY_ANY_PAIRS_HPP

#include <pulley/algorithms/skip.hpp>

namespace pulley
{
    namespace algorithms
    {
        namespace detail
        {

            template<typename P>
            constexpr bool any_pairs(std::tuple<> const &t, P &&predicate)
            {
                return false;
            }

            template<typename X, typename P>
            constexpr bool any_pairs(std::tuple<X> const &t, P &&predicate)
            {
                return false;
            }

            template<typename X, typename Y, typename P>
            constexpr bool any_pairs(std::tuple<X, Y> const &t, P &&predicate)
            {
                return predicate(std::get<0>(t), std::get<1>(t));
            }

            template< typename X, typename Y, typename... Xs, typename P>
            constexpr bool any_pairs(std::tuple<X, Y, Xs...> const &t, P &&predicate)
            {
                return predicate(std::get<0>(t), std::get<1>(t)) ? true :
                       any_pairs(skip<2>(t), std::forward<P>(predicate));
            }

        }

        template<typename TTuple, typename P>
        constexpr bool any_pairs(TTuple const &t, P &&predicate)
        {
            return detail::any_pairs(t, std::forward<P>(predicate));
        }
    }
}

#endif
