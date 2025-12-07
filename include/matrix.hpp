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
        Matrix() = default;
        Matrix(int rows, int cols) : 
                            m_rows(rows), m_cols(cols), m_matrix(std::vector<real>(rows*cols)){};

        real& operator()(int row, int col);
        const real& operator()(int row, int col) const;

        void print();

        friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

        template <typename T>
        concept IsMatrix = std::same_as<std::remove_cvref_t<T>, Matrix>;

        // Операторы присваивания-расширения
        friend Matrix& operator+=(IsMatrix auto& lhs, const IsMatrix auto& rhs);
        friend Matrix& operator-=(IsMatrix auto& lhs, const IsMatrix auto& rhs);
        friend Matrix& operator*=(IsMatrix auto& lhs, const IsMatrix auto& rhs);

        // Потоковые операторы
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
        friend std::istream& operator>>(std::istream& is, Matrix& m);
    };
    
    Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    Matrix operator*(const Matrix& lhs, const Matrix& rhs);
}