#include "matrix.hpp"
#include <iostream>


int main()
{
    math::Matrix m1(3, 3);
    math::Matrix m2(3, 3);

    m1(0, 0) = 7;
    m1(1, 1) = 3;

    m2(0, 0) = 3;
    m2(1, 1) = 9;


    m1.print();
    std::cout << std::endl;
    m2.print();
    std::cout << std::endl;

    math::Matrix m_sum = m1 + m2;
    m_sum.print();
    std::cout << std::endl;

    math::Matrix m_sub = m1 - m2;
    m_sub.print();
    std::cout << std::endl;

    math::Matrix m_mul = m1 * m2;
    m_mul.print();
    std::cout << std::endl;

    return 0;
}