#pragma once
#include <vector>
#include <concepts>
#include <type_traits>
#include <ostream>
#include <istream>
#include <stdexcept>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int m_rows{0}, m_cols{0};
        std::vector<real> m_matrix;

    public:
        Matrix() = default;
        Matrix(int rows, int cols) : m_rows(rows), m_cols(cols), m_matrix(std::vector<real>(rows * cols)) {};

        real &operator()(int row, int col);
        const real &operator()(int row, int col) const;

        void print();

        int rows() const
        {
            return m_rows;
        }

        int cols() const
        {
            return m_cols;
        }

        friend Matrix operator+(Matrix lhs, const Matrix &rhs);
        friend Matrix operator-(Matrix lhs, const Matrix &rhs);
        friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);

        // Операторы присваивания-расширения
        Matrix &operator+=(const Matrix &rhs);
        Matrix &operator-=(const Matrix &rhs);
        Matrix &operator*=(const Matrix &rhs);

        // Потоковые операторы
        friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
        friend std::istream &operator>>(std::istream &is, Matrix &m);
    };

}
