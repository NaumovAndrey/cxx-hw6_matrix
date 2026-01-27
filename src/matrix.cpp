#include "matrix.hpp"
#include <iostream>

using namespace math;

real& math::Matrix::operator()(int row, int col)
{
    if(row >= this->m_rows || col >= this->m_cols)
    {
        std::cerr << "Error: index out of range" << std::endl;
    }

    int pos(0);
    pos = m_cols * row + col;
    
    return this->m_matrix.at(pos);
}

const real& math::Matrix::operator()(int row, int col) const
{
    int pos = m_cols * row + col;
    return this->m_matrix.at(pos);
}

void Matrix::print()
{
    for(int i = 0; i < this->m_rows; ++i)
    {
        for(int j = 0; j < this->m_cols; ++j)
        {
            std::cout << this->m_matrix.at(i * this->m_cols + j) << " ";
        }
        std::cout << std::endl;
    }    
}

Matrix math::operator+(const Matrix& lhs, const Matrix& rhs)
{
    if((lhs.m_rows != rhs.m_rows) || (lhs.m_cols != rhs.m_cols))
    {
        std::cerr << "Error: matrices have different dimensions" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(lhs.m_rows, lhs.m_cols);

    for(int i = 0; i < result.m_matrix.size(); ++i)
    {
        result.m_matrix.at(i) = lhs.m_matrix.at(i) + rhs.m_matrix.at(i);
    }

    return result;
}

Matrix math::operator-(const Matrix& lhs, const Matrix& rhs)
{
    if((lhs.m_rows != rhs.m_rows) || (lhs.m_cols != rhs.m_cols))
    {
        std::cerr << "Error: matrices have different dimensions" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(lhs.m_rows, lhs.m_cols);

    for(int i = 0; i < result.m_matrix.size(); ++i)
    {
        result.m_matrix.at(i) = lhs.m_matrix.at(i) - rhs.m_matrix.at(i);
    }

    return result;
}

//матричное умножение
Matrix math::operator*(const Matrix& lhs, const Matrix& rhs)
{
    if(lhs.m_cols != rhs.m_rows)
    {
        std::cerr << "error" << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(lhs.m_rows, rhs.m_cols);

    for(size_t i = 0; i < rhs.m_rows; ++i)
    {
        for (size_t j= 0; j< rhs.m_cols; ++j)
        {
            for(size_t k = 0; k < lhs.m_cols; ++k)
            {
                result(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
        
    }

    return result;
}

Matrix &math::operator+=(IsMatrix auto &lhs, const IsMatrix auto &rhs)
{
    // TODO: insert return statement here
    return lhs;
}

Matrix &math::operator-=(IsMatrix auto &lhs, const IsMatrix auto &rhs)
{
    // TODO: insert return statement here
    return lhs;
}

Matrix &math::operator*=(IsMatrix auto &lhs, const IsMatrix auto &rhs)
{
    // TODO: insert return statement here
    return lhs;
}

