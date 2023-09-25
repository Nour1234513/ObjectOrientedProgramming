
#ifndef TRACE_H
#define TRACE_H

#include <QDebug>
#include <iostream>
#include <ostream>
#include <string>
class Trace
{
public:
    enum Outputtype { output_cout, output_qdebug };
    Trace(const std::string& funktionsnamn){
        m_funktionsnamn = funktionsnamn;
        printline( indentering() + ">>" + m_funktionsnamn + ">>" );
        s_aktuelltDjup += 1;
    };
    Trace(const std::string& funktionsnamn, const std::string& extra){
        m_funktionsnamn = funktionsnamn;
        printline( indentering()+" >>" + m_funktionsnamn + " " +extra + ">>" );
        s_aktuelltDjup += 1;

    };

    ~Trace(){
        s_aktuelltDjup -= 1;
        printline( indentering() + "<<" + m_funktionsnamn + "<<" );
    };

    void message(const std::string& str){
        printline( indentering() + "trace:" + str );
    };

#define traceme Trace traceObject( __func__ );
#define tracemex( extra ) Trace traceObject( __func__, extra );
#define traceMsg( meddelande ) traceObject.message( meddelande );
private:
    std::string m_funktionsnamn;
    std::string indentering(){
        std::string mellanslag;
        for(int x =0;x<(3*s_aktuelltDjup);x+=1){
            mellanslag.push_back(' ');
        }
        return mellanslag;
    };
    void printline(const std::string& str){
        if(s_utskriftsMetod==output_cout)
            std::cout << str << std::endl;
        else {
            qDebug() << str.c_str();
        }
    };
    static int s_aktuelltDjup;
    static Outputtype s_utskriftsMetod;
};
#endif // TRACE_H
