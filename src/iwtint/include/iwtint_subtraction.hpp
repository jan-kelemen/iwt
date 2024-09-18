#ifndef IWTINT_SUBTRACTION_INCLUDED
#define IWTINT_SUBTRACTION_INCLUDED

#include <iwtint_config.hpp>

#include <concepts>
#include <type_traits>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool sub(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    sub(char const lhs, char const rhs, char& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        if constexpr (std::is_signed_v<char>)
        {
            static_assert(size_align_sign_matches_v<char, signed char>);
            return _sub_overflow_i8(0,
                       lhs,
                       rhs,
                       reinterpret_cast<signed char*>(&out)) == 0;
        }
        else
        {
            static_assert(size_align_sign_matches_v<char, unsigned char>);
            return _subborrow_u8(0,
                       lhs,
                       rhs,
                       reinterpret_cast<unsigned char*>(&out)) == 0;
        }
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _subborrow_u8(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _sub_overflow_i8(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char8_t, unsigned char>);
        return _subborrow_u8(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned char*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char16_t, unsigned short>);
        return _subborrow_u16(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char32_t, unsigned int>);
        return _subborrow_u32(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<wchar_t, unsigned short>);
        return _subborrow_u16(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(short const lhs, short const rhs, short& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _sub_overflow_i16(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _subborrow_u16(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(int const lhs, int const rhs, int& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _sub_overflow_i32(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _subborrow_u32(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(long const lhs, long const rhs, long& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<long, int>);
        return _sub_overflow_i32(0, lhs, rhs, reinterpret_cast<int*>(&out)) ==
            0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<unsigned long, unsigned int>);
        return _subborrow_u32(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    sub(long long const lhs, long long const rhs, long long& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<long long, __int64>);
        return _sub_overflow_i64(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool sub(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
#if __has_builtin(__builtin_sub_overflow)
        return !__builtin_sub_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(
            size_align_sign_matches_v<unsigned long long, unsigned __int64>);
        return _subborrow_u64(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }
} // namespace iwtint
#endif
