#include "minafunktioner.h"
#include <iostream>
using namespace std;

bool boolFranAnvandare(const std::string &txt){
cout << txt << endl;
string svar;
cin >> svar;
if (svar=="ja")
    return true;
else if (svar=="nej")
    return false;
else {
    cout << "try again" << endl;
    return boolFranAnvandare(txt);
}
};
