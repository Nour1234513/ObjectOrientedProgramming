
#include "huvudfonster.h"
#include "ui_huvudfonster.h"


Huvudfonster::Huvudfonster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Huvudfonster)
{
    ui->setupUi(this);
}

Huvudfonster::~Huvudfonster()
{
    delete ui;
}


