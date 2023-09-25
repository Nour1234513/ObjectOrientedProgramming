
#include "spelarbot.h"
#include <iostream>
#include <ostream>


Spelarbot::Spelarbot(int antalPartierAttspela)
{
    m_antalPartierAttSpela=antalPartierAttspela;
    botwallet=1000;
}

bool Spelarbot::villSpela()
{
    if(m_antalSpeladeSpel==m_antalPartierAttSpela)
        return false;
    return true;
}

bool Spelarbot::villHaKort() const
{
    if(m_hand.antalKort()==4)
        return true;
//    int poang=0;
//    for(int x=0 ; x<m_hand.antalKort();x+=1){
//        if(m_hand.kort(x).valor()>10)
//            poang+=10;
//        else {
//            poang+=m_hand.kort(x).valor();
//        }
//    }
    int poang=0;
    int ess=0;
    for(unsigned long long int x=0 ; x<m_hand.antalKort();x+=1){
        if(m_hand.antalKort()==5)
            return 21;
        if(m_hand.kort(x).valor()==1){
            ess+=1;
        }
        if(m_hand.kort(x).valor()>10)
            poang+=10;
        else {
            poang+=m_hand.kort(x).valor();
        }
    }
    for(;ess>0;ess-=1){
        if(poang+10<=21)
            poang+=10;
    }
    if (poang<16)
        return true;
    return false;
}

void Spelarbot::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    std::cout << "bot tog" << kort.text() << std::endl;
}

void Spelarbot::bankenTogKort(const Kort &kort)
{
    std::cout << "bank tog " << kort.text() << std::endl;
}

void Spelarbot::KortlekenHarBlandats()
{
    std::cout << "Kort leken Har Blandats" << std::endl;
}

void Spelarbot::speletAvslutat(bool spelarenVann, int vinnst)
{

    m_antalSpeladeSpel+=1;
    if(spelarenVann){
        m_totalvinst+=vinnst;
        botwallet+=vinnst;
        std::cout << "bot van" << std::endl;
        std::cout << "bot har : " << botwallet  << std::endl;
    }
    else{
        std::cout << "bot lost" << std::endl;
        std::cout << "bot har : " << botwallet  << std::endl;
    }
    if(m_antalSpeladeSpel==m_antalPartierAttSpela||botwallet==0){

        std::cout << "vinnst :" << m_totalvinst << std::endl;
       // std::cout << "vinnsten är " << botwallet+m_totalvinst-10000000 << std::endl;
    }
}

int Spelarbot::hurmycketvilldusattsa()
{
    botwallet-=1;
    return 1;
}

int Spelarbot::pengarIKonto()
{
    return botwallet;
}

bool Spelarbot::villDudoublera(int pricepool)
{
    if(m_hand.kort(0).valor()>=10){
        botwallet-=pricepool;
        return true;
    }
    return false;
}

 Korthand &Spelarbot::korthand()
{
    return m_hand;
}
