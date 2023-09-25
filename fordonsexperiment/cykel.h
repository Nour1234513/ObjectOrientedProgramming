

#ifndef CYKEL_H
#define CYKEL_H
#include "fordon.h"



class Cykel:public Fordon
{
public:
    Cykel();

    // Fordon interface
public:
    void paKallaUppmarksamet() override;
    void indikeraKommandeSvang() override;
    void svangVanster() override;
    void svangHoger() override;
    void kortFrammat(float antalKm) override;
    void skrivUtInfo() override;
private:
    typedef Fordon Super;
};

#endif // CYKEL_H
