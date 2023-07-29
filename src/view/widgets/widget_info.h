#ifndef WIDGET_INFO_H
#define WIDGET_INFO_H

#include <QWidget>

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
};

#endif // WIDGET_INFO_H
