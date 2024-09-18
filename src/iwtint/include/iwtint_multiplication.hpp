#ifndef IWTINT_MULTIPLICATION_INCLUDED
#define IWTINT_MULTIPLICATION_INCLUDED

#include <iwtint_config.hpp>

#include <concepts>
#include <type_traits>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool mul(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    mul(char const lhs, char const rhs, char& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        if constexpr (std::is_signed_v<char>)
        {
            signed short temp; // NOLINT
            if (_mul_full_overflow_i8(lhs, rhs, &temp) != 0) [[unlikely]]
            {
                return false;
            }
            out = static_cast<char>(temp);
            return true;
        }
        else
        {
            unsigned short temp; // NOLINT
            if (_mul_full_overflow_u8(lhs, rhs, &temp) != 0) [[unlikely]]
            {
                return false;
            }
            out = static_cast<char>(temp);
            return true;
        }
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        unsigned short temp; // NOLINT
        if (_mul_full_overflow_u8(lhs, rhs, &temp) != 0) [[unlikely]]
        {
            return false;
        }
        out = static_cast<unsigned char>(temp);
        return true;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        signed short temp; // NOLINT
        if (_mul_full_overflow_i8(lhs, rhs, &temp) != 0) [[unlikely]]
        {
            return false;
        }
        out = static_cast<signed char>(temp);
        return true;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        unsigned short temp; // NOLINT
        if (_mul_full_overflow_u8(lhs, rhs, &temp) != 0 || temp & 0xFF'00)
            [[unlikely]]
        {
            return false;
        }
        out = static_cast<char8_t>(temp);
        return true;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char16_t, unsigned short>);

        unsigned short upper; // NOLINT
        return _mul_full_overflow_u16(lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out),
                   &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char32_t, unsigned int>);

        unsigned int upper; // NOLINT
        return _mul_full_overflow_u32(lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out),
                   &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<wchar_t, unsigned short>);

        unsigned short upper; // NOLINT
        return _mul_full_overflow_u16(lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out),
                   &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(short const lhs, short const rhs, short& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _mul_overflow_i16(lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        unsigned short upper; // NOLINT
        return _mul_full_overflow_u16(lhs, rhs, &out, &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(int const lhs, int const rhs, int& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _mul_overflow_i32(lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        unsigned int upper; // NOLINT
        return _mul_full_overflow_u32(lhs, rhs, &out, &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(long const lhs, long const rhs, long& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<long, int>);

        return _mul_overflow_i32(lhs, rhs, reinterpret_cast<int*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<unsigned long, unsigned int>);

        unsigned int upper; // NOLINT
        return _mul_full_overflow_u32(lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out),
                   &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    mul(long long const lhs, long long const rhs, long long& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<long long, __int64>);
        return _mul_overflow_i64(lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool mul(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
#if __has_builtin(__builtin_mul_overflow)
        return !__builtin_mul_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(
            size_align_sign_matches_v<unsigned long long, unsigned __int64>);

        unsigned __int64 upper; // NOLINT
        return _mul_full_overflow_u64(lhs,
                   rhs,
                   reinterpret_cast<unsigned __int64*>(&out),
                   &upper) == 0 &&
            upper == 0;
#else
#error "Unsupported compiler"
#endif
    }
} // namespace iwtint
#endif
