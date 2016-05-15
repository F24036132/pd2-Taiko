#include "explain.h"
#include "ui_explain.h"

Explain::Explain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Explain)
{
    ui->setupUi(this);
    setFixedSize(480,320);
    setWindowTitle("Help");
}

Explain::~Explain()
{
    delete ui;
}
