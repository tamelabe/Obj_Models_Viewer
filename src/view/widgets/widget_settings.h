#ifndef WIDGET_SETTINGS_H
#define WIDGET_SETTINGS_H

#include <QColorDialog>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

#include "../../controller/controller.h"
#include "../../helpers/data_objects.h"

namespace Ui {
class Settings;
}

namespace s21 {

class Settings : public QWidget {
  Q_OBJECT

 public:
  Settings(QWidget *parent = nullptr);
  ~Settings();
  void setDefault();
  const s21::ModelStateData *getModelState() const { return &model_state_; }

 private:
  Ui::Settings *ui_;
  s21::Controller &controller_ = s21::Controller::getInstance();
  s21::TransformParams tp_;
  s21::ModelStateData model_state_;

  void connectButtons();
  int updateState(char pos_type, char axis, int value);

  void movement(char pos_type, int value, char axis = 0);

 signals:
  void settingsUpdated();
};

}  // namespace s21

#endif  // WIDGET_SETTINGS_H
