
#ifndef ABSTRAKTSPElARE_H
#define ABSTRAKTSPElARE_H


#include "kort.h"
#include "korthand.h"
#include <string.h>

class abstraktspelare
{
public:
    //Spelare();
    virtual bool villSpela()=0;
    virtual bool villHaKort() const=0;
    virtual void tagEmotKort(const Kort &kort)=0;
    virtual void bankenTogKort(const Kort &kort)=0;
    virtual void KortlekenHarBlandats()=0;
    virtual void speletAvslutat(bool spelarenVann,int vinnst)=0;
    virtual int hurmycketvilldusattsa()=0;
    virtual int pengarIKonto()=0;
    virtual bool villDudoublera(int pricepool)=0;

   virtual  Korthand &korthand()=0;
private:
    Korthand m_hand;

};

#endif // SPELARE_H
