#include <iostream>
#include <string>
#include <optional>
using namespace std;

long int strtol(const char* str, char** ppEnd, int base);


bool hittadeFodelsearFranNamn(const std::string namn, int *pFodelsear){
    // TODO
    if(namn=="Newten"){
        *pFodelsear=1960;
        return true;
    }
    else {
        *pFodelsear=-360;
        return false;
    }
}
void provaHittadeFodelsear(){
    // TODO
    int ar=0;
    string str;
    cin >>str;
    if (hittadeFodelsearFranNamn(str, &ar)){
        cout << str <<  " födelsår" << ar<< endl;
    }
    else {
        cout << "who the fuck is this" << endl;
    }
}
std::optional<int> fodelsearFranNamn(const std::string namn){
    // TODO
    if(namn=="Newten")
        return 1960;
}

void provaFodelsear(){
    // TODO
    string str;
    cin >>str;
    std::optional<float> ar=fodelsearFranNamn(str);
    if (ar.has_value()){
        cout << str << " " << *fodelsearFranNamn(str)  << endl;
    }
    else {
        cout << "who the fuck is this" <<endl;
    }


}

void ingangTillFodelsear(){
    provaHittadeFodelsear();
    provaFodelsear();
}

