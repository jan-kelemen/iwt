#ifndef IWTINT_ADDITION_INCLUDED
#define IWTINT_ADDITION_INCLUDED

#include <iwtint_config.hpp>

#include <concepts>
#include <type_traits>

namespace iwtint
{
    template<std::integral T>
    [[nodiscard]] bool add(T lhs, T rhs, T& out) noexcept;

    template<>
    [[nodiscard]] inline bool
    add(char const lhs, char const rhs, char& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        if constexpr (std::is_signed_v<char>)
        {
            static_assert(size_align_sign_matches_v<char, signed char>);
            return _add_overflow_i8(0,
                       lhs,
                       rhs,
                       reinterpret_cast<signed char*>(&out)) == 0;
        }
        else
        {
            static_assert(size_align_sign_matches_v<char, unsigned char>);
            return _addcarry_u8(0,
                       lhs,
                       rhs,
                       reinterpret_cast<unsigned char*>(&out)) == 0;
        }
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool add(unsigned char const lhs,
        unsigned char const rhs,
        unsigned char& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _addcarry_u8(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(signed char const lhs, signed char const rhs, signed char& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _add_overflow_i8(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(char8_t const lhs, char8_t const rhs, char8_t& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char8_t, unsigned char>);
        return _addcarry_u8(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned char*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(char16_t const lhs, char16_t const rhs, char16_t& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char16_t, unsigned short>);
        return _addcarry_u16(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(char32_t const lhs, char32_t const rhs, char32_t& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<char32_t, unsigned int>);
        return _addcarry_u32(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(wchar_t const lhs, wchar_t const rhs, wchar_t& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<wchar_t, unsigned short>);
        return _addcarry_u16(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned short*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(short const lhs, short const rhs, short& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _add_overflow_i16(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool add(unsigned short const lhs,
        unsigned short const rhs,
        unsigned short& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _addcarry_u16(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(int const lhs, int const rhs, int& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _add_overflow_i32(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool add(unsigned int const lhs,
        unsigned int const rhs,
        unsigned int& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _addcarry_u32(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(long const lhs, long const rhs, long& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<long, int>);
        return _add_overflow_i32(0, lhs, rhs, reinterpret_cast<int*>(&out)) ==
            0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool add(unsigned long const lhs,
        unsigned long const rhs,
        unsigned long& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        static_assert(size_align_sign_matches_v<unsigned long, unsigned int>);
        return _addcarry_u32(0,
                   lhs,
                   rhs,
                   reinterpret_cast<unsigned int*>(&out)) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool
    add(long long const lhs, long long const rhs, long long& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _add_overflow_i64(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }

    template<>
    [[nodiscard]] inline bool add(unsigned long long const lhs,
        unsigned long long const rhs,
        unsigned long long& out) noexcept
    {
#if __has_builtin(__builtin_add_overflow)
        return !__builtin_add_overflow(lhs, rhs, &out);
#elif defined(IWTINT_IS_MSVC)
        return _addcarry_u64(0, lhs, rhs, &out) == 0;
#else
#error "Unsupported compiler"
#endif
    }
} // namespace iwtint
#endif
