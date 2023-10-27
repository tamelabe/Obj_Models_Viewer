#ifndef S21_RENDER_H
#define S21_RENDER_H
#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QSettings>
#include <QWidget>
#include <QtGui/QMatrix4x4>
#include <iostream>

#include "../../controller/controller.h"
#include "../../helpers/view_data_objects.h"
#include "../../view/widgets/widget_settings.h"

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

  void setPaintConfig(PaintConfig* conf) { conf_ = conf; };
  void updateObject();

 signals:
  void saveSettings();

 private:
  PaintConfig* conf_;
  const s21::GLObject* object_ = nullptr;
  s21::Controller& controller_ = s21::Controller::getInstance();

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
};

}  // namespace s21

#endif  // S21_RENDER_H
