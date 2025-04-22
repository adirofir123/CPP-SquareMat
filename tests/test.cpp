// adirofir123@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SquareMat.h"

using namespace matrixlib;

TEST_CASE("Addition of 2 square matrices")
{
    SquareMat m1({{1, 2},
                  {3, 4}});

    SquareMat m2({{5, 6},
                  {7, 8}});

    SquareMat expected({{6, 8},
                        {10, 12}});

    SquareMat result = m1 + m2;

    CHECK(result.getSize() == 2);

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Subtraction of 2 square matrices")
{
    SquareMat m1({{5, 7},
                  {9, 11}});

    SquareMat m2({{1, 2},
                  {3, 4}});

    SquareMat expected({{4, 5},
                        {6, 7}});

    SquareMat result = m1 - m2;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Unary minus operator")
{
    SquareMat m({{1, -2},
                 {-3, 4}});

    SquareMat expected({{-1, 2},
                        {3, -4}});

    SquareMat result = -m;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Matrix multiplication")
{
    SquareMat m1({{1, 2},
                  {3, 4}});

    SquareMat m2({{2, 0},
                  {1, 2}});

    // Expected: m1 * m2
    // [1*2 + 2*1, 1*0 + 2*2] = [4, 4]
    // [3*2 + 4*1, 3*0 + 4*2] = [10, 8]
    SquareMat expected({{4, 4},
                        {10, 8}});

    SquareMat result = m1 * m2;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Scalar multiplication")
{
    SquareMat m({{1, 2},
                 {3, 4}});

    SquareMat expected({{2, 4},
                        {6, 8}});

    CHECK((m * 2)[0][0] == doctest::Approx(expected[0][0]));
    CHECK((2 * m)[1][1] == doctest::Approx(expected[1][1]));
}

TEST_CASE("Element-wise multiplication (%)")
{
    SquareMat m1({{1, 2},
                  {3, 4}});

    SquareMat m2({{5, 6},
                  {7, 8}});

    SquareMat expected({{5, 12},
                        {21, 32}});

    SquareMat result = m1 % m2;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Modulo with scalar (%)")
{
    SquareMat m({{5, 8},
                 {9, 4}});

    SquareMat expected({{2, 2},
                        {0, 1}});

    SquareMat result = m % 3;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Division by scalar")
{
    SquareMat m({{10, 20},
                 {30, 40}});

    SquareMat expected({{5, 10},
                        {15, 20}});

    SquareMat result = m / 2;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Matrix power operator (^)")
{
    SquareMat m({{2, 0},
                 {0, 2}});

    SquareMat expected({{8, 0},
                        {0, 8}}); // since 2^3 = 8

    SquareMat result = m ^ 3;

    for (size_t i = 0; i < result.getSize(); ++i)
    {
        for (size_t j = 0; j < result.getSize(); ++j)
        {
            CHECK(result[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Pre and post increment/decrement")
{
    SquareMat m({{0, 1},
                 {2, 3}});

    SquareMat expectedPostInc({{0, 1},
                               {2, 3}});

    SquareMat expectedAfterPost({{1, 2},
                                 {3, 4}});

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
    SquareMat m({{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}});

    SquareMat expected({{1, 4, 7},
                        {2, 5, 8},
                        {3, 6, 9}});

    SquareMat t = ~m;

    for (size_t i = 0; i < t.getSize(); ++i)
    {
        for (size_t j = 0; j < t.getSize(); ++j)
        {
            CHECK(t[i][j] == doctest::Approx(expected[i][j]));
        }
    }
}

TEST_CASE("Equality and comparison operators") {
    SquareMat m1({
        {1, 2},
        {3, 4}
    });

    SquareMat m2({
        {2, 3},
        {1, 4}
    });

    SquareMat m3({
        {0, 0},
        {0, 0}
    });

    CHECK(m1 == m2);  // both sum to 10
    CHECK(m1 != m3);
    CHECK(m3 < m1);
    CHECK(m1 >= m3);
    CHECK(m1 <= m2);
    CHECK(!(m1 > m2)); // equal, not greater
}

TEST_CASE("Determinant operator (!)") {
    SquareMat m1({
        {1, 2},
        {3, 4}
    }); // det = -2

    CHECK((!m1) == doctest::Approx(-2));

    SquareMat m2({
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    }); // det = -306

    CHECK((!m2) == doctest::Approx(-306));
}

TEST_CASE("Compound assignment operators") {
    SquareMat m1({
        {1, 2},
        {3, 4}
    });

    SquareMat m2({
        {1, 1},
        {1, 1}
    });

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
