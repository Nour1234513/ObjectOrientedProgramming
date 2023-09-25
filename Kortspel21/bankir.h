#ifndef BANKIR_H
#define BANKIR_H

#include "abstraktspelare.h"
#include "kortlek.h"

class Bankir
{
public:
    Bankir();
    void registreraSpelare(abstraktspelare *pSpelare);
    bool harRegisteradeSpelare() const ;
    void spelaEnOmgang();
private:
    Kortlek m_kortlek;
    abstraktspelare *m_pSpelare;

};

#endif // BANKIR_H
