#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  this->setFixedSize(1680, 1070);
  connect(ui_->w_actions, &Actions::fileLoaded, this, &MainWindow::updateView);
  connect(ui_->w_settings, &Settings::settingsUpdated, this,
          &MainWindow::updateView);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::updateView() {
  ui_->w_scene->updateObject();
  ui_->w_info->updateInfo();
}

}  // namespace s21
