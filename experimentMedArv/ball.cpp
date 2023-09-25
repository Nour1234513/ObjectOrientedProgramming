#include <iostream>
class ball{
public:
    ball(int diameter){m_diameter=diameter;};
private:
    int m_diameter;
};





class pingball:public ball{
public:
    pingball(int diameter ,bool isyellow):ball(diameter){m_isyellow=isyellow;};
    void skrivaut(){if (m_isyellow)  (std::cout << "is  yellow:" << std::endl);}
private:
    bool m_isyellow;
};

void test(){
    pingball s(20,false);
    s.skrivaut();
    pingball a(20,true);
    a.skrivaut();
}
