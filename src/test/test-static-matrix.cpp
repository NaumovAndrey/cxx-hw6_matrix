#include <iostream>
#include </home/naumov/Documents/skillbox/cpp/hw6/include/matrix.hpp>

int main()
{
    
    math::Matrix m(3, 3);
    m(0, 0) = 1.;
    m(1, 1) = 2.;

    math::Matrix m0(3, 3);
    m0(0, 0) = 5.;
    m0(1, 1) = 9.;

    std::cout << "matrix m is" << std::endl;
    m.print();

    std::cout << "matrix m0 is" << std::endl;
    m0.print();

    math::Matrix m_addition = m + m0;
    std::cout << "matrix sum"<< std::endl;
    m_addition.print();

    math::Matrix m_sub = m - m0;
    std::cout << "matrix sub"<< std::endl;
    m_sub.print();

    math::Matrix m_mul = m * m0;
    std::cout << "matrix mul"<< std::endl;
    m_mul.print();


    std::cout <<"hello world" << std::endl;
    return 0;
}