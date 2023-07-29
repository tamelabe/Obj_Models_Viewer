#include "widget_actions.h"
#include "ui_widget_actions.h"

Actions::Actions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Actions)
{
    ui->setupUi(this);
}

Actions::~Actions()
{
    delete ui;
}
