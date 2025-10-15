#pragma once
#include <vector>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int m_rows{0}, m_cols{0};
        std::vector<real> m_matrix;

    public:
        Matrix();
        Matrix(int rows, int cols) : 
                            m_rows(rows), m_cols(cols), m_matrix(std::vector<real>(rows*cols)){};

        real& operator()(int row, int col);

        void print();

        friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    };
    
    Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    Matrix operator*(const Matrix& lhs, const Matrix& rhs);
}