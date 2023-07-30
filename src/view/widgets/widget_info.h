#ifndef WIDGET_INFO_H
#define WIDGET_INFO_H

#include <QWidget>
#include "../../controller/controller.h"

namespace Ui {
class Info;
}

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();

private:
    Ui::Info *ui;
    s21::Controller& controller_ = s21::Controller::getInstance();
};

#endif // WIDGET_INFO_H
