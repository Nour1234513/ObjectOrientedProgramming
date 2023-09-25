
#ifndef BIL_H
#define BIL_H
#include "fordon.h"

class Bil : public Fordon
{
public:
    Bil();

    // Fordon interface
public:
    void paKallaUppmarksamet() override;
    void indikeraKommandeSvang() override;
    void svangVanster()override;
    void svangHoger() override;
    void kortFrammat(float antalKm) override;
    void skrivUtInfo() override;
private:
    typedef Fordon Super;
};

#endif // BIL_H
