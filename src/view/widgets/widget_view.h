#ifndef WIDGET_VIEW_H
#define WIDGET_VIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private:
    Ui::View *ui_;
};
#endif // WIDGET_VIEW_H
