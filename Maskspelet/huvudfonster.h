
#ifndef HUVUDFONSTER_H
#define HUVUDFONSTER_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class Huvudfonster; }
QT_END_NAMESPACE

class Huvudfonster : public QMainWindow

{
    Q_OBJECT

public:
    Huvudfonster(QWidget *parent = nullptr);
    ~Huvudfonster();

private:
    Ui::Huvudfonster *ui;
};

#endif // HUVUDFONSTER_H
