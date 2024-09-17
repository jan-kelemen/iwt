#ifndef IWTINT_INCLUDED
#define IWTINT_INCLUDED

#include <concepts>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool add(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    add(char const lhs, char const rhs, char& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool add(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(short const lhs, short const rhs, short& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool add(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(int const lhs, int const rhs, int& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool add(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(long const lhs, long const rhs, long& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool add(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    add(long long const lhs, long long const rhs, long long& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool add(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
        return !__builtin_add_overflow(lhs, rhs, &out);
    }

    template<std::integral T>
    [[nodiscard]] bool sub(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    sub(char const lhs, char const rhs, char& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(short const lhs, short const rhs, short& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(int const lhs, int const rhs, int& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(long const lhs, long const rhs, long& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    sub(long long const lhs, long long const rhs, long long& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
        return !__builtin_sub_overflow(lhs, rhs, &out);
    }

    template<std::integral T>
    [[nodiscard]] bool mul(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    mul(char const lhs, char const rhs, char& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(short const lhs, short const rhs, short& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(int const lhs, int const rhs, int& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(long const lhs, long const rhs, long& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool
    mul(long long const lhs, long long const rhs, long long& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
        return !__builtin_mul_overflow(lhs, rhs, &out);
    }

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
