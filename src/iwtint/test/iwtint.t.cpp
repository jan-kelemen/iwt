#include <iwtint.hpp>

#include <catch2/catch_test_macros.hpp>

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

TEST_CASE("add overflow", "[iwtint]")
{
    check_add_overflow<char>();
    check_add_overflow<unsigned char>();
    check_add_overflow<signed char>();
    check_add_overflow<char8_t>();
    check_add_overflow<char16_t>();
    check_add_overflow<char32_t>();
    check_add_overflow<char32_t>();
    check_add_overflow<short>();
    check_add_overflow<unsigned short>();
    check_add_overflow<int>();
    check_add_overflow<unsigned int>();
    check_add_overflow<long>();
    check_add_overflow<unsigned long>();
    check_add_overflow<long long>();
    check_add_overflow<unsigned long long>();
}

TEST_CASE("sub overflow", "[iwtint]")
{
    check_sub_overflow<char>();
    check_sub_overflow<unsigned char>();
    check_sub_overflow<signed char>();
    check_sub_overflow<char8_t>();
    check_sub_overflow<char16_t>();
    check_sub_overflow<char32_t>();
    check_sub_overflow<char32_t>();
    check_sub_overflow<short>();
    check_sub_overflow<unsigned short>();
    check_sub_overflow<int>();
    check_sub_overflow<unsigned int>();
    check_sub_overflow<long>();
    check_sub_overflow<unsigned long>();
    check_sub_overflow<long long>();
    check_sub_overflow<unsigned long long>();
}

TEST_CASE("mul overflow", "[iwtint]")
{
    check_mul_overflow<char>();
    check_mul_overflow<unsigned char>();
    check_mul_overflow<signed char>();
    check_mul_overflow<char8_t>();
    check_mul_overflow<char16_t>();
    check_mul_overflow<char32_t>();
    check_mul_overflow<char32_t>();
    check_mul_overflow<short>();
    check_mul_overflow<unsigned short>();
    check_mul_overflow<int>();
    check_mul_overflow<unsigned int>();
    check_mul_overflow<long>();
    check_mul_overflow<unsigned long>();
    check_mul_overflow<long long>();
    check_mul_overflow<unsigned long long>();
}

TEST_CASE("div by zero", "[iwtint]")
{
    check_div_by_zero<char>();
    check_div_by_zero<unsigned char>();
    check_div_by_zero<signed char>();
    check_div_by_zero<char8_t>();
    check_div_by_zero<char16_t>();
    check_div_by_zero<char32_t>();
    check_div_by_zero<char32_t>();
    check_div_by_zero<short>();
    check_div_by_zero<unsigned short>();
    check_div_by_zero<int>();
    check_div_by_zero<unsigned int>();
    check_div_by_zero<long>();
    check_div_by_zero<unsigned long>();
    check_div_by_zero<long long>();
    check_div_by_zero<unsigned long long>();
}
