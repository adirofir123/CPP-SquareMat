// adirofir123@gmail.com

#include "SquareMat.h"

namespace matrixlib
{

    SquareMat::SquareMat(size_t n) : size(n), mat(n, std::vector<double>(n, 0)) {}

    SquareMat::SquareMat(const std::vector<std::vector<double>> &values)
    {
        size = values.size();
        for (const auto &row : values)
        {
            if (row.size() != size)
            {
                throw std::invalid_argument("Matrix must be square.");
            }
        }
        mat = values;
    }

    size_t SquareMat::getSize() const
    {
        return size;
    }

    void SquareMat::print() const
    {
        for (const auto &row : mat)
        {
            for (double val : row)
            {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
    std::vector<double> &SquareMat::operator[](size_t row)
    {
        if (row >= size)
            throw std::out_of_range("Row index out of bounds");
        return mat[row];
    }

    const std::vector<double> &SquareMat::operator[](size_t row) const
    {
        if (row >= size)
            throw std::out_of_range("Row index out of bounds");
        return mat[row];
    }

    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::invalid_argument("Matrix sizes do not match for addition.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return SquareMat(result);
    }

    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::invalid_argument("Matrix sizes do not match for subtraction.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return SquareMat(result);
    }

    SquareMat SquareMat::operator-() const
    {
        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = -mat[i][j];
            }
        }
        return SquareMat(result);
    }

    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::invalid_argument("Matrix sizes do not match for multiplication.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size, 0));

        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                for (size_t k = 0; k < size; ++k)
                {
                    result[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }

        return SquareMat(result);
    }

    SquareMat SquareMat::operator*(double scalar) const
    {
        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = mat[i][j] * scalar;
            }
        }
        return SquareMat(result);
    }

    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        return mat * scalar; // reuses the member function
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = mat[i][j] * other.mat[i][j];
            }
        }

        return SquareMat(result);
    }

    SquareMat SquareMat::operator%(int scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Modulo by zero is undefined.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = static_cast<int>(mat[i][j]) % scalar;
            }
        }
        return SquareMat(result);
    }

    SquareMat SquareMat::operator/(double scalar) const
    {
        if (scalar == 0.0)
        {
            throw std::invalid_argument("Division by zero is undefined.");
        }

        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                result[i][j] = mat[i][j] / scalar;
            }
        }
        return SquareMat(result);
    }

    SquareMat SquareMat::operator^(int power) const
    {
        if (power < 0)
        {
            throw std::invalid_argument("Negative powers not supported.");
        }

        // Identity matrix
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result[i][i] = 1;
        }

        if (power == 0)
            return result;

        SquareMat base(*this);
        for (int i = 0; i < power; ++i)
        {
            result = result * base;
        }

        return result;
    }

    // Pre-increment
    SquareMat &SquareMat::operator++()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                mat[i][j] += 1.0;
        return *this;
    }

    // Pre-decrement
    SquareMat &SquareMat::operator--()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                mat[i][j] -= 1.0;
        return *this;
    }

    // Post-increment
    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp = *this;
        ++(*this);
        return temp;
    }

    // Post-decrement
    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp = *this;
        --(*this);
        return temp;
    }

    SquareMat SquareMat::operator~() const
    {
        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[j][i] = mat[i][j];
        return SquareMat(result);
    }

    double SquareMat::getSum() const
    {
        double sum = 0;
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                sum += mat[i][j];
        return sum;
    }

    bool SquareMat::operator==(const SquareMat &other) const
    {
        return this->getSum() == other.getSum();
    }

    bool SquareMat::operator!=(const SquareMat &other) const
    {
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat &other) const
    {
        return this->getSum() < other.getSum();
    }

    bool SquareMat::operator<=(const SquareMat &other) const
    {
        return this->getSum() <= other.getSum();
    }

    bool SquareMat::operator>(const SquareMat &other) const
    {
        return this->getSum() > other.getSum();
    }

    bool SquareMat::operator>=(const SquareMat &other) const
    {
        return this->getSum() >= other.getSum();
    }


    double SquareMat::operator!() const {
        if (size == 0) return 1; // or throw if you prefer
    
        if (size == 1) return mat[0][0];
        if (size == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    
        double det = 0;
        for (size_t col = 0; col < size; ++col) {
            double sign = (col % 2 == 0) ? 1 : -1;
            det += sign * mat[0][col] * getMinor(0, col).operator!();
        }
        return det;
    }
    

    SquareMat SquareMat::getMinor(size_t row, size_t col) const {
        std::vector<std::vector<double>> minorMat;
        for (size_t i = 0; i < size; ++i) {
            if (i == row) continue;
            std::vector<double> newRow;
            for (size_t j = 0; j < size; ++j) {
                if (j == col) continue;
                newRow.push_back(mat[i][j]);
            }
            minorMat.push_back(newRow);
        }
        return SquareMat(minorMat);
    }
    
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        return *this = *this + other;
    }
    
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        return *this = *this - other;
    }
    
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        return *this = *this * other;
    }
    
    SquareMat& SquareMat::operator*=(double scalar) {
        return *this = *this * scalar;
    }
    
    SquareMat& SquareMat::operator/=(double scalar) {
        return *this = *this / scalar;
    }
    
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        return *this = *this % other;
    }
    
    SquareMat& SquareMat::operator%=(int scalar) {
        return *this = *this % scalar;
    }
    

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (size_t i = 0; i < mat.getSize(); ++i) {
            for (size_t j = 0; j < mat.getSize(); ++j) {
                os << mat[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }
    
}
