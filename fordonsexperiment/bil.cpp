
#include "bil.h"
#include <iostream>
using namespace std;

Bil::Bil() : Fordon (4)
{

}

void Bil::paKallaUppmarksamet()
{
    cout << "tut tut" << endl;
}

void Bil::indikeraKommandeSvang()
{
    cout << "sätt blinkers på" << endl;
}

void Bil::svangVanster()
{
    cout << "vrid rattan åt Vanster" << endl;
}

void Bil::svangHoger()
{
    cout << "vrid rattan åt Hoger" << endl;
}

void Bil::kortFrammat(float antalKm)
{
    cout << "gassa på " << antalKm << endl;
}

void Bil::skrivUtInfo(){
    cout << "Fordonet är en Bil." << endl;
        Super::skrivUtInfo();
}
