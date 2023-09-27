#include "widget_view_settings.h"

#include "ui_widget_view_settings.h"

namespace s21 {

ViewSettings::ViewSettings(QWidget *parent)
    : QWidget(parent), ui_(new Ui::ViewSettings) {
  ui_->setupUi(this);
  connectButtons();
  loadViewSettings();
  ui_->sb_line_width->setValue(conf_.line_width);
  ui_->sb_vertex_size->setValue(conf_.vertex_size);
  if (conf_.line_dashed) {
    ui_->rb_et_dashed->click();
  } else {
    ui_->rb_et_solid->click();
  }
  if (conf_.vertex_style == 1) {
    ui_->rb_vt_ball->click();
  } else if (conf_.vertex_style == 2) {
    ui_->rb_vt_cube->click();
  }
  if (conf_.central_projection) {
    ui_->rb_pt_central->click();
  } else {
    ui_->rb_pt_parallel->click();
  }
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
  connect(ui_->bt_vertex_color, &QPushButton::clicked, this,
          &ViewSettings::buttonVertexColor);
  connect(ui_->sb_line_width, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ViewSettings::spinboxLineWidth);
  connect(ui_->sb_vertex_size, QOverload<int>::of(&QSpinBox::valueChanged), this, &ViewSettings::spinboxVertexSize);
  connect(ui_->rb_et_solid, &QRadioButton::toggled, this, &ViewSettings::toggleSolidLine);
  connect(ui_->rb_et_dashed, &QRadioButton::toggled, this, &ViewSettings::toggleDashedLine);
  connect(ui_->rb_vt_none, &QRadioButton::toggled, this, &ViewSettings::toggleNoneVertex);
  connect(ui_->rb_vt_ball, &QRadioButton::toggled, this, &ViewSettings::toggleBallVertex);
  connect(ui_->rb_vt_cube, &QRadioButton::toggled, this, &ViewSettings::toggleCubeVertex);
  connect(ui_->rb_pt_central, &QRadioButton::toggled, this, &ViewSettings::toggleCentralProjection);
  connect(ui_->rb_pt_parallel, &QRadioButton::toggled, this, &ViewSettings::toggleParallelProjection);

}

void ViewSettings::saveViewSettings() {
  settings.setValue("color_bg", conf_.color_bg);
  settings.setValue("color_line", conf_.color_line);
  settings.setValue("color_vertex", conf_.color_vertex);
  settings.setValue("line_width", conf_.line_width);
  settings.setValue("line_dashed", conf_.line_dashed);
  settings.setValue("vertex_style", conf_.vertex_style);
  settings.setValue("vertex_size", conf_.vertex_size);
  settings.setValue("central_projection", conf_.central_projection);

}

void ViewSettings::loadViewSettings() {
  conf_.color_bg = settings.value("color_bg", QColor(Qt::white)).value<QColor>();
  conf_.color_line = settings.value("color_line", QColor(Qt::black)).value<QColor>();
  conf_.color_vertex = settings.value("color_vertex", QColor(Qt::green)).value<QColor>();
  conf_.line_width = settings.value("line_width", 1).toFloat();
  conf_.line_dashed = settings.value("line_dashed", false).toBool();
  conf_.vertex_style = settings.value("vertex_style", 0).toInt();
  conf_.vertex_size = settings.value("vertex_size", 0).toInt();
  conf_.central_projection = settings.value("central_projection", false).toBool();

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

void ViewSettings::toggleNoneVertex()
{
  conf_.vertex_style = 0;
  emit settingsUpdated();
}

void ViewSettings::toggleBallVertex()
{
  conf_.vertex_style = 1;
  emit settingsUpdated();
}

void ViewSettings::toggleCubeVertex()
{
  conf_.vertex_style = 2;
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

void ViewSettings::buttonVertexColor() {
  QColorDialog dialog(this);
  dialog.setCurrentColor(conf_.color_vertex);
  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    conf_.color_vertex = color;
    emit settingsUpdated();
  }
}

void ViewSettings::spinboxVertexSize() {
  conf_.vertex_size = ui_->sb_vertex_size->value();
  emit settingsUpdated();
}

void ViewSettings::toggleCentralProjection() {
  conf_.central_projection = true;
  emit settingsUpdated();
}

void ViewSettings::toggleParallelProjection() {
  conf_.central_projection = false;
  emit settingsUpdated();
}

}  // namespace s21
