#ifndef WIDGET_ACTIONS_H
#define WIDGET_ACTIONS_H

#include <QDir>
#include <QFileDialog>
#include <QWidget>
#include <string>

#include "controller/controller.h"
#include "../render/ogl_render.h"
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

  void connectButtons();
  void saveImage(const QString& format);

 signals:
  void fileLoaded();
  void resetConfig();

 private slots:
  void loadFile();
  void rec();
};

}  // namespace s21

#endif  // WIDGET_ACTIONS_H
