#include <iwtint.hpp>

#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include <limits>
#include <type_traits> // IWYU pragma: keep

template<typename T>
void check_add_overflow()
{
    T out; // NOLINT

    static constexpr T v1{1};
    static constexpr T v2{std::numeric_limits<T>::max()};
    CHECK_FALSE(iwtint::add(v1, v2, out));

    if constexpr (std::is_signed_v<T>)
    {
        static constexpr T v3{std::numeric_limits<T>::min()};
        static constexpr T v4{-1};
        CHECK_FALSE(iwtint::add(v3, v4, out));
    }

    static constexpr T v5{1};
    static constexpr T v6{2};
    static constexpr T r1{3};
    CHECK(iwtint::add(v5, v6, out));
    CHECK(out == r1);
}

TEST_CASE("add overflow", "[iwtint]")
{
    check_add_overflow<char>();
    check_add_overflow<unsigned char>();
    check_add_overflow<signed char>();
    check_add_overflow<char8_t>();
    check_add_overflow<char16_t>();
    check_add_overflow<char32_t>();
    check_add_overflow<wchar_t>();
    check_add_overflow<short>();
    check_add_overflow<unsigned short>();
    check_add_overflow<int>();
    check_add_overflow<unsigned int>();
    check_add_overflow<long>();
    check_add_overflow<unsigned long>();
    check_add_overflow<long long>();
    check_add_overflow<unsigned long long>();
}

template<typename T>
void check_sub_overflow()
{
    T out; // NOLINT

    static constexpr T v1{std::numeric_limits<T>::min()};
    static constexpr T v2{1};
    CHECK_FALSE(iwtint::sub(v1, v2, out));

    if constexpr (std::is_signed_v<T>)
    {
        static constexpr T v3{std::numeric_limits<T>::max()};
        static constexpr T v4{std::numeric_limits<T>::min()};
        CHECK_FALSE(iwtint::sub(v3, v4, out));
    }
    else
    {
        static constexpr T v3{0};
        static constexpr T v4{1};
        CHECK_FALSE(iwtint::sub(v3, v4, out));
    }

    static constexpr T v5{7};
    static constexpr T v6{2};
    static constexpr T r1{5};
    CHECK(iwtint::sub(v5, v6, out));
    CHECK(out == r1);
}

TEST_CASE("sub overflow", "[iwtint]")
{
    check_sub_overflow<char>();
    check_sub_overflow<unsigned char>();
    check_sub_overflow<signed char>();
    check_sub_overflow<char8_t>();
    check_sub_overflow<char16_t>();
    check_sub_overflow<char32_t>();
    check_sub_overflow<wchar_t>();
    check_sub_overflow<short>();
    check_sub_overflow<unsigned short>();
    check_sub_overflow<int>();
    check_sub_overflow<unsigned int>();
    check_sub_overflow<long>();
    check_sub_overflow<unsigned long>();
    check_sub_overflow<long long>();
    check_sub_overflow<unsigned long long>();
}

template<typename T>
void check_mul_overflow()
{
    T out; // NOLINT

    static constexpr T v1{std::numeric_limits<T>::max()};
    static constexpr T v2{2};
    CHECK_FALSE(iwtint::mul(v1, v2, out));

    if constexpr (std::is_signed_v<T>)
    {
        static constexpr T v3{std::numeric_limits<T>::min()};
        static constexpr T v4{2};
        CHECK_FALSE(iwtint::mul(v3, v4, out));
    }

    static constexpr T v5{7};
    static constexpr T v6{2};
    static constexpr T r1{14};
    CHECK(iwtint::mul(v5, v6, out));
    CHECK(out == r1);
}

TEST_CASE("mul overflow", "[iwtint]")
{
    check_mul_overflow<char>();
    check_mul_overflow<unsigned char>();
    check_mul_overflow<signed char>();
    check_mul_overflow<char8_t>();
    check_mul_overflow<char16_t>();
    check_mul_overflow<char32_t>();
    check_mul_overflow<wchar_t>();
    check_mul_overflow<short>();
    check_mul_overflow<unsigned short>();
    check_mul_overflow<int>();
    check_mul_overflow<unsigned int>();
    check_mul_overflow<long>();
    check_mul_overflow<unsigned long>();
    check_mul_overflow<long long>();
    check_mul_overflow<unsigned long long>();
}

