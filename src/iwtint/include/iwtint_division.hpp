#ifndef IWTINT_DIVISION_INCLUDED
#define IWTINT_DIVISION_INCLUDED

#include <concepts>
#include <limits>
#include <type_traits>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool div(T const lhs, T const rhs, T& out) noexcept
    {
        if constexpr (std::is_signed_v<T>)
        {
            if (rhs == T{} ||
                (lhs == std::numeric_limits<T>::min() && rhs == T{-1}))
                [[unlikely]]
            {
                return false;
            }
        }
        else
        {
            if (rhs == T{}) [[unlikely]]
            {
                return false;
            }
        }

        out = lhs / rhs;
        return true;
    }
} // namespace iwtint

#endif
