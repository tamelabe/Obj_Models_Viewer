#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets/widget_actions.h"
#include "render/ogl_render.h"
#include "widgets/widget_settings.h"
#include "widgets/widget_info.h"

namespace Ui {
class MainWindow;
}

namespace s21 {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateView();

private:
    Ui::MainWindow *ui_;
};

} // namespace s21

#endif // MAINWINDOW_H

