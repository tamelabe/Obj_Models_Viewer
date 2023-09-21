#include "widget_view_settings.h"

#include "ui_widget_view_settings.h"

namespace s21 {

    ViewSettings::ViewSettings(QWidget *parent/*, MainWindow *window*/) : QWidget(parent), ui_(new Ui::ViewSettings)/*, w_(window)*/ {
  ui_->setupUi(this);
  main_window_ = dynamic_cast<s21::MainWindow *>(qApp->findChild<QWidget *>("MainWindow"));

    connectButtons();
}

    ViewSettings::~ViewSettings() { delete ui_; }

void ViewSettings::connectButtons() {
  connect(ui_->bt_bg_color, SIGNAL(clicked()), main_window_, SLOT(buttonBackgroudColor()));
}

}  // namespace s21
