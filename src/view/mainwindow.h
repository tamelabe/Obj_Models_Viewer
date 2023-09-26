#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QSettings>

#include "render/ogl_render.h"
#include "ui_mainwindow.h"
#include "widgets/widget_actions.h"
#include "widgets/widget_info.h"
#include "widgets/widget_settings.h"
#include "widgets/widget_view_settings.h"

namespace Ui {
class MainWindow;
}

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  QWidget *my_central_widget;
  s21::Settings *w_settings;
  s21::Info *w_info;
  s21::Actions *w_actions;
  s21::OpenGLMod *w_scene;
  s21::ViewSettings *w_view_settings;

  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void keyPressEvent(QKeyEvent *event) override;

 private slots:
  void updateView();

 private:
  Ui::MainWindow *ui_;
  int window_widht = 1680;
  int window_height = 1070;
  void setupWidgets();
  void connectSlots();
};

}  // namespace s21

#endif  // MAINWINDOW_H
