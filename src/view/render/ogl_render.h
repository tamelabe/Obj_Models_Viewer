#ifndef S21_RENDER_H
#define S21_RENDER_H
#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QGuiApplication>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QPoint>
#include <QPointerEvent>
#include <QTime>
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

  void updateObject() {
    object_ = &controller_.getObject();
    if (object_) update();
  }

 private:
  const s21::GLObject* object_ = nullptr;
  s21::Controller& controller_ = s21::Controller::getInstance();
  QOpenGLBuffer m_arrayBuffer;
  QOpenGLBuffer m_indexBuffer;

  void initializeGL() override {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
  }
  void resizeGL(int w, int h) override {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspected_widget_width = w / 120;
    float aspected_widget_height = h / 120;
    float widget_left = -aspected_widget_width / 2;
    float widget_right = aspected_widget_width / 2;
    float widget_bottom = -aspected_widget_height / 2;
    float widget_top = aspected_widget_height / 2;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(widget_left, widget_right, widget_bottom, widget_top, -100, 100);
  }
  void paintGL() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    int size = 3;
    //      float far = 100;
    float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
    float heapHeight = size / (2 * tan(fov / 2));

    //      glFrustum(-1, 1, -1, 1, heapHeight, far);
    //      glClearColor(background_red, background_green, background_blue,
    //      background_alpha);

    glLoadIdentity();
    glTranslatef(0, 0, -3 * heapHeight);
    drawObject();
  }

  void drawObject() {
    if (object_ == nullptr) return;
    glPointSize(5);

    glVertexPointer(3, GL_FLOAT, 0, object_->vertices.data());
    glEnableClientState(GL_VERTEX_ARRAY);
    glLineWidth(2);

    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SPRITE);

    //          glColor4d(edge_red, edge_green, edge_blue, edge_alpha);

    glDisable(GL_LINE_STIPPLE);

    glDrawElements(GL_LINES, object_->facets.size(), GL_UNSIGNED_INT,
                   object_->facets.data());

    glDisableClientState(GL_VERTEX_ARRAY);
  }
};

}  // namespace s21

#endif  // S21_RENDER_H
