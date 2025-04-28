// adirofir123@gmail.com
#pragma once
#include <iostream>
#include <stdexcept>

namespace matrixlib
{
    
    class SquareMat
    {
    private:
        size_t size;
        double **mat; // dynamic 2D array (pointer to pointer)

        double getSum() const;
        SquareMat getMinor(size_t row, size_t col) const;

    public:
        // Constructors and Destructor
        SquareMat(size_t n);                          // Create zero matrix
        SquareMat(const SquareMat &other);            // Copy constructor
        SquareMat &operator=(const SquareMat &other); // Assignment operator
        ~SquareMat();                                 // Destructor

        // Basic functions
        size_t getSize() const;
        void print() const;

        // Access operators
        double *operator[](size_t row);             // write access
        const double *operator[](size_t row) const; // read access

        // Arithmetic operators
        SquareMat operator+(const SquareMat &other) const;
        SquareMat operator-(const SquareMat &other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat &other) const;
        SquareMat operator*(double scalar) const;
        SquareMat operator%(const SquareMat &other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator^(int power) const;

        // Compound assignment operators
        SquareMat &operator+=(const SquareMat &other);
        SquareMat &operator-=(const SquareMat &other);
        SquareMat &operator*=(const SquareMat &other);
        SquareMat &operator*=(double scalar);
        SquareMat &operator/=(double scalar);
        SquareMat &operator%=(const SquareMat &other);
        SquareMat &operator%=(int scalar);

        // Increment and Decrement
        SquareMat &operator++();   // Pre-increment
        SquareMat &operator--();   // Pre-decrement
        SquareMat operator++(int); // Post-increment
        SquareMat operator--(int); // Post-decrement

        // Other operators
        SquareMat operator~() const; // Transpose
        bool operator==(const SquareMat &other) const;
        bool operator!=(const SquareMat &other) const;
        bool operator<(const SquareMat &other) const;
        bool operator<=(const SquareMat &other) const;
        bool operator>(const SquareMat &other) const;
        bool operator>=(const SquareMat &other) const;
        double operator!() const; // Determinant
    };

    // Non-member friend operators
    SquareMat operator*(double scalar, const SquareMat &mat); // scalar * matrix
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat);

}
