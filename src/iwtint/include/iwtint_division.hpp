#ifndef IWTINT_DIVISION_INCLUDED
#define IWTINT_DIVISION_INCLUDED

#include <concepts>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool div(T const lhs, T const rhs, T& out) noexcept
    {
        if (rhs == T{}) [[unlikely]]
        {
            return false;
        }

        out = lhs / rhs;
        return true;
    }
} // namespace iwtint

#endif
