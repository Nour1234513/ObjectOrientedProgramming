
#include <iostream>
#include <typeinfo.h>
void test();
using namespace std;

class Bas {
public:

    void iv(){cout << "Bas iv()"<< endl;}
   virtual void v(){cout << "Bas v()"<< endl;}
   virtual ~Bas (){cout << "Bas destruktor"<< endl;}
};
class Sub:public Bas{
public:
    void iv(){cout << "Sub iv()"<< endl;}
    void v(){cout << "Sub v()"<< endl;}
    ~Sub(){cout << "Sub destruktor"<< endl;}

};
void test1(){
    cout << endl << "test1, anrop via sub" << endl;
    Sub sub ;
    sub.iv();
    sub.v();
    cout << endl << "test2, anrop via bas1" << endl;
    Bas bas1= sub ;
    bas1.iv();
    bas1.v();
    cout << endl << "test3, anrop via bas-pekare" << endl;
    Bas *pB=&sub;
    pB->iv();
    pB->v();
    (*pB).iv();
    (*pB).v();
    cout << endl << "test4, anrop via basreferens" << endl;
    Bas &bas2=sub ;
    bas2.iv();
    bas2.v();
    cout << endl << "testaVirtual avslutas" << endl;
}
void test11(){
    cout << "test destrukt" << endl;
    Bas* pBase=new Sub;
    delete pBase;
}
void provaDownCasting(Bas *pBas){
    Sub *pSub=dynamic_cast<Sub*>(pBas);
    if(pSub!=nullptr)
        cout << "yes vi har fått en pekare till ett subklass"<< endl;
            else cout << "nope, typomvandling gick ej"<< endl;
}
void exprementMedDynamicDownCasting(){
//            cout << "exprement med dynamic down casting"<<endl;
//            Bas *px=new Bas;
//            Bas *py=new Sub;
//            provaDownCasting(px);
//            provaDownCasting(py);
//            delete px;
//            delete py;

}
int main()
{

            //exprementMedDynamicDownCasting();
           // test();
}
