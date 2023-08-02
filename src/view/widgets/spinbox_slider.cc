#include "spinbox_slider.h"
#include "ui_spinbox_slider.h"

SpinboxSlider::SpinboxSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpinboxSlider),
    spin_box_(new QSpinBox(this)),
    slider_(new QSlider(Qt::Horizontal, this))
{
    ui->setupUi(this);
    spin_box_->setRange(0, 100);
    slider_->setRange(0, 100);
    connect(spin_box_, QOverload<int>::of(&QSpinBox::valueChanged), slider_, &QSlider::setValue);
    connect(slider_, &QSlider::valueChanged, spin_box_, &QSpinBox::setValue);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(spin_box_);
    layout->addWidget(slider_);
    setLayout(layout);
}

SpinboxSlider::~SpinboxSlider()
{
    delete ui;
}
