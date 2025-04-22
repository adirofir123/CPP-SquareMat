// adirofir123@gmail.com

#include "SquareMat.h"
using namespace matrixlib;

int main()
{
    SquareMat m1({{1, 2},
                  {3, 4}});

    SquareMat m2({{5, 6},
                  {7, 8}});

    SquareMat result = m1 + m2;
    result = result * 2;
    result = result % 3;
    SquareMat transposed = ~result;
    double det = !m1;

    std::cout << "Final Matrix:\n"
              << transposed;
    std::cout << "Determinant: " << det << std::endl;

    return 0;
}
