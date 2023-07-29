#include "widget_view.h"
#include "./ui_widget_view.h"
#include "ui_widget_info.h"

View::View(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::View)
{
    ui_->setupUi(this);
}

View::~View()
{
    delete ui_;
}