template<typename T>
void check_div_by_zero()
{
    T out; // NOLINT

    static constexpr T v1{std::numeric_limits<T>::max()};
    static constexpr T v2{0};
    CHECK_FALSE(iwtint::div(v1, v2, out));

    static constexpr T v3{8};
    static constexpr T v4{4};
    static constexpr T r1{2};
    CHECK(iwtint::div(v3, v4, out));
    CHECK(out == r1);

    static constexpr T v5{8};
    static constexpr T v6{3};
    static constexpr T r2{2};
    CHECK(iwtint::div(v5, v6, out));
    CHECK(out == r2);
}

TEST_CASE("div by zero", "[iwtint]")
{
    check_div_by_zero<char>();
    check_div_by_zero<unsigned char>();
    check_div_by_zero<signed char>();
    check_div_by_zero<char8_t>();
    check_div_by_zero<char16_t>();
    check_div_by_zero<char32_t>();
    check_div_by_zero<wchar_t>();
    check_div_by_zero<short>();
    check_div_by_zero<unsigned short>();
    check_div_by_zero<int>();
    check_div_by_zero<unsigned int>();
    check_div_by_zero<long>();
    check_div_by_zero<unsigned long>();
    check_div_by_zero<long long>();
    check_div_by_zero<unsigned long long>();
}

template<typename T>
void check_narrow_to_8_16_32_bits()
{
    static_assert(sizeof(T) >= 1 && sizeof(T) <= 4);
    static_assert(sizeof(intmax_t) > 4);

    T out; // NOLINT

    static constexpr intmax_t z{};
    CHECK(iwtint::narrow(z, out));
    CHECK(out == T{});

    static constexpr intmax_t upper{std::numeric_limits<T>::max()};
    CHECK(iwtint::narrow(upper, out));
    CHECK(out == std::numeric_limits<T>::max());

    static constexpr intmax_t above{upper + 1};
    CHECK_FALSE(iwtint::narrow(above, out));

    if constexpr (std::is_signed_v<T>)
    {
        static constexpr intmax_t lower{std::numeric_limits<T>::min()};
        CHECK(iwtint::narrow(lower, out));
        CHECK(out == std::numeric_limits<T>::min());

        static constexpr intmax_t below{lower - 1};
        CHECK_FALSE(iwtint::narrow(below, out));
    }
    else
    {
        static constexpr intmax_t neg{-1};
        CHECK_FALSE(iwtint::narrow(neg, out));
    }
}

template<typename T>
void check_narrow_to_64_bits()
{
    static_assert(sizeof(T) == 8);

    T out; // NOLINT

    static constexpr intmax_t z{};
    CHECK(iwtint::narrow(z, out));
    CHECK(out == T{});

    if constexpr (std::is_unsigned_v<T>)
    {
        static constexpr intmax_t neg{-1};
        CHECK_FALSE(iwtint::narrow(neg, out));

        static constexpr uintmax_t upper{std::numeric_limits<T>::max()};
        CHECK(iwtint::narrow(upper, out));
        CHECK(out == std::numeric_limits<T>::max());
    }
    else
    {
        static constexpr intmax_t upper{std::numeric_limits<T>::max()};
        CHECK(iwtint::narrow(upper, out));
        CHECK(out == std::numeric_limits<T>::max());

        static constexpr uintmax_t above{std::numeric_limits<uintmax_t>::max()};
        CHECK_FALSE(iwtint::narrow(above, out));
    }
}

