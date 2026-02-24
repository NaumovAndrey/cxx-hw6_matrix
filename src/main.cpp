#include "matrix.hpp"
#include <iostream>

using namespace math;


int main()
{
    math::Matrix m1(3, 3);
    math::Matrix m2(3, 3);

    m1(0, 0) = 7; m1(0, 1) = 2; m1(0, 2) = 1;
    m1(1, 0) = 0; m1(1, 1) = 3; m1(1, 2) = -1;
    m1(2, 0) = 4; m1(2, 1) = -2; m1(2, 2) = 5;

    m2(0, 0) = 3; m2(0, 1) = 0; m2(0, 2) = 2;
    m2(1, 0) = 1; m2(1, 1) = -1; m2(1, 2) = 0;
    m2(2, 0) = -1; m2(2, 1) = 4; m2(2, 2) = 1;

    std::cout << "Матрица m1 \n" << m1 << std::endl;
    std::cout << "Матрица m2 \n" << m2 << std::endl;

    math::Matrix m_sum = m1 + m2;
    std::cout << "m1 + m2 =\n" << m_sum << std::endl;

    math::Matrix m_sub = m1 - m2;
    std::cout << "m1 - m2 =\n" << m_sub << std::endl;

    math::Matrix m_mul = m1 * m2;
    std::cout << "m1 * m2 =\n" << m_mul << std::endl;

    m1 += m2;
    std::cout << "m1 += m2 =>\n" << m1 << std::endl;

    m1 -= m2;
    std::cout << "m1 -= m2 =>\n" << m1 << std::endl;

    return 0;
}