#include "c_api.h"
#include <iostream>

int main()
{
    Matrix m = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1.0);
    math_set(m, 0, 1, 34.0);

    math_print(m);

    math_deleteMatrix(m);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}