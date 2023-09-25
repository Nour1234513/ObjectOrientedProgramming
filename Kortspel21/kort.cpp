#include <kort.h>



Kort::Kort(Farg farg, int valor)
{
    m_farge=farg;
    m_valor=valor;
}

Kort::Farg Kort::farg() const
{
    return m_farge;

}

int Kort::valor() const
{

    return m_valor;
}

std::string Kort::text() const
{
    static const char* valornamn[14]{"finns ej","ess","tva","tre","fyra","fem","sex","sju","atta","nio","tio","knekt","dam","kung"};
    return fargstrang() + " " +valornamn[m_valor];
}

std::string Kort::fargstrang() const
{
    static const char* farg[4]{"klöver","ruter","hjärter","spader"};
    if (m_farge==klover)
        return farg[0];
    if(m_farge== ruter)
        return farg[1];
    if(m_farge==hjarter)
        return farg[2];
    if(m_farge==spader)
        return farg[3];
}