template<typename T>
void check_char_type_as_source()
{
    intmax_t out; // NOLINT

    static constexpr T z{};
    CHECK(iwtint::narrow(z, out));
    CHECK(out == intmax_t{});

    static constexpr T v{3};
    static constexpr intmax_t r{3};
    CHECK(iwtint::narrow(v, out));
    CHECK(out == r);

    if constexpr (std::is_signed_v<T>)
    {
        static constexpr T neg{-1};
        uintmax_t uout; // NOLINT
        CHECK_FALSE(iwtint::narrow(neg, uout));
    }

    static constexpr T upper{std::numeric_limits<T>::max()};
    CHECK(iwtint::narrow(upper, out));

    static constexpr T lower{std::numeric_limits<T>::min()};
    CHECK(iwtint::narrow(lower, out));
}

template<typename Source, typename Target>
void check_char_type_as_source_and_target()
{
    Target out; // NOLINT

    static constexpr Source source_z{};
    static constexpr Target target_z{};

    CHECK(iwtint::narrow(source_z, out));
    CHECK(out == target_z);

    if constexpr (std::is_signed_v<Source> && std::is_signed_v<Target>)
    {
        static constexpr Source max{std::numeric_limits<Source>::max()};
        if constexpr (sizeof(Source) > sizeof(Target))
        {
            CHECK_FALSE(iwtint::narrow(max, out));
        }
        else
        {
            CHECK(iwtint::narrow(max, out));
        }
    }
    else if constexpr (std::is_signed_v<Source> && std::is_unsigned_v<Target>)
    {
        static constexpr Source neg{-1};
        CHECK_FALSE(iwtint::narrow(neg, out));
    }
    else if constexpr (std::is_unsigned_v<Source> && std::is_signed_v<Target>)
    {
        static constexpr Source max{std::numeric_limits<Source>::max()};
        if constexpr (sizeof(Source) >= sizeof(Target))
        {
            CHECK_FALSE(iwtint::narrow(max, out));
        }
        else
        {
            CHECK(iwtint::narrow(max, out));
        }
    }
    else
    {
        static_assert(std::is_unsigned_v<Source> && std::is_unsigned_v<Target>);

        static constexpr Source max{std::numeric_limits<Source>::max()};
        if constexpr (sizeof(Source) > sizeof(Target))
        {
            CHECK_FALSE(iwtint::narrow(max, out));
        }
        else
        {
            CHECK(iwtint::narrow(max, out));
        }
    }
}

TEST_CASE("narrow", "[iwtint]")
{
    check_narrow_to_8_16_32_bits<char>();
    check_narrow_to_8_16_32_bits<unsigned char>();
    check_narrow_to_8_16_32_bits<signed char>();
    check_narrow_to_8_16_32_bits<char8_t>();
    check_narrow_to_8_16_32_bits<char16_t>();
    check_narrow_to_8_16_32_bits<char32_t>();
    check_narrow_to_8_16_32_bits<wchar_t>();
    check_narrow_to_8_16_32_bits<short>();
    check_narrow_to_8_16_32_bits<unsigned short>();
    check_narrow_to_8_16_32_bits<int>();
    check_narrow_to_8_16_32_bits<unsigned int>();
#ifdef IWTINT_IS_MSVC
    check_narrow_to_8_16_32_bits<long>();
    check_narrow_to_8_16_32_bits<unsigned long>();
#else
    check_narrow_to_64_bits<long>();
    check_narrow_to_64_bits<unsigned long>();
#endif
    check_narrow_to_64_bits<long long>();
    check_narrow_to_64_bits<unsigned long long>();
}

TEST_CASE("narrow with char types")
{
    check_char_type_as_source<char>();
    check_char_type_as_source<char8_t>();
    check_char_type_as_source<char16_t>();
    check_char_type_as_source<char32_t>();
    check_char_type_as_source<wchar_t>();

    check_char_type_as_source_and_target<char, char8_t>();
    check_char_type_as_source_and_target<char, char16_t>();
    check_char_type_as_source_and_target<char, char32_t>();
    check_char_type_as_source_and_target<char, wchar_t>();

    check_char_type_as_source_and_target<char8_t, wchar_t>();
    check_char_type_as_source_and_target<char16_t, char32_t>();
    check_char_type_as_source_and_target<char32_t, char16_t>();
    check_char_type_as_source_and_target<wchar_t, char8_t>();
}
