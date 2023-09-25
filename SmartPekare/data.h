#ifndef DATA_H
#define DATA_H

#include <iostream>
struct Data{
    int m_tal = 0;
    Data(int tal) { m_tal = tal;
        std::cout << "Data(" << m_tal << ")" << std::endl; }
    ~Data() { std::cout << "~Data(" << m_tal << ")" << std::endl; }
};

#endif // DATA_H
