#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  setFixedSize(1680, 1070);
  setWindowTitle("3D Viewer");
  setupWidgets();
  connectSlots();
}

void MainWindow::connectSlots() {
  connect(w_actions, &Actions::fileLoaded, this, [=]() {
    updateView();
    w_settings->setDefault();
  });
  connect(w_settings, &Settings::settingsUpdated, this,
          &MainWindow::updateView);
  connect(w_view_settings, &ViewSettings::settingsUpdated, this,
          &MainWindow::updateView);
  connect(w_actions, &Actions::resetConfig, this,
          [=]() { w_settings->setDefault(); });
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
  w_scene->updateObject();
  w_info->updateInfo();
}

void MainWindow::setupWidgets() {
  my_central_widget = new QWidget(this);
  my_central_widget->setObjectName(QString::fromUtf8("my_central_widget"));
  setCentralWidget(my_central_widget);

  w_settings = new s21::Settings(my_central_widget);
  w_settings->setObjectName(QString::fromUtf8("w_settings"));
  w_settings->setGeometry(QRect(1410, 549, 260, 441));

  w_info = new s21::Info(my_central_widget);
  w_info->setObjectName(QString::fromUtf8("w_info"));
  w_info->setGeometry(QRect(1410, 10, 260, 100));

  w_actions = new s21::Actions(my_central_widget);
  w_actions->setObjectName(QString::fromUtf8("w_actions"));
  w_actions->setGeometry(QRect(10, 5, 515, 30));

  w_view_settings = new s21::ViewSettings(my_central_widget);
  w_view_settings->setObjectName(QString::fromUtf8("w_view_settings"));
  w_view_settings->setGeometry(QRect(1410, 110, 261, 431));

  w_scene = new s21::OpenGLMod(my_central_widget);
  w_scene->setObjectName(QString::fromUtf8("w_scene"));
  w_scene->setGeometry(QRect(10, 40, 1380, 1000));
  w_scene->setPaintConfig(w_view_settings->getPaintConfig());
}

}  // namespace s21
