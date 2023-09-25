
#include "spelplan.h"

#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>


Spelplan::Spelplan(QWidget *parent):QWidget(parent)
{
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this , &Spelplan::uppdateraMasken);
        timer->start(50);
    setFocus();
    m_rkHuvud=RK(50,50);
    m_rkTiktning=RK(0,0);
}

void Spelplan::uppdateraMasken()
{


    if(m_rkHuvud.m_r==0&&m_rkTiktning.m_r==-1)
        m_rkHuvud.m_r=this->heightMM();
    if(m_rkHuvud.m_r==heightMM()&&m_rkTiktning.m_r==1)
        m_rkHuvud.m_r=0;
    if(m_rkHuvud.m_k==0&&m_rkTiktning.m_k==-1)
        m_rkHuvud.m_k=this->widthMM();
    if(m_rkHuvud.m_k==widthMM()&&m_rkTiktning.m_k==1)
        m_rkHuvud.m_k=0;
    if(alive){
    m_rkHuvud.m_r+=m_rkTiktning.m_r;
    m_rkHuvud.m_k+=m_rkTiktning.m_k;
    m_masken.push_front((m_rkHuvud));
    if(m_masken.size()>size)
        m_masken.pop_back();
    statue();
    }


    delamaten();
    update();


}

void Spelplan::keyPressEvent(QKeyEvent *event)
{

    int k=event->key();
    if(k==Qt::Key_Down){
        if(m_rkTiktning.m_r!=-1)
            m_rkTiktning=RK(1,0);
    }
    if(k==Qt::Key_Up){
        if(m_rkTiktning.m_r!=1)
            m_rkTiktning=RK(-1,0);
    }
    if(k==Qt::Key_Left){
        if(m_rkTiktning.m_k!=1)
            m_rkTiktning=RK(0,-1);
    }
    if(k==Qt::Key_Right){
        if(m_rkTiktning.m_k!=-1)
        m_rkTiktning=RK(0,1);
    }
}

void Spelplan::paintEvent(QPaintEvent *event)
{

    QColor color=Qt :: black;
    if(!alive)
        color=Qt::red;
    QPainter painter (this);
    painter.fillRect(rect(),Qt::white);
    for(unsigned int i =0;i<m_masken.size();i++){
        RK rk=m_masken[i];
        painter.fillRect(rk.m_k*m_cellstorlek,
                     rk.m_r*m_cellstorlek,
                     m_cellstorlek,
                     m_cellstorlek,
                     color);

    }
    for(unsigned int i =0;i<m_maten.size();i++){
        RK rk=m_maten[i];
        painter.fillRect(rk.m_k*m_cellstorlek,
            rk.m_r*m_cellstorlek,
            m_cellstorlek,
            m_cellstorlek,
                         Qt::green);
    }
}

void Spelplan::delamaten()
{
    if(m_maten.size()!=matenbitar){
        m_maten.push_back(RK((rand()%heightMM()+1),(rand()%widthMM()+1)));
    }
    for(unsigned int i =0;i<m_maten.size();i++){
        if(m_rkHuvud.m_k==m_maten[i].m_k&&m_rkHuvud.m_r==m_maten[i].m_r){
            m_maten.erase(m_maten.begin()+i);
            size+=1;
        }
    }
}


void Spelplan::statue()
{
    for(unsigned int i =1;i<m_masken.size();i++){
        if(m_masken.size()>=size){
        if(m_masken[i].m_k==m_masken[0].m_k&&m_masken[i].m_r==m_masken[0].m_r){
                alive=false;
            }
        }
    }
}


