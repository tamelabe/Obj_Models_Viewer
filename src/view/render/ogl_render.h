#ifndef S21_RENDER_H
#define S21_RENDER_H
#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QWidget>
#include <QSettings>

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

  void setBackgroundColor(QColor color_bg) { color_bg_ = color_bg; };
  QColor getBackgroundColor() { return color_bg_; };
  void setLineColor(QColor color_line) { color_line_ = color_line; };
  QColor getLineColor() { return color_line_; };
  void setVertexColor(QColor color_vertex) { color_vertex_ = color_vertex; };
  QColor getVertexColor() { return color_vertex_; };

  void setSettings(QSettings* settings) { settings_ = settings; };

 signals:
  void saveSettings();

 private:
  QColor color_bg_;
  QColor color_line_;
  QColor color_vertex_;

  QSettings* settings_;

  const s21::GLObject* object_ = nullptr;
  s21::Controller& controller_ = s21::Controller::getInstance();

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void drawObject();
};

}  // namespace s21

#endif  // S21_RENDER_H
