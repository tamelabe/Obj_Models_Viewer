#include "widget_actions.h"
#include "ui_widget_actions.h"

Actions::Actions(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Actions)
{
    ui_->setupUi(this);
}

Actions::~Actions()
{
    delete ui_;
}

void Actions::connectButtons() {

}
