#ifndef S21_RENDER_H
#define S21_RENDER_H
#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QGuiApplication>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QPoint>
#include <QPointerEvent>
#include <QTime>
#include <QWidget>

#include <QMessageBox>

#include "../../helpers/data_objects.h"
#include "../../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class OpenGLMod;
}
QT_END_NAMESPACE

class OpenGLMod : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLMod(QWidget *parent = nullptr) :
        QOpenGLWidget(parent) {}
  ~OpenGLMod() { }

    void updateObject() {
        object_ = controller_.getObject();
        std::cout << "OBJ LOADED" << object_.facets.size() << '\n';
        update();
    }

 private:
  s21::GLObject object_;
  s21::Controller& controller_ = s21::Controller::getInstance();
  QOpenGLBuffer m_arrayBuffer;
  QOpenGLBuffer m_indexBuffer;

  void initializeGL() override {
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_CULL_FACE);
  }
  void resizeGL(int w, int h) override {
      glViewport(0, 0, w, h);
  }
  void paintGL() override {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      int size = 3;
      float far = 100;
      float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
      float heapHeight = size / (2 * tan(fov / 2));

      glFrustum(-1, 1, -1, 1, heapHeight, far);
//      glClearColor(background_red, background_green, background_blue, background_alpha);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(0, 0, -3 * heapHeight);
      drawObject();
  }

  void drawObject() {
          glPointSize(5);

          glVertexPointer(3, GL_DOUBLE, 0, object_.vertices.data());
          glEnableClientState(GL_VERTEX_ARRAY);
          glLineWidth(2);

          glDisable(GL_POINT_SMOOTH);
          glEnable(GL_POINT_SPRITE);

//          glColor4d(edge_red, edge_green, edge_blue, edge_alpha);

          glDisable(GL_LINE_STIPPLE);

          glDrawElements(GL_LINES, object_.facets.size(), GL_UNSIGNED_INT, object_.facets.data());

          glDisableClientState(GL_VERTEX_ARRAY);

  }

//  void drawLine() {
//      glVertexPointer(3, GL_DOUBLE, 0, object_.vertices.data());
//      glEnableClientState(GL_VERTEX_ARRAY);
//      glDrawElements(GL_LINES, object_.facets.size(), GL_UNSIGNED_INT, object_.facets.data());
//      glDisableClientState(GL_VERTEX_ARRAY);
//  }


//  void drawLine() {
//      m_arrayBuffer.create();
//      m_arrayBuffer.bind();
//      m_arrayBuffer.allocate(object_.vertices.data(),
//                             object_.vertices.size() * sizeof(double));
//      m_arrayBuffer.release();

//      m_indexBuffer.create();
//      m_indexBuffer.bind();
//      m_indexBuffer.allocate(object_.facets.data(), object_.facets.size() * sizeof(unsigned));
//      m_indexBuffer.release();
//  }
//  void setProject();
//  void setLineMod();
//  void setLineSize();
//  void setApexMod();
//  void setApexSize();

};

#endif  // S21_RENDER_H
