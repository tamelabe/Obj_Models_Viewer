#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  this->setFixedSize(1680, 1070);
  connect(ui_->w_actions, &Actions::fileLoaded, this, [=]() {
    updateView();
    ui_->w_settings->setDefault();
  });
  connect(ui_->w_settings, &Settings::settingsUpdated, this,
          &MainWindow::updateView);
  connect(ui_->w_actions, &Actions::resetConfig, this,[=]() {
      ui_->w_settings->setDefault();
  });
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::updateView() {
  ui_->w_scene->updateObject();
  ui_->w_info->updateInfo();
}

void MainWindow::on_bt_bg_color_clicked() {
    QColor BG_color = QColorDialog::getColor();
    ui_->w_scene->setRedBG(static_cast<float>(BG_color.red()));
    ui_->w_scene->setGreenBG(static_cast<float>(BG_color.green()));
    ui_->w_scene->setBlueBG(static_cast<float>(BG_color.blue()));
    ui_->w_scene->setAlphaBG(static_cast<float>(BG_color.alpha()));
}

}  // namespace s21
