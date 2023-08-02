#ifndef WIDGET_ACTIONS_H
#define WIDGET_ACTIONS_H

#include "controller/controller.h"
#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <string>

//#include "../../controller/controller.h"

namespace Ui {
class Actions;
}

namespace s21 {

class Actions : public QWidget
{
    Q_OBJECT

public:
    explicit Actions(QWidget *parent = nullptr);
    ~Actions();

private:
    Ui::Actions *ui_;
    std::string filepath_;
    s21::Controller& controller_ = s21::Controller::getInstance();

    void connectButtons();
    void savePic(char type);

signals:
    void fileLoaded();


private slots:
    void loadFile();
    void rec();
};

} // namespace s21

#endif // WIDGET_ACTIONS_H
