#include "widget_actions.h"

#include "ui_widget_actions.h"

namespace s21 {

Actions::Actions(QWidget *parent) : QWidget(parent), ui_(new Ui::Actions) {
  ui_->setupUi(this);
  connectButtons();
  record_time_ = new QTimer(this);
  connect(record_time_, &QTimer::timeout, this, &Actions::recordGIF);
}

Actions::~Actions() { delete ui_; }

void Actions::connectButtons() {
  connect(ui_->bt_load_file, &QPushButton::clicked, this,
          [=]() { loadFile(); });
  connect(ui_->bt_save_bmp, &QPushButton::clicked, this,
          [=]() { saveImage("*.bmp");; });
  connect(ui_->bt_save_jpeg, &QPushButton::clicked, this,
          [=]() { saveImage("*.jpeg"); });
  connect(ui_->bt_rec, &QPushButton::clicked, this, [=]() { startGIFRecord(); });

}

void Actions::loadFile() {
  QString fileQS = QFileDialog::getOpenFileName(
      this, tr("Load Model"), QDir::currentPath(), tr("*.obj"));
  if (fileQS.isEmpty()) return;
  filepath_ = fileQS.toStdString();
  emit resetConfig();
  controller_.setFilepath(filepath_);
  emit fileLoaded();
}

void Actions::saveImage(const QString& format) {
  QString str = QFileDialog::getSaveFileName(this, "Save file as",
                                             QDir::homePath(), format);
  if (str != "") {
    scene_->grabFramebuffer().save(str);
  }
}

void Actions::startGIFRecord() {
  if (!is_record_) {
    scene_->resize(640, 480);
    scene_->move(450, 260);
    is_record_ = true;
    record_time_->start(100);
  }
}

void Actions::recordGIF() {
  if (is_record_ && time_ <= 5.0) {
    gif_.push_back(scene_->grab().toImage());
    time_ += 0.1;
    ui_->bt_rec->setText("RECORDING...");
  } else {
    ui_->bt_rec->setText("REC GIF");
    scene_->move(10 , 40);
    scene_->resize(1380, 1000);
    record_time_->stop();
    saveGIF();
  }
}

void Actions::saveGIF() {
  QString str = QFileDialog::getSaveFileName(
    this, tr("Save GIF"), QDir::homePath(), tr("GIF (*.gif)"));
  if (str != "") {
    QGifImage current_gif;
    current_gif.setDefaultTransparentColor(Qt::black);
    current_gif.setDefaultDelay(100);

    for (QVector<QImage>::Iterator frame = gif_.begin(); frame != gif_.end();
         frame++) {
      current_gif.addFrame(*frame);
    }
    current_gif.save(str);
    gif_.clear();
  }
  time_ = 0.0;
  is_record_ = false;
}


}  // namespace s21
