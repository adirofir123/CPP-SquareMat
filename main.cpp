// adirofir123@gmail.com
#include "SquareMat.h"
#include <iostream>

using namespace matrixlib;

int main()
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

    SquareMat sum = m1 + m2;
    SquareMat product = m1 * m2;

    std::cout << "Matrix 1:" << std::endl;
    m1.print();

    std::cout << "\nMatrix 2:" << std::endl;
    m2.print();

    std::cout << "\nSum:" << std::endl;
    sum.print();

    std::cout << "\nProduct:" << std::endl;
    product.print();

    return 0;
}
