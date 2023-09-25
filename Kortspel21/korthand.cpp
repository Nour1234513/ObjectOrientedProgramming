#include "korthand.h"
#include <cassert>
#include <iostream>


Korthand::Korthand()
{

}

void Korthand::rensa()
{
    m_Korten.clear();
}

int Korthand::antalKort() const
{
    return m_Korten.size();
}

Kort Korthand::kort(int nr) const
{
    return m_Korten[nr];
}

void Korthand::stoppaInKort(const Kort &kort)
{
    m_Korten.push_back(kort);
}

int Korthand::poang() const
{
    int poang=0;
    int ess=0;
    for(unsigned long long int x=0 ; x<m_Korten.size();x+=1){
        if(m_Korten.size()==5)
            return 21;
        if(m_Korten[x].valor()==1){
            ess+=1;
        }
        if(m_Korten[x].valor()>10)
            poang+=10;
        else {
        poang+=m_Korten[x].valor();
        }
    }
    for(;ess>0;ess-=1){
        if(poang+10<=21)
        poang+=10;
    }

    return poang;
}
