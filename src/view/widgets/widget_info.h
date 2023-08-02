#ifndef WIDGET_INFO_H
#define WIDGET_INFO_H

#include <QWidget>
#include "../../controller/controller.h"

namespace Ui {
class Info;
}

namespace s21 {

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    void updateInfo();
    ~Info();

private:
    Ui::Info *ui_;
    Controller& controller_ = s21::Controller::getInstance();
    const GLObject* object_ = nullptr;
    std::string filepath_{};
};

} // namespace s21

#endif // WIDGET_INFO_H
