#include "widget_view_settings.h"

#include "ui_widget_view_settings.h"

namespace s21 {

ViewSettings::ViewSettings(QWidget *parent)
    : QWidget(parent), ui_(new Ui::ViewSettings) {
  ui_->setupUi(this);
  connectButtons();
  loadViewSettings();
  ui_->sb_line_width->setValue(conf_.line_width);

}

ViewSettings::~ViewSettings() {
  saveViewSettings();
  delete ui_;
}

void ViewSettings::connectButtons() {
  connect(ui_->bt_bg_color, &QPushButton::clicked, this,
          &ViewSettings::buttonBackgroundColor);
  connect(ui_->bt_line_color, &QPushButton::clicked, this,
          &ViewSettings::buttonLineColor);
  connect(ui_->sb_line_width, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ViewSettings::spinboxLineWidth);
  connect(ui_->rb_et_solid, &QRadioButton::toggled, this, &ViewSettings::toggleSolidLine);
  connect(ui_->rb_et_dashed, &QRadioButton::toggled, this, &ViewSettings::toggleDashedLine);

}



void ViewSettings::saveViewSettings() {
  settings.setValue("background_color", conf_.color_bg);
  settings.setValue("line_color", conf_.color_line);
  settings.setValue("line_width", conf_.line_width);
  settings.setValue("line_style", static_cast<int>(conf_.line_style));

}

void ViewSettings::loadViewSettings() {
  conf_.color_bg = settings.value("background_color", QColor(Qt::white)).value<QColor>();
  conf_.color_line = settings.value("line_color", QColor(Qt::black )).value<QColor>();
  conf_.line_width = settings.value("line_width", 1).toFloat();
  conf_.line_style = static_cast<Qt::PenStyle>(settings.value("line_style", static_cast<int>(Qt::SolidLine)).toInt());

}

void ViewSettings::spinboxLineWidth() {
  conf_.line_width = ui_->sb_line_width->value();
  emit settingsUpdated();
}

void ViewSettings::toggleSolidLine()
{
  conf_.line_dashed = false;
  emit settingsUpdated();
}

void ViewSettings::toggleDashedLine()
{
  conf_.line_dashed = true;
  emit settingsUpdated();
}

void ViewSettings::buttonBackgroundColor() {
  QColorDialog dialog(this);
  dialog.setCurrentColor(conf_.color_bg);
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    conf_.color_bg = color;
    emit settingsUpdated();
  }
}

void ViewSettings::buttonLineColor() {
  QColorDialog dialog(this);
  dialog.setCurrentColor(conf_.color_line);
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    conf_.color_line = color;
    emit settingsUpdated();
  }
}

}  // namespace s21
