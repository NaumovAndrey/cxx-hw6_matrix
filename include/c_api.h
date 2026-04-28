#pragma once
#include "/home/naumov/Documents/skillbox/cpp/hw6/include/export.h"

#ifdef MATH_DOBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Matrix Matrix;
    MATRIXLIB_EXPORT Matrix* math_createMatrix(int rows, int cols);
    MATRIXLIB_EXPORT void math_deleteMatrix(Matrix *M);

    MATRIXLIB_EXPORT real math_get(const Matrix *M, int row, int col);
    MATRIXLIB_EXPORT void math_set(Matrix *M, int row, int col, real val);

    MATRIXLIB_EXPORT Matrix* math_add(const Matrix *A, const Matrix *B);
    MATRIXLIB_EXPORT Matrix* math_subtract(const Matrix* A, const Matrix* B);
    MATRIXLIB_EXPORT Matrix* math_dot(const Matrix* A, const Matrix* B);
    MATRIXLIB_EXPORT void math_print(const Matrix* M);


#ifdef __cplusplus
}
#endif
