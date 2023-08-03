#include "widget_info.h"

#include "ui_widget_info.h"

namespace s21 {

Info::Info(QWidget *parent) : QWidget(parent), ui_(new Ui::Info) {
  ui_->setupUi(this);
  object_ = &controller_.getObject();
}

Info::~Info() { delete ui_; }

void Info::updateInfo() {
  ui_->lb_filename->setText(QString::fromStdString(object_->getFile()));
  ui_->lb_edges->setText(QString::number(object_->getEdges()));
  ui_->lb_vertices->setText(QString::number(object_->getVertices()));
}

}  // namespace s21
