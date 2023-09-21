#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSettings>

#include "render/ogl_render.h"
#include "widgets/widget_actions.h"
#include "widgets/widget_info.h"
#include "widgets/widget_settings.h"
#include "widgets/widget_view_settings.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void keyPressEvent(QKeyEvent *event) override;
    QColor getBackgroundColor() { return ui_->w_scene->getBackgroundColor(); };
    void setBackgroundColor(QColor color_bg) { ui_->w_scene->setBackgroundColor(color_bg); };
//    const MainWindow *getUi() { return reinterpret_cast<const MainWindow *>(ui_); };


    public slots:
        void buttonBackgroudColor();


 private slots:
  void updateView();
  void on_bt_line_color_clicked();
  void on_bt_vertex_color_clicked();

 private:
  Ui::MainWindow *ui_;
};

}  // namespace s21

#endif  // MAINWINDOW_H
