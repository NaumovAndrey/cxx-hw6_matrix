#include "/home/naumov/Documents/skillbox/cpp/hw6/include/matrix.hpp"
#include "/home/naumov/Documents/skillbox/cpp/hw6/include/c_api.h"


struct Matrix : public math::Matrix
{
public:
    Matrix(const struct math::Matrix &M) : math::Matrix(M) {};
};

MATRIXLIB_EXPORT Matrix* math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols)); 
}

MATRIXLIB_EXPORT void math_deleteMatrix(Matrix *M)
{
    delete M;
}

MATRIXLIB_EXPORT real math_get(const Matrix *M, int row, int col)
{
    return M->operator()(row, col);
}

MATRIXLIB_EXPORT void math_set(Matrix *M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

MATRIXLIB_EXPORT Matrix* math_add(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A + *B);
}

MATRIXLIB_EXPORT Matrix* math_subtract(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A - *B);
}

MATRIXLIB_EXPORT Matrix* math_dot(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A * *B);
};

MATRIXLIB_EXPORT void math_print(const Matrix *M)
{
    M->print();
}
