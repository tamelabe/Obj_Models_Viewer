#include "widget_info.h"
#include "ui_widget_info.h"

namespace s21 {

Info::Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}

} // namespace s21
