#include "widget_view_settings.h"

#include "ui_widget_view_settings.h"

namespace s21 {

ViewSettings::ViewSettings(QWidget *parent)
    : QWidget(parent), ui_(new Ui::ViewSettings) {
  ui_->setupUi(this);
  connectButtons();
}

ViewSettings::~ViewSettings() { delete ui_; }

void ViewSettings::connectButtons() {
  connect(ui_->bt_bg_color, &QPushButton::clicked, this,
          &ViewSettings::buttonBackgroundColor);
  connect(ui_->bt_line_color, &QPushButton::clicked, this,
            &ViewSettings::buttonLineColor);
}

void ViewSettings::buttonBackgroundColor() {
  QColorDialog dialog(this);
  dialog.setCurrentColor(conf_.color_bg_);
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    conf_.color_bg_ = color;
    emit settingsUpdated();
  }
}

void ViewSettings::buttonLineColor() {
  QColorDialog dialog(this);
  dialog.setCurrentColor(conf_.color_line_);
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    conf_.color_line_ = color;
    emit settingsUpdated();
  }
}

}  // namespace s21
