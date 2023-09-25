#include <iostream>
#include <cassert>
#include <memory>
#include "data.h"
using namespace std;
shared_ptr<Data> spGLOBALPEKARE;
void provaSharedPekare(){
    cout << endl << ">> provaSharedPekare >>" << endl;
    shared_ptr<Data> spD1( new Data(1) );
    shared_ptr<Data> spD2( new Data(2) );
    shared_ptr<Data> spD3( new Data(3) );
    cout << "spD1.use_count() == " << spD1.use_count() << endl;
    cout << "spD2.use_count() == " << spD2.use_count() << endl;
    cout << "spD3.use_count() == " << spD3.use_count() << endl;
    cout << "låter även spD3 och spGLOBALPEKARE peka på 1:an" << endl;
    spD3 = spD1;
    spGLOBALPEKARE = spD1;
    cout << "spGLOBALPEKARE.use_count() == " << spGLOBALPEKARE.use_count() << endl;
    cout << "<< provaSharedPekare <<" << endl;
}
struct Markering {
    weak_ptr<Data> m_wpMarkeratObjekt;
    void behandlaAktuellMarkering(){
        // TODO!
        if(!(m_wpMarkeratObjekt).expired())
            cout << " Objekt med värde tal behandlas." << endl;
        if(m_wpMarkeratObjekt.expired())
            cout << "inget objekt är markerat." << endl;

}
};
Markering MARKERING;
void provaWeakPointer(){
    cout << endl << ">> provaWeakPointer >>" << endl;
    shared_ptr<Data> m_spObjA( new Data(11) );
    shared_ptr<Data> m_spObjB( new Data(22) );
    MARKERING.m_wpMarkeratObjekt = m_spObjA; // markera detta objekt
    MARKERING.behandlaAktuellMarkering();
    m_spObjA->m_tal = 11000;
    MARKERING.behandlaAktuellMarkering();
    m_spObjA = m_spObjB;
    MARKERING.behandlaAktuellMarkering();
    cout << "<< provaWeakPointer <<" << endl;
}

void ingangTillProvaShared(){
    cout << "ingangTillProvaShared" << endl;
    //provaSharedPekare();
    provaWeakPointer();
}
