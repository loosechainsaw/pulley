#ifndef PULLEY_FOR_EACH_H
#define PULLEY_FOR_EACH_H

#include <tuple>
#include <utility>
#include <pulley/algorithms/tail.hpp>

namespace pulley
{
    namespace algorithms
    {
        namespace detail
        {

#if defined(__GNUC__) && (__GNUC___ >= 7)
            template<typename... Ts, size_t... Is, typename F>
            constexpr void for_each(std::tuple<Ts...> const& t, std::index_sequence<Is...> is, F&& f) {
                std::initializer_list<int> i{(f(std::get<Is>(t)), 0)... };
            }

            template<typename... Ts, size_t... Is, typename F>
            constexpr void for_each(std::tuple<Ts...> & t, std::index_sequence<Is...> is, F&& f) {
                std::initializer_list<int> i{(f(std::get<Is>(t)), 0)... };
            }
#else

            template<typename T, typename F>
            struct for_each;

            template<typename F>
            struct for_each<std::tuple<>, F> {
                static constexpr void apply(std::tuple<> const &t, F f) {}
                static constexpr void apply(std::tuple<> &t, F f) {}
            };

            template<typename T, typename... Ts, typename F>
            struct for_each<std::tuple<T, Ts...>, F>
            {
                static constexpr void apply(std::tuple<T, Ts...> const &t, F f) noexcept(noexcept(f(std::get<0>(t))) &&
                                                                                   std::is_nothrow_copy_assignable<F>::value)
                {
                    f(std::get<0>(t));
                    auto tt = tail(t);
                    detail::for_each<std::decay_t <decltype(tt)>, F>::apply(tt, f);
                }

                static constexpr void apply(std::tuple<T, Ts...> &t, F f) noexcept(noexcept(f(std::get<0>(t))) &&
                                                                                   std::is_nothrow_copy_assignable<F>::value)
                {
                    f(std::get<0>(t));
                    auto tt = tail(t);
                    detail::for_each<std::decay_t <decltype(tt)>, F>::apply(tt, f);
                }
            };

#endif


        }

        template<typename... Ts, typename F>
        constexpr void for_each(std::tuple<Ts...> const &t, F &&f)
        {
#if defined(__GNUC__) && (__GNUC___ >= 7)
            detail::for_each(t, std::make_index_sequence<std::tuple_size<std::tuple<Ts...>>::value>{}, std::forward<F>(f));
#else
            detail::for_each<std::decay_t <decltype(t)>, F>::apply(t, f);
#endif
        }
    }
}

#endif
