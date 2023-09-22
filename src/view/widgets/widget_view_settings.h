#ifndef WIDGET_VIEW_SETTINGS_H
#define WIDGET_VIEW_SETTINGS_H

#include <QColorDialog>
#include <QSettings>
#include <QVariant>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

#include "helpers/data_objects.h"

namespace Ui {
class ViewSettings;
}

namespace s21 {

class ViewSettings : public QWidget {
  Q_OBJECT

 public:
  explicit ViewSettings(QWidget *parent = nullptr);
  ~ViewSettings();

  void saveViewSettings();
  void loadViewSettings();
  PaintConfig *getPaintConfig() { return &conf_; };

 public slots:
  void buttonBackgroundColor();
  void buttonLineColor();
  void spinboxLineWidth();
  void toggleSolidLine();
  void toggleDashedLine();

 signals:
  void settingsUpdated();

 private:
  Ui::ViewSettings *ui_;
  PaintConfig conf_;
  QSettings settings;

  void connectButtons();
};

}  // namespace s21

#endif  // WIDGET_VIEW_SETTINGS_H
