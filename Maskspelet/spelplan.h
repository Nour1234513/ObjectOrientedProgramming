
#ifndef SPELPLAN_H
#define SPELPLAN_H


#include <QWidget>
#include <deque>

class Spelplan : public QWidget
{
    Q_OBJECT
public:
    explicit Spelplan(QWidget *parent=nullptr);

    // QWidget interface
private slots:
    void uppdateraMasken();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void spelRegel();
    void delamaten();
private:
    const int m_cellstorlek=5;
    struct RK{
        RK(int r=0,int k=0): m_r(r) , m_k(k){};
        int m_r;
        int m_k;
    };
    RK m_rkTiktning;
    RK m_rkHuvud;
    std::deque<RK> m_masken;
    std::vector<RK> m_maten;
    void statue();
    bool alive =true;
    unsigned long int size=50;
    unsigned long int matenbitar=2;
};

#endif // SPELPLAN_H
