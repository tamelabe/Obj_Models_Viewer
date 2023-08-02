#ifndef SPINBOX_SLIDER_H
#define SPINBOX_SLIDER_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>

namespace Ui {
class SpinboxSlider;
}

class SpinboxSlider : public QWidget
{
    Q_OBJECT

public:
    explicit SpinboxSlider(QWidget *parent = nullptr);
    ~SpinboxSlider();

private:
    Ui::SpinboxSlider *ui;
    QSpinBox *spin_box_;
    QSlider *slider_;
};

#endif // SPINBOX_SLIDER_H
