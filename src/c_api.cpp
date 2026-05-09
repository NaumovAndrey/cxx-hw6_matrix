#include "export.h"
#include "matrix.hpp"
#include "c_api.h"

using Matrix = math::Matrix*;

extern "C" {

MATRIXLIB_EXPORT Matrix math_createMatrix(int rows, int cols)
{
    return new math::Matrix(rows, cols);
}

MATRIXLIB_EXPORT void math_deleteMatrix(Matrix M)
{
    delete M;
}

MATRIXLIB_EXPORT void math_set(Matrix M, int row, int col, real val)
{
    (*M)(row, col) = val;
}

MATRIXLIB_EXPORT real math_get(const Matrix M, int row, int col)
{
    return (*M)(row, col);
}

MATRIXLIB_EXPORT void math_print(const Matrix M)
{
    M->print();
}

}