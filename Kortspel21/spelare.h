#ifndef SPELARE_H
#define SPELARE_H


#include "abstraktspelare.h"
#include "kort.h"
#include "korthand.h"
#include <string.h>

class Spelare:public abstraktspelare
{
public:
    Spelare();
    bool villSpela()override;
    bool villHaKort() const override;
    void tagEmotKort(const Kort &kort)override;
    void bankenTogKort(const Kort &kort)override;
    void KortlekenHarBlandats()override;
    void speletAvslutat(bool spelarenVann,int vinnst)override;
    int hurmycketvilldusattsa()override;
    int pengarIKonto() override;
    bool villDudoublera(int pricepool) override;

     Korthand &korthand()override;
private:
    Korthand m_hand;
    int wallet;
};

#endif // SPELARE_H
