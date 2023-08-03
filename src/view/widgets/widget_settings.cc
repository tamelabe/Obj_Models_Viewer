#include "widget_settings.h"

#include <iostream>

#include "ui_widget_settings.h"

namespace s21 {

Settings::Settings(QWidget *parent) : QWidget(parent), ui_(new Ui::Settings) {
  ui_->setupUi(this);
  connectButtons();
}

Settings::~Settings() { delete ui_; }

void Settings::connectButtons() {
  connect(ui_->sb_rotate_x, &QSpinBox::valueChanged, this, [=]() {
    movement('r', ui_->sb_rotate_x->value(), 'x');
    ui_->sl_rotation_x->setValue(ui_->sb_rotate_x->value());
  });
  connect(ui_->sb_rotate_y, &QSpinBox::valueChanged, this, [=]() {
    movement('r', ui_->sb_rotate_y->value(), 'y');
    ui_->sl_rotation_y->setValue(ui_->sb_rotate_y->value());
  });
  connect(ui_->sb_rotate_z, &QSpinBox::valueChanged, this, [=]() {
    movement('r', ui_->sb_rotate_z->value(), 'z');
    ui_->sl_rotation_z->setValue(ui_->sb_rotate_z->value());
  });
  connect(ui_->sb_moving_x, &QSpinBox::valueChanged, this, [=]() {
    movement('m', ui_->sb_moving_x->value(), 'x');
    ui_->sl_moving_x->setValue(ui_->sb_moving_x->value());
  });
  connect(ui_->sb_moving_y, &QSpinBox::valueChanged, this, [=]() {
    movement('m', ui_->sb_moving_y->value(), 'y');
    ui_->sl_moving_y->setValue(ui_->sb_moving_y->value());
  });
  connect(ui_->sb_moving_z, &QSpinBox::valueChanged, this, [=]() {
    movement('m', ui_->sb_moving_z->value(), 'z');
    ui_->sl_moving_z->setValue(ui_->sb_moving_z->value());
  });
  connect(ui_->sb_scale, &QSpinBox::valueChanged, this, [=]() {
    movement('s', ui_->sb_scale->value());
    ui_->sl_scale->setValue(ui_->sb_scale->value());
  });
  connect(ui_->sl_rotation_x, &QSlider::valueChanged, this, [=]() {
    movement('r', ui_->sl_rotation_x->value(), 'x');
    ui_->sb_rotate_x->setValue(ui_->sl_rotation_x->value());
  });
  connect(ui_->sl_rotation_y, &QSlider::valueChanged, this, [=]() {
    movement('r', ui_->sl_rotation_y->value(), 'y');
    ui_->sb_rotate_y->setValue(ui_->sl_rotation_y->value());
  });
  connect(ui_->sl_rotation_z, &QSlider::valueChanged, this, [=]() {
    movement('r', ui_->sl_rotation_z->value(), 'z');
    ui_->sb_rotate_z->setValue(ui_->sl_rotation_z->value());
  });
  connect(ui_->sl_moving_x, &QSlider::valueChanged, this, [=]() {
    movement('m', ui_->sl_moving_x->value(), 'x');
    ui_->sb_moving_x->setValue(ui_->sl_moving_x->value());
  });
  connect(ui_->sl_moving_y, &QSlider::valueChanged, this, [=]() {
    movement('m', ui_->sl_moving_y->value(), 'y');
    ui_->sb_moving_y->setValue(ui_->sl_moving_y->value());
  });
  connect(ui_->sl_moving_z, &QSlider::valueChanged, this, [=]() {
    movement('m', ui_->sl_moving_z->value(), 'z');
    ui_->sb_moving_z->setValue(ui_->sl_moving_z->value());
  });
  connect(ui_->sl_scale, &QSlider::valueChanged, this, [=]() {
    movement('s', ui_->sl_scale->value());
    ui_->sb_scale->setValue(ui_->sl_scale->value());
  });
}

void Settings::setDefault() {
  ui_->sb_moving_x->setValue(0);
  ui_->sb_moving_y->setValue(0);
  ui_->sb_moving_z->setValue(0);
  ui_->sb_rotate_x->setValue(0);
  ui_->sb_rotate_y->setValue(0);
  ui_->sb_rotate_z->setValue(0);
  ui_->sb_scale->setValue(0);
}

void Settings::movement(char pos_type, int value, char axis) {
  if (controller_.getObject().facets.empty() ||
      controller_.getObject().vertices.empty())
    return;
  tp_.pos_type = pos_type;
  tp_.axis = axis;
  int prev_value = updateState(pos_type, axis, value);
  tp_.value = value - prev_value;
  controller_.changeObjectState(tp_);
  emit settingsUpdated();
}

int Settings::updateState(char pos_type, char axis, int value) {
  int prev_value{};
  if (pos_type == 'r') {
    if (axis == 'x') {
      prev_value = model_state_.rotate.x;
      model_state_.rotate.x = value;

    } else if (axis == 'y') {
      prev_value = model_state_.rotate.y;
      model_state_.rotate.y = value;
    } else if (axis == 'z') {
      prev_value = model_state_.rotate.y;
      model_state_.rotate.y = value;
    }
  } else if (pos_type == 'm') {
    if (axis == 'x') {
      prev_value = model_state_.move.x;
      model_state_.move.x = value;
    } else if (axis == 'y') {
      prev_value = model_state_.move.y;
      model_state_.move.y = value;
    } else if (axis == 'z') {
      prev_value = model_state_.move.z;
      model_state_.move.z = value;
    }
  } else if (pos_type == 's') {
    prev_value = model_state_.scale;
    model_state_.scale = value;
  }
  return prev_value;
}

}  // namespace s21
