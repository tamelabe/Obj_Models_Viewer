#ifndef S21_RENDER_H
#define S21_RENDER_H

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QGuiApplication>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QPoint>
#include <QPointerEvent>
#include <QTime>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class OpenGLMod;
}
QT_END_NAMESPACE

class OpenGLMod : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLMod(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}
  ~OpenGLMod() {}

 private:
  OpenGLMod *render;
//  void initializeGL() override;
//  void resizeGL(int w, int h) override;
//  void paintGL() override;
//
//  void drawLine();
//  void setProject();
//  void setLineMod();
//  void setLineSize();
//  void setApexMod();
//  void setApexSize();

};

#endif  // S21_RENDER_H