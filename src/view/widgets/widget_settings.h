#ifndef WIDGET_SETTINGS_H
#define WIDGET_SETTINGS_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "../../helpers/data_objects.h"
#include "../../controller/controller.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui_;
    s21::Controller& controller_ = s21::Controller::getInstance();
    s21::TransformParams tp_;
    s21::ModelStateData model_state_;

    void connectButtons();
    int updateState(char pos_type, char axis, int value);

    void movement(char pos_type, int value, char axis = 0);



signals:
    void settingsUpdated();

};

#endif // WIDGET_SETTINGS_H
