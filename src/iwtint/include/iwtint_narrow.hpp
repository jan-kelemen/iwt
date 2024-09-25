#ifndef IWTINT_NARROW_INCLUDED
#define IWTINT_NARROW_INCLUDED

#include <concepts>
#include <type_traits>

namespace iwtint
{
    template<std::integral T, std::integral R>
    [[nodiscard]] bool narrow(T const value, R& out) noexcept
    {
        // https://stackoverflow.com/q/52863643

        // NOLINTNEXTLINE(bugprone-signed-char-misuse)
        out = static_cast<R>(value);

        if (static_cast<T>(out) != value)
        {
            return false;
        }

        if (std::is_signed_v<T> != std::is_signed_v<R> &&
            ((value < T{}) != (out < R{})))
        {
            return false;
        }

        return true;
    }
} // namespace iwtint

#endif
