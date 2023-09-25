#include "kortlek.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <assert.h>
Kortlek::Kortlek()
{

}

int Kortlek::antalKort() const
{
    return m_korten.size();
}

Kort Kortlek::utplockatKort()
{
    Kort kort=m_korten.back();
    m_korten.pop_back();
    return kort;
}

void Kortlek::aterstalKortlek()
{
    m_korten.clear();
   Kort::Farg farger[4]{Kort::klover,Kort::hjarter,Kort::ruter,Kort::spader};
    for(int farg =0 ;farg<4; farg+=1){
        for(int nummer=1 ; nummer<14;nummer+=1){
            Kort kort(farger[farg] ,nummer);
            m_korten.push_back(kort);
        }
    }
    assert(m_korten.size()==52);
}

void Kortlek::blanda()
{
    static unsigned seed=std :: chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine slumpgenerator(seed);
    std::shuffle(m_korten.begin(),m_korten.end(),slumpgenerator);
}

void Kortlek::aterstallBlandadkortlek()
{
    aterstalKortlek();
    blanda();
}
