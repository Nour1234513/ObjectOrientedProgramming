
#include "cykel.h"
#include <iostream>
using namespace std;

Cykel::Cykel():Fordon(2)
{

}

void Cykel::paKallaUppmarksamet()
{
    cout << "pling pling" << endl;
}

void Cykel::indikeraKommandeSvang()
{
    cout << "rek upp handen" << endl;
}

void Cykel::svangVanster()
{
    cout << "cykla at vanster"<< endl;
}

void Cykel::svangHoger()
{
    cout << "cykla at hoger"<< endl;
}

void Cykel::kortFrammat(float antalKm)
{
    cout << "cykla fram för " << antalKm << endl;
}

void Cykel::skrivUtInfo(){
    cout << "Fordonet är en cykel." << endl;
        Super::skrivUtInfo();
}


