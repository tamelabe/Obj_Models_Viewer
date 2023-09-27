#include "widget_actions.h"

#include "ui_widget_actions.h"

namespace s21 {

Actions::Actions(QWidget *parent) : QWidget(parent), ui_(new Ui::Actions) {
  ui_->setupUi(this);
  connectButtons();
}

Actions::~Actions() { delete ui_; }

void Actions::connectButtons() {
  connect(ui_->bt_load_file, &QPushButton::clicked, this,
          [=]() { loadFile(); });
  connect(ui_->bt_save_bmp, &QPushButton::clicked, this,
          [=]() { saveImage("*.bmp");; });
  connect(ui_->bt_save_jpeg, &QPushButton::clicked, this,
          [=]() { saveImage("*.jpeg"); });
  connect(ui_->bt_rec, &QPushButton::clicked, this, [=]() { loadFile(); });
}

void Actions::loadFile() {
  QString fileQS = QFileDialog::getOpenFileName(
      this, tr("Load Model"), QDir::currentPath(), tr("*.obj"));
  if (fileQS.isEmpty()) return;
  filepath_ = fileQS.toStdString();
  emit resetConfig();
  controller_.setFilepath(filepath_);
  emit fileLoaded();
}

void Actions::saveImage(const QString& format) {
  QString str = QFileDialog::getSaveFileName(this, "Save file as",
                                             QDir::homePath(), format);
  if (str != "") {
    scene_->grabFramebuffer().save(str);
  }
}

void Actions::rec() {}

}  // namespace s21
