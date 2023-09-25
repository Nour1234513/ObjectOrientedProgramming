
#include "huvudfonster.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Huvudfonster w;
    w.show();
    return a.exec();
}
