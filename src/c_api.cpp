#include "c_api.h"

#include "matrix.hpp"

struct MatrixHandle
{
    math::Matrix matrix;

    MatrixHandle(int rows, int cols)
        : matrix(rows, cols)
    {}
};

extern "C"
{

    MATRIXLIB_EXPORT Matrix math_createMatrix(int rows, int cols)
    {
        return new MatrixHandle(rows, cols);
    }

    MATRIXLIB_EXPORT void math_deleteMatrix(Matrix matrix)
    {
        delete matrix;
    }

    MATRIXLIB_EXPORT void math_set(
        Matrix matrix,
        int row,
        int col,
        real value
    )
    {
        matrix->matrix(row, col) = value;
    }

    MATRIXLIB_EXPORT real math_get(
        Matrix matrix,
        int row,
        int col
    )
    {
        return matrix->matrix(row, col);
    }

    MATRIXLIB_EXPORT void math_print(
        Matrix matrix
    )
    {
        matrix->matrix.print();
    }

}