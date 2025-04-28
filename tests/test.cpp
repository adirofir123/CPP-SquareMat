// adirofir123@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SquareMat.h"

using namespace matrixlib;

TEST_CASE("Addition of 2 square matrices")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat expected(2);
    expected[0][0] = 6;
    expected[0][1] = 8;
    expected[1][0] = 10;
    expected[1][1] = 12;

    SquareMat result = m1 + m2;

    CHECK(result.getSize() == 2);
    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Subtraction of 2 square matrices")
{
    SquareMat m1(2);
    m1[0][0] = 5;
    m1[0][1] = 7;
    m1[1][0] = 9;
    m1[1][1] = 11;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 3;
    m2[1][1] = 4;

    SquareMat expected(2);
    expected[0][0] = 4;
    expected[0][1] = 5;
    expected[1][0] = 6;
    expected[1][1] = 7;

    SquareMat result = m1 - m2;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Unary minus operator")
{
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = -2;
    m[1][0] = -3;
    m[1][1] = 4;

    SquareMat expected(2);
    expected[0][0] = -1;
    expected[0][1] = 2;
    expected[1][0] = 3;
    expected[1][1] = -4;

    SquareMat result = -m;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Matrix multiplication")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 2;
    m2[0][1] = 0;
    m2[1][0] = 1;
    m2[1][1] = 2;

    SquareMat expected(2);
    expected[0][0] = 4;
    expected[0][1] = 4;
    expected[1][0] = 10;
    expected[1][1] = 8;

    SquareMat result = m1 * m2;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Scalar multiplication")
{
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat expected(2);
    expected[0][0] = 2;
    expected[0][1] = 4;
    expected[1][0] = 6;
    expected[1][1] = 8;

    CHECK((m * 2)[0][0] == doctest::Approx(expected[0][0]));
    CHECK((2 * m)[1][1] == doctest::Approx(expected[1][1]));
}

TEST_CASE("Element-wise multiplication (%)")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat expected(2);
    expected[0][0] = 5;
    expected[0][1] = 12;
    expected[1][0] = 21;
    expected[1][1] = 32;

    SquareMat result = m1 % m2;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Modulo with scalar (%)")
{
    SquareMat m(2);
    m[0][0] = 5;
    m[0][1] = 8;
    m[1][0] = 9;
    m[1][1] = 4;

    SquareMat expected(2);
    expected[0][0] = 2;
    expected[0][1] = 2;
    expected[1][0] = 0;
    expected[1][1] = 1;

    SquareMat result = m % 3;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Division by scalar")
{
    SquareMat m(2);
    m[0][0] = 10;
    m[0][1] = 20;
    m[1][0] = 30;
    m[1][1] = 40;

    SquareMat expected(2);
    expected[0][0] = 5;
    expected[0][1] = 10;
    expected[1][0] = 15;
    expected[1][1] = 20;

    SquareMat result = m / 2;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Matrix power operator (^)")
{
    SquareMat m(2);
    m[0][0] = 2;
    m[0][1] = 0;
    m[1][0] = 0;
    m[1][1] = 2;

    SquareMat expected(2);
    expected[0][0] = 8;
    expected[0][1] = 0;
    expected[1][0] = 0;
    expected[1][1] = 8;

    SquareMat result = m ^ 3;

    for (size_t i = 0; i < result.getSize(); ++i)
        for (size_t j = 0; j < result.getSize(); ++j)
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Pre and post increment/decrement")
{
    SquareMat m(2);
    m[0][0] = 0;
    m[0][1] = 1;
    m[1][0] = 2;
    m[1][1] = 3;

    SquareMat expectedPostInc(2);
    expectedPostInc[0][0] = 0;
    expectedPostInc[0][1] = 1;
    expectedPostInc[1][0] = 2;
    expectedPostInc[1][1] = 3;

    SquareMat expectedAfterPost(2);
    expectedAfterPost[0][0] = 1;
    expectedAfterPost[0][1] = 2;
    expectedAfterPost[1][0] = 3;
    expectedAfterPost[1][1] = 4;

    SquareMat post = m++;
    CHECK(post[0][0] == doctest::Approx(expectedPostInc[0][0]));
    CHECK(m[1][1] == doctest::Approx(expectedAfterPost[1][1]));

    SquareMat post2 = m--;
    CHECK(post2[0][1] == doctest::Approx(expectedAfterPost[0][1]));
    CHECK(m[1][0] == doctest::Approx(expectedPostInc[1][0]));

    ++m;
    CHECK(m[0][0] == doctest::Approx(1));

    --m;
    CHECK(m[0][0] == doctest::Approx(0));
}

TEST_CASE("Transpose operator (~)")
{
    SquareMat m(3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    m[2][0] = 7;
    m[2][1] = 8;
    m[2][2] = 9;

    SquareMat expected(3);
    expected[0][0] = 1;
    expected[0][1] = 4;
    expected[0][2] = 7;
    expected[1][0] = 2;
    expected[1][1] = 5;
    expected[1][2] = 8;
    expected[2][0] = 3;
    expected[2][1] = 6;
    expected[2][2] = 9;

    SquareMat t = ~m;

    for (size_t i = 0; i < t.getSize(); ++i)
        for (size_t j = 0; j < t.getSize(); ++j)
            CHECK(t[i][j] == doctest::Approx(expected[i][j]));
}

TEST_CASE("Equality and comparison operators")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 2;
    m2[0][1] = 3;
    m2[1][0] = 1;
    m2[1][1] = 4;

    SquareMat m3(2);
    m3[0][0] = 0;
    m3[0][1] = 0;
    m3[1][0] = 0;
    m3[1][1] = 0;

    CHECK(m1 == m2); // both sum to 10
    CHECK(m1 != m3);
    CHECK(m3 < m1);
    CHECK(m1 >= m3);
    CHECK(m1 <= m2);
    CHECK(!(m1 > m2)); // equal, not greater
}

TEST_CASE("Determinant operator (!)")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    CHECK((!m1) == doctest::Approx(-2));

    SquareMat m2(3);
    m2[0][0] = 6;
    m2[0][1] = 1;
    m2[0][2] = 1;
    m2[1][0] = 4;
    m2[1][1] = -2;
    m2[1][2] = 5;
    m2[2][0] = 2;
    m2[2][1] = 8;
    m2[2][2] = 7;

    CHECK((!m2) == doctest::Approx(-306));
}

TEST_CASE("Compound assignment operators")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 1;
    m2[1][0] = 1;
    m2[1][1] = 1;

    m1 += m2;
    CHECK(m1[0][0] == doctest::Approx(2));
    CHECK(m1[1][1] == doctest::Approx(5));

    m1 *= 2;
    CHECK(m1[0][0] == doctest::Approx(4));
    CHECK(m1[1][1] == doctest::Approx(10));

    m1 %= 3;
    CHECK(m1[0][0] == doctest::Approx(1));
    CHECK(m1[1][1] == doctest::Approx(1));
}
