#ifndef S21_RENDER_H
#define S21_RENDER_H
#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QWidget>

#include "../../controller/controller.h"
#include "../../helpers/data_objects.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class OpenGLMod;
}
QT_END_NAMESPACE

namespace s21 {

class OpenGLMod : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLMod(QWidget* parent = nullptr) : QOpenGLWidget(parent) {}
  ~OpenGLMod() {}

  void updateObject();
  void setRedBG(float red_bg) { red_bg_ = red_bg; };
  void setGreenBG(float green_bg) { green_bg_ = green_bg; };
  void setBlueBG(float blue_bg) { blue_bg_ = blue_bg; };
  void setAlphaBG(float alpha_bg) { alpha_bg_ = alpha_bg; };

 private:
  float red_bg_, green_bg_, blue_bg_, alpha_bg_;

  const s21::GLObject* object_ = nullptr;
  s21::Controller& controller_ = s21::Controller::getInstance();

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void drawObject();
};

}  // namespace s21

#endif  // S21_RENDER_H
