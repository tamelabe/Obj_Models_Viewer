#ifndef WIDGET_ACTIONS_H
#define WIDGET_ACTIONS_H

#include <QDir>
#include <QFileDialog>
#include <QImage>
#include <QTimer>
#include <QVector>
#include <QWidget>
#include <string>

#include "../../resources/GIFCreation/gifImage/qgifimage.h"
#include "../render/ogl_render.h"
#include "controller/controller.h"
// #include "../../controller/controller.h"

namespace Ui {
class Actions;
}

namespace s21 {

class Actions : public QWidget {
  Q_OBJECT

 public:
  explicit Actions(QWidget *parent = nullptr);
  ~Actions();

  void setOpenGLMod(OpenGLMod *scene) { scene_ = scene; };

 private:
  Ui::Actions *ui_;
  std::string filepath_;
  s21::Controller &controller_ = s21::Controller::getInstance();
  s21::OpenGLMod *scene_;
  bool is_record_{};
  QVector<QImage> gif_;
  QTimer *record_time_;
  float time_{};

  void connectButtons();

 signals:
  void fileLoaded();
  void resetConfig();

 private slots:
  void loadFile();
  void saveImage(const QString &format);
  void startGIFRecord();
  void recordGIF();
  void saveGIF();
};

}  // namespace s21

#endif  // WIDGET_ACTIONS_H
