#include "matrix.hpp"
#include <iostream>

namespace math
{
    real &Matrix::operator()(int row, int col)
    {
        if (row >= this->m_rows || col >= this->m_cols)
        {
            std::cerr << "Error: index out of range" << std::endl;
        }

        int pos(0);
        pos = m_cols * row + col;

        return this->m_matrix.at(pos);
    }

    const real &Matrix::operator()(int row, int col) const
    {
        int pos = m_cols * row + col;
        return this->m_matrix.at(pos);
    }

    void Matrix::print()
    {
        for (int i = 0; i < this->m_rows; ++i)
        {
            for (int j = 0; j < this->m_cols; ++j)
            {
                std::cout << this->m_matrix.at(i * this->m_cols + j) << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix &Matrix::operator+=(const Matrix &rhs)
    {
        if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
            throw std::invalid_argument("matrices have different dimensions");

        for (size_t i = 0; i < m_matrix.size(); ++i)
            m_matrix[i] += rhs.m_matrix[i];

        return *this;
    }

    Matrix operator+(Matrix lhs, const Matrix &rhs)
    {
        lhs += rhs;
        return lhs;
    }

    Matrix &Matrix::operator-=(const Matrix &rhs)
    {
        if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
            throw std::invalid_argument("matrices have different dimensions");

        for (int i = 0; i < m_matrix.size(); ++i)
        {
            m_matrix.at(i) -= rhs.m_matrix.at(i);
        }
        return *this;
    }

    Matrix operator-(Matrix lhs, const Matrix &rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    Matrix &Matrix::operator*=(const Matrix &rhs)
    {
        if (m_cols != rhs.m_rows)
            throw std::invalid_argument("matrices have different dimensions");

        Matrix result(m_rows, rhs.m_cols);

        for (std::size_t i = 0; i < m_rows; ++i)
            for (std::size_t j = 0; j < rhs.m_cols; ++j)
                for (std::size_t k = 0; k < m_cols; ++k)
                    result(i, j) += (*this)(i, k) * rhs(k, j);

        *this = std::move(result);
        return *this;
    }

    Matrix operator*(const Matrix &lhs, const Matrix &rhs)
    {
        Matrix result(lhs);
        result *= rhs;
        return result;
    }

    Matrix operator*(const Matrix &m, double scalar)
    {
        Matrix result(m.m_rows, m.m_cols);

        for (std::size_t i = 0; i < m.m_rows; ++i)
        {
            for (std::size_t j = 0; j < m.m_cols; ++j)
            {
                result(i, j) = m(i, j) * scalar;
            }
        }

        return result;
    }

    std::ostream &operator<<(std::ostream &os, const Matrix &m)
    {
        for (std::size_t i = 0; i < m.m_rows; ++i)
        {
            for (std::size_t j = 0; j < m.m_cols; ++j)
            {
                os << m(i, j);
                if (j + 1 < m.m_cols)
                    os << ' ';
            }
            os << '\n';
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Matrix &m)
    {
        std::size_t rows{}, cols{};

        if (!(is >> rows >> cols))
            return is;

        Matrix temp(rows, cols);

        for (std::size_t i = 0; i < rows; ++i)
            for (std::size_t j = 0; j < cols; ++j)
                if (!(is >> temp(i, j)))
                    return is;

        m = std::move(temp);

        return is;
    }
}
