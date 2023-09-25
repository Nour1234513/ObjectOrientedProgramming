
#ifndef FORDON_H
#define FORDON_H
#include <iostream>

using namespace std;



class Fordon
{
public:
    //Fordon();
    Fordon(int antalHjul){m_antalHjul=antalHjul;};
    virtual void paKallaUppmarksamet()=0;
    virtual void indikeraKommandeSvang()=0;
    virtual void svangVanster(){cout << "rät";};
    virtual void svangHoger()=0;
    virtual void kortFrammat(float antalKm)=0;
    virtual void skrivUtInfo(){cout << "Ett fordon med " << m_antalHjul << " hjul." << endl;};
protected:
    int m_antalHjul;

};

#endif // FORDON_H
