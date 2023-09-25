#ifndef KORT_H
#define KORT_H
#include <string>

class Kort
{
public:

    enum Farg{
        klover,ruter,hjarter,spader
    };
    Kort(Farg farg,int valor);
    Farg farg() const;
    int valor() const;
    std::string text() const ;

private:
    std::string fargstrang() const;
    Farg m_farge;
    int m_valor;
};


#endif // KORT_H
