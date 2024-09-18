#ifndef IWTINT_CONFIG_INCLUDED
#define IWTINT_CONFIG_INCLUDED

#ifdef _MSC_VER
#define IWTINT_IS_MSVC
#endif

#ifndef __has_builtin
#define __has_builtin(__x) 0
#endif

#ifdef _MSC_VER
#include <intrin.h>
#include <softintrin.h>
#endif

#include <type_traits>

namespace iwtint
{
    template<typename T, typename U>
    constexpr bool size_align_sign_matches_v{(sizeof(T) == sizeof(U)) &&
        (alignof(T) == alignof(U)) &&
        (std::is_signed_v<T> == std::is_signed_v<T>) };

    template<typename T, typename... Candidates>
    constexpr bool is_any_of_v =
        std::disjunction_v<std::is_same<T, Candidates>...>;

} // namespace iwtint

#endif
