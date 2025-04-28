// adirofir123@gmail.com

#include "SquareMat.h"
#include <iomanip> 

namespace matrixlib
{
    // Constructor
    SquareMat::SquareMat(size_t n) : size(n)
    {
        mat = new double *[size];
        for (size_t i = 0; i < size; ++i)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; ++j)
            {
                mat[i][j] = 0.0;
            }
        }
    }

    // Copy Constructor
    SquareMat::SquareMat(const SquareMat &other) : size(other.size)
    {
        mat = new double *[size];
        for (size_t i = 0; i < size; ++i)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; ++j)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    // Assignment Operator
    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (this == &other)
        {
            return *this; // Handle self-assignment
        }

        // Free current memory
        for (size_t i = 0; i < size; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;

        // Copy new matrix
        size = other.size;
        mat = new double *[size];
        for (size_t i = 0; i < size; ++i)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; ++j)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
        return *this;
    }

    // Destructor
    SquareMat::~SquareMat()
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Other functions

    size_t SquareMat::getSize() const
    {
        return size;
    }

    void SquareMat::print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    double *SquareMat::operator[](size_t row)
    {
        if (row >= size)
            throw std::out_of_range("Row index out of bounds");
        return mat[row];
    }

    const double *SquareMat::operator[](size_t row) const
    {
        if (row >= size)
            throw std::out_of_range("Row index out of bounds");
        return mat[row];
    }

    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match for addition.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match for subtraction.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
        return result;
    }

    SquareMat SquareMat::operator-() const
    {
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = -mat[i][j];
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match for multiplication.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                for (size_t k = 0; k < size; ++k)
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
        return result;
    }

    SquareMat SquareMat::operator*(double scalar) const
    {
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = mat[i][j] * scalar;
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = mat[i][j] * other.mat[i][j];
        return result;
    }

    SquareMat SquareMat::operator%(int scalar) const
    {
        if (scalar == 0)
            throw std::invalid_argument("Modulo by zero is undefined.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = static_cast<int>(mat[i][j]) % scalar;
        return result;
    }

    SquareMat SquareMat::operator/(double scalar) const
    {
        if (scalar == 0.0)
            throw std::invalid_argument("Division by zero is undefined.");
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = mat[i][j] / scalar;
        return result;
    }

    SquareMat SquareMat::operator^(int power) const
    {
        if (power < 0)
            throw std::invalid_argument("Negative powers not supported.");

        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[i][j] = (i == j) ? 1.0 : 0.0; // Identity matrix

        if (power == 0)
            return result;

        SquareMat base(*this);
        for (int i = 0; i < power; ++i)
        {
            result = result * base;
        }

        return result;
    }

    // Compound assignment
    SquareMat &SquareMat::operator+=(const SquareMat &other) { return *this = *this + other; }
    SquareMat &SquareMat::operator-=(const SquareMat &other) { return *this = *this - other; }
    SquareMat &SquareMat::operator*=(const SquareMat &other) { return *this = *this * other; }
    SquareMat &SquareMat::operator*=(double scalar) { return *this = *this * scalar; }
    SquareMat &SquareMat::operator/=(double scalar) { return *this = *this / scalar; }
    SquareMat &SquareMat::operator%=(const SquareMat &other) { return *this = *this % other; }
    SquareMat &SquareMat::operator%=(int scalar) { return *this = *this % scalar; }

    // Increments and Decrements
    SquareMat &SquareMat::operator++()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                mat[i][j] += 1.0;
        return *this;
    }

    SquareMat &SquareMat::operator--()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                mat[i][j] -= 1.0;
        return *this;
    }

    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    // Other operators
    SquareMat SquareMat::operator~() const
    {
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.mat[j][i] = mat[i][j];
        return result;
    }

    bool SquareMat::operator==(const SquareMat &other) const { return getSum() == other.getSum(); }
    bool SquareMat::operator!=(const SquareMat &other) const { return !(*this == other); }
    bool SquareMat::operator<(const SquareMat &other) const { return getSum() < other.getSum(); }
    bool SquareMat::operator<=(const SquareMat &other) const { return getSum() <= other.getSum(); }
    bool SquareMat::operator>(const SquareMat &other) const { return getSum() > other.getSum(); }
    bool SquareMat::operator>=(const SquareMat &other) const { return getSum() >= other.getSum(); }

    double SquareMat::operator!() const
    {
        if (size == 0)
            throw std::invalid_argument("Determinant undefined for 0x0 matrix.");
        if (size == 1)
            return mat[0][0];
        if (size == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        double det = 0;
        for (size_t col = 0; col < size; ++col)
        {
            double sign = (col % 2 == 0) ? 1 : -1;
            det += sign * mat[0][col] * getMinor(0, col).operator!();
        }
        return det;
    }

    double SquareMat::getSum() const
    {
        double sum = 0;
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                sum += mat[i][j];
        return sum;
    }

    SquareMat SquareMat::getMinor(size_t row, size_t col) const
    {
        SquareMat minorMat(size - 1);

        size_t minor_i = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (i == row)
                continue;

            size_t minor_j = 0;
            for (size_t j = 0; j < size; ++j)
            {
                if (j == col)
                    continue;
                minorMat.mat[minor_i][minor_j] = mat[i][j];
                ++minor_j;
            }
            ++minor_i;
        }
        return minorMat;
    }

    std::ostream &operator<<(std::ostream &os, const SquareMat &mat)
    {
        for (size_t i = 0; i < mat.getSize(); ++i)
        {
            for (size_t j = 0; j < mat.getSize(); ++j)
            {
                os << mat[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

}
