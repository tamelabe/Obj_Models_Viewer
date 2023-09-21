#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  this->setFixedSize(1680, 1070);
  this->setWindowTitle("3D Viewer");
  ui_->w_scene->setSettings(ui_->w_view_settings->getSettings());
  connect(ui_->w_actions, &Actions::fileLoaded, this, [=]() {
      updateView();
      ui_->w_settings->setDefault();
//    ui_->w_view_settings->setDefault();   ПОТОМ!!!
  });
  connect(ui_->w_settings, &Settings::settingsUpdated, this,
          &MainWindow::updateView);
  connect(ui_->w_actions, &Actions::resetConfig, this,[=]() {
      ui_->w_settings->setDefault();
  });
//    loadSettings();
}

MainWindow::~MainWindow() { delete ui_; }

void s21::MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_W) {
    close();
  } else {
    QMainWindow::keyPressEvent(event);
  }
}


void MainWindow::updateView() {
  ui_->w_scene->updateObject();
  ui_->w_info->updateInfo();
}

void MainWindow::buttonBackgroudColor() {
  QColorDialog dialog(this);
  dialog.setWindowTitle("Выберите цвет заднего фона");
  dialog.setCurrentColor(ui_->w_scene->getBackgroundColor());
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    ui_->w_scene->setBackgroundColor(color);
    ui_->w_scene->update();
  }
}

//void MainWindow::on_bt_line_color_clicked() {
//  QColorDialog dialog(this);
//  dialog.setWindowTitle("Выберите цвет ребер");
//  dialog.setCurrentColor(ui_->w_scene->getLineColor());
//  if (dialog.exec() == QDialog::Accepted) {
//    QColor color = dialog.selectedColor();
//    ui_->w_scene->setLineColor(color);
//    ui_->w_scene->update();
//  }
//}
//
//void MainWindow::on_bt_vertex_color_clicked() {
//  QColorDialog dialog(this);
//  dialog.setWindowTitle("Выберите цвет вершин");
//  dialog.setCurrentColor(ui_->w_scene->getVertexColor());
//  if (dialog.exec() == QDialog::Accepted) {
//    QColor color = dialog.selectedColor();
//    ui_->w_scene->setLineColor(color);
//    ui_->w_scene->update();
//  }
//}

}  // namespace s21
