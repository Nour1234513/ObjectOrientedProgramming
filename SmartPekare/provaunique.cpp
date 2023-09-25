#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
#include "data.h"
using namespace std;
Data* pNyttDataobjekt(int tal){
    Data *pData = new Data( tal );
    return pData;
}
unique_ptr<Data> upNyttDataobjekt(int tal){
    Data *pData = new Data( tal );
    return unique_ptr<Data>(pData);
}
// Ett av objekten 1,2,3,4 kommer att frigöras innan funktionen lämnas
void provaUnique(){
    cout << ">>provaUnique>>" << endl;
    upNyttDataobjekt(0); // glömmer att ta hand om returvärdet
    unique_ptr<Data> upA = upNyttDataobjekt(1);
    unique_ptr<Data> upB(upNyttDataobjekt(2));
    unique_ptr<Data> upC(new Data(3));
    upB = upNyttDataobjekt(4);
    cout << "<<provaUnique<<" << endl;
}
void provaExplicitMove(){
    cout << endl << "provaExplicitmove" << endl;
    string str1 ="hello";
    string str2=std::move(str1);
    cout << "str1: " << str1 << endl;
    cout <<"str2: "<< str2 << endl;
}
vector<unique_ptr<Data>> VEKTOR;
void stoppaInIVektor(){
    unique_ptr<Data> upData1 = upNyttDataobjekt(1);
    VEKTOR.push_back(std::move (upData1) );
    VEKTOR.push_back( upNyttDataobjekt(2));
}

void ingangTillProvaUnique(){
    //provaUnique();
    //provaExplicitMove();
}
