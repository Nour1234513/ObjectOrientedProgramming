#include "spelare.h"
#include "minafunktioner.h"
#include "kort.h"
#include <iostream>
Spelare::Spelare()
{
    wallet=100;
}

bool Spelare::villSpela()
{
    return boolFranAnvandare("vill du spela?");
}

bool Spelare::villHaKort() const
{
    return boolFranAnvandare("vill du ha Kort?");
}

void Spelare::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    std::cout << kort.text() << std::endl;
}

void Spelare::bankenTogKort(const Kort &kort)
{
    std::cout << " banken fick " << kort.text() << std::endl;
}

void Spelare::KortlekenHarBlandats()
{
    std::cout << "Kort leken Har Blandats" << std::endl;
}


void Spelare::speletAvslutat(bool spelarenVann,int vinnst)
{
    if (spelarenVann){
        std::cout <<  " Du vann" << std::endl;
        wallet+=(vinnst*2);
        std::cout <<  " Du har " << wallet<< std::endl;
    }
    else{

        std::cout << " banken vann" << std::endl;
        std::cout <<  " Du har " << wallet<< std::endl;
    }
}


int Spelare::hurmycketvilldusattsa(){
    std::cout << "hur mycket vill du sattsa" << std::endl;
    int x=0;
    std::cin >> x;
    if(x>0&&x<=wallet){
        wallet-=x;
        return x;
    }
    return hurmycketvilldusattsa();
}

int Spelare::pengarIKonto()
{
    return wallet;
}

bool Spelare::villDudoublera(int pricepool)
{
    std::cout << " vill du dublera "<< std::endl;
    std::string x;
    std::cin >> x;
    if(x=="ja"){
        wallet-=pricepool;
        return true;
    }
    return false;
}


Korthand &Spelare::korthand()
{
   return m_hand;
}
