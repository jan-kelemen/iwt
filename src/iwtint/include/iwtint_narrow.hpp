#ifndef IWTINT_NARROW_INCLUDED
#define IWTINT_NARROW_INCLUDED

#include <iwtint_config.hpp>

#include <climits>
#include <concepts>
#include <utility>

namespace iwtint
{
    template<typename T>
    concept is_nonstandard_integral_char_type =
        is_any_of_v<T, char, char8_t, char16_t, char32_t, wchar_t>;

    template<typename T>
    struct [[nodiscard]] narrow_traits;

    template<>
    struct [[nodiscard]] narrow_traits<char> final
    {
#if (CHAR_MIN == 0)
        using primitive = unsigned char;
#else
        using primitive = signed char;
#endif
    };

    template<>
    struct [[nodiscard]] narrow_traits<char8_t> final
    {
        using primitive = unsigned char;
    };

    template<>
    struct [[nodiscard]] narrow_traits<char16_t> final
    {
        using primitive = unsigned short;
    };

    template<>
    struct [[nodiscard]] narrow_traits<wchar_t> final
    {
#ifdef IWTINT_IS_MSVC
        using primitive = unsigned short;
#else
        using primitive = unsigned int;
#endif
    };

    template<>
    struct [[nodiscard]] narrow_traits<char32_t> final
    {
        using primitive = unsigned int;
    };

    template<typename T, typename R>
    struct [[nodiscard]] narrow_op final
    {
        [[nodiscard]] static bool result(T value, R& out) noexcept
        {
            if (std::in_range<R>(value)) [[likely]]
            {
                out = static_cast<R>(value);
                return true;
            }

            return false;
        }

        [[nodiscard]] static bool result(T const value, R& out) noexcept
        requires(is_nonstandard_integral_char_type<R>)
        {
            using primitive_r = narrow_traits<std::decay_t<R>>::primitive;
            static_assert(sizeof(primitive_r) == sizeof(R));

            primitive_r temp; // NOLINT
            if (narrow_op<T, primitive_r>::result(value, temp)) [[likely]]
            {
                out = static_cast<R>(temp);
                return true;
            }
            return false;
        }

        [[nodiscard]] static bool result(T const value, R& out) noexcept
        requires(is_nonstandard_integral_char_type<T>)
        {
            using primitive_t = narrow_traits<std::decay_t<T>>::primitive;
            static_assert(sizeof(primitive_t) == sizeof(T));

            return narrow_op<primitive_t, R>::result(
                static_cast<primitive_t>(value),
                out);
        }

        [[nodiscard]] static bool result(T const value, R& out) noexcept
        requires(is_nonstandard_integral_char_type<T> &&
            is_nonstandard_integral_char_type<R>)
        {
            using primitive_t = narrow_traits<std::decay_t<T>>::primitive;
            static_assert(sizeof(primitive_t) == sizeof(T));
            using primitive_r = narrow_traits<std::decay_t<R>>::primitive;
            static_assert(sizeof(primitive_r) == sizeof(R));

            primitive_r temp; // NOLINT
            if (narrow_op<primitive_t, primitive_r>::result(
                    static_cast<primitive_t>(value),
                    temp)) [[likely]]
            {
                out = static_cast<R>(temp);
                return true;
            }

            return false;
        }
    };

    template<typename T, typename R>
    [[nodiscard]] bool narrow(T const value, R& out) noexcept
    {
        return narrow_op<T, R>::result(value, out);
    }
} // namespace iwtint

#endif
