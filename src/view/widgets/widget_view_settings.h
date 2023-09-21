#ifndef WIDGET_VIEW_SETTINGS_H
#define WIDGET_VIEW_SETTINGS_H

#include <QSlider>
#include <QSpinBox>
#include <QWidget>
#include <QColorDialog>

#include "../mainwindow.h"

namespace Ui {
class ViewSettings;
}

namespace s21 {

class ViewSettings : public QWidget {
  Q_OBJECT

 public:
  ViewSettings(QWidget *parent = nullptr/*, MainWindow *window = nullptr*/);
  ~ViewSettings();

  QSettings* getSettings() {
      return &qSettings_;
  }

 private:
  Ui::ViewSettings *ui_;
  MainWindow *main_window_;
  QSettings qSettings_{};

  void connectButtons();

 signals:
  void settingsUpdated();
};

}  // namespace s21

#endif  // WIDGET_VIEW_SETTINGS_H

