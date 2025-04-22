// adirofir123@gmail.com

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

namespace matrixlib
{

    class SquareMat
    {
    private:
        size_t size;
        std::vector<std::vector<double>> mat;
        double getSum() const;
        SquareMat getMinor(size_t row, size_t col) const;

    public:
        SquareMat(size_t n);                                       // Create zero matrix
        SquareMat(const std::vector<std::vector<double>> &values); // From values

        size_t getSize() const;
        void print() const;

        SquareMat operator+(const SquareMat &other) const;
        SquareMat operator-(const SquareMat &other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat &other) const;
        SquareMat operator*(double scalar) const;
        SquareMat operator%(const SquareMat &other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator^(int power) const;

        // ++ and -- operators
        SquareMat &operator++();   // pre-increment
        SquareMat &operator--();   // pre-decrement
        SquareMat operator++(int); // post-increment
        SquareMat operator--(int); // post-decrement

        SquareMat operator~() const;

        bool operator==(const SquareMat &other) const;
        bool operator!=(const SquareMat &other) const;
        bool operator<(const SquareMat &other) const;
        bool operator<=(const SquareMat &other) const;
        bool operator>(const SquareMat &other) const;
        bool operator>=(const SquareMat &other) const;

        double operator!() const;

        SquareMat &operator+=(const SquareMat &other);
        SquareMat &operator-=(const SquareMat &other);
        SquareMat &operator*=(const SquareMat &other);
        SquareMat &operator*=(double scalar);
        SquareMat &operator/=(double scalar);
        SquareMat &operator%=(const SquareMat &other);
        SquareMat &operator%=(int scalar);

        std::vector<double> &operator[](size_t row);             // write access
        const std::vector<double> &operator[](size_t row) const; // read access
    };

    SquareMat operator*(double scalar, const SquareMat &mat); // scalar * matrix

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat);


}
