#include "bankir.h"
#include <cassert>
#include <iostream>

Bankir::Bankir()
{
m_pSpelare=nullptr;
}

void Bankir::registreraSpelare(abstraktspelare *pSpelare)
{
    m_pSpelare=pSpelare;
}

bool Bankir::harRegisteradeSpelare() const
{
if(m_pSpelare!=nullptr)
    return true;
return false;
}



void Bankir::spelaEnOmgang()
{
    if(m_pSpelare==nullptr)
        return ;
    if(m_kortlek.antalKort()<15){
        m_kortlek.aterstallBlandadkortlek();
        (*m_pSpelare).KortlekenHarBlandats();
    }
    if((*m_pSpelare).villSpela()&&(m_pSpelare->pengarIKonto())>0){
        m_pSpelare->korthand().rensa();
        int pricepool=m_pSpelare->hurmycketvilldusattsa();




        Kort k=m_kortlek.utplockatKort();
        m_pSpelare->tagEmotKort(k);

        if(pricepool<=(*m_pSpelare).pengarIKonto()){
            if(m_pSpelare->villDudoublera(pricepool)){
            pricepool=pricepool*2;
            }
        }

        while(m_pSpelare->korthand().poang()<21&&(*m_pSpelare).villHaKort()){

            Kort k=m_kortlek.utplockatKort();
            m_pSpelare->tagEmotKort(k);

            std::cout << "summa är " << m_pSpelare->korthand().poang() << std::endl;


        }
        int spelarpoang = m_pSpelare->korthand().poang();
//        if(m_pSpelare->korthand().antalKort()==5&&spelarpoang<21)
//            spelarpoang=21;

        if(spelarpoang>21){
            (*m_pSpelare).speletAvslutat(false,pricepool);
        }
        else if (spelarpoang==21)
            (*m_pSpelare).speletAvslutat(true,pricepool*2);

        else{
            Korthand bankhand;

            while (bankhand.poang()<16){

                Kort kort=m_kortlek.utplockatKort();
                bankhand.stoppaInKort(kort);
                (*m_pSpelare).bankenTogKort(kort);
            }
            int bankpoang=bankhand.poang();
            bool spelarenVann=(bankpoang>21||spelarpoang>=bankpoang);
            (*m_pSpelare).speletAvslutat(spelarenVann,pricepool);


        }
    }

    else m_pSpelare=nullptr;
}
