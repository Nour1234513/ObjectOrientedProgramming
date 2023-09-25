#include "komplex.h"
#include <assert.h>
#include <iostream>

Komplex::Komplex(){}


Komplex ::Komplex(float re, float im){
    m_re=re;
    m_im=im;
}
Komplex Komplex::fromAbsArg(float a, float grader)
{

    Komplex fromAbs;
    fromAbs.m_re= sin(grader)*a;
    fromAbs.m_im=cos(grader)*a;
    return fromAbs;
}

float Komplex::re() const
{
    return m_re;
}

float Komplex::im() const
{
    return m_im;
}

float Komplex::abs() const
{
    return sqrt((m_re*m_re)+(m_im*m_im));
}

float Komplex::argRadians() const
{
    return atan2(m_im, m_re);
}

float Komplex::argDegrees() const
{
    return M_PI/180;
}

Komplex Komplex::konjugat() const
{
    return Komplex(m_re, -m_im);
}

Komplex::operator std::string() const
{

    return string (to_string(m_re)+to_string(m_im)+"i");


}
const Komplex &Komplex::operator+=(const Komplex &h)
{
    this->m_re =this->m_re+h.m_re;
    this->m_im=this->m_im+h.m_im;
    return *this;
}

const Komplex &Komplex::operator-=(const Komplex &h)
{
    this->m_re =this->m_re-h.m_re;
    this->m_im=this->m_im-h.m_im;
    return *this;
}

const Komplex &Komplex::operator*=(const Komplex &h)
{
    this->m_re=this->m_re*h.m_re-this->m_im*h.m_im;
    this->m_im=this->m_re*h.m_im+this->m_im*h.m_re;
    return *this;
}

const Komplex &Komplex::operator/=(const Komplex &h)
{
    Komplex taljare = *this * h.konjugat();
    Komplex namnare = h * h.konjugat();
    assert( std::abs(namnare.im()) < 0.0001);
    this->m_re=( taljare.re()/namnare.re());
    this->m_im= taljare.im()/namnare.re();
    return *this;
}

Komplex operator "" _i(long double d){
    return Komplex(0, d);
}
Komplex operator "" _i(unsigned long long i){
    return Komplex(0,i);
}

Komplex operator +(const Komplex & v , const Komplex& h){
   return Komplex ((v.re()+h.re()),(v.im()+h.im()));
}
Komplex operator -(const Komplex & v , const Komplex& h){
    return Komplex((v.re()-h.re()),(v.im()-h.im()));
}
Komplex operator -(const Komplex & c){
    return Komplex(-c.re(),-c.im()) ;
}
Komplex operator *(const Komplex & v , const Komplex& h){
    return Komplex( v.re()*h.re()-v.im()*h.im(), v.re()*h.im()+v.im()*h.re());

}
Komplex operator /(const Komplex & v , const Komplex& h){
    Komplex taljare = v * h.konjugat();
    Komplex namnare = h * h.konjugat();
    assert( std::abs(namnare.im()) < 0.0001);
    return Komplex( taljare.re()/namnare.re(), taljare.im()/namnare.re());

}
std::ostream& operator<<(std::ostream& out, Komplex c)
{
    out << string(c);
    return out;
}
