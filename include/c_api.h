#pragma once

#include "matrixlib_export.h"

#ifdef __cplusplus
extern "C" {
	#endif

	typedef struct MatrixHandle MatrixHandle;
	typedef MatrixHandle* Matrix;

	typedef double real;

	MATRIXLIB_EXPORT Matrix math_createMatrix(int rows, int cols);
	MATRIXLIB_EXPORT void math_deleteMatrix(Matrix matrix);
	MATRIXLIB_EXPORT void math_set(Matrix matrix, int row, int col, real value);
	MATRIXLIB_EXPORT real math_get(Matrix matrix, int row, int col);
	MATRIXLIB_EXPORT void math_print(Matrix matrix);

	#ifdef __cplusplus
}
#endif