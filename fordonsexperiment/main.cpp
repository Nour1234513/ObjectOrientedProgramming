
#include "bil.h"
#include "cykel.h"
#include "fordon.h"
#include <iostream>

using namespace std;

void test(Fordon &Fordon){
    cout << "aker en runda" << endl;
    Fordon.skrivUtInfo();
    Fordon.kortFrammat(2);
    Fordon.indikeraKommandeSvang();
    Fordon.svangHoger();
    Fordon.kortFrammat(1.5);
    Fordon.paKallaUppmarksamet();
    Fordon.kortFrammat(0.5);
    Fordon.svangVanster();
    Fordon.kortFrammat(0.1);
    cout << "avslutar ak" << endl;
}
void test1(){
    Cykel cykel;
    Bil bil;
    Fordon & refTillCykel =cykel;
    Fordon &ettFordon = cykel;

    //test(refTillCykel);
   // test(ettFordon);

    //test(bil);
    //test(cykel);

}

int main()
{
    test1();
}
