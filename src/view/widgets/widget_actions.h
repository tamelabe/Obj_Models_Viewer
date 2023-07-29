#ifndef WIDGET_ACTIONS_H
#define WIDGET_ACTIONS_H

#include <QWidget>

namespace Ui {
class Actions;
}

class Actions : public QWidget
{
    Q_OBJECT

public:
    explicit Actions(QWidget *parent = nullptr);
    ~Actions();

private:
    Ui::Actions *ui;
};

#endif // WIDGET_ACTIONS_H
