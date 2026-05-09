#include "matrix.hpp"
#include "export.h" 

#ifdef __cplusplus
extern "C" {
#endif

    using Matrix = math::Matrix*;
    using real = double;

    MATRIXLIB_EXPORT Matrix math_createMatrix(int rows, int cols);
    MATRIXLIB_EXPORT void math_deleteMatrix(Matrix M);
    MATRIXLIB_EXPORT void math_set(Matrix M, int row, int col, real val);
    MATRIXLIB_EXPORT real math_get(const Matrix M, int row, int col);
    MATRIXLIB_EXPORT void math_print(const Matrix M);

#ifdef __cplusplus
}
#endif