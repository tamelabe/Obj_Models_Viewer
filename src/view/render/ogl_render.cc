#include "ogl_render.h"

namespace s21 {

void OpenGLMod::updateObject() {
  object_ = &controller_.getObject();
  if (object_ && object_->facets.size()) update();
}

void OpenGLMod::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void OpenGLMod::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float width = w / 120;
  float height = h / 120;
  float left = -width / 2;
  float right = width / 2;
  float bottom = -height / 2;
  float top = height / 2;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(left, right, bottom, top, -100, 100);
}

void OpenGLMod::paintGL() {
  glClearColor(red_bg_ / 255.0f, green_bg_ / 255.0f, blue_bg_ / 255.0f, alpha_bg_);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  int size = 3;
  float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
  float heapHeight = size / (2 * tan(fov / 2));
  glLoadIdentity();
  glTranslatef(0, 0, -3 * heapHeight);
  drawObject();
}

void OpenGLMod::drawObject() {
  if (object_ == nullptr) return;
  glPointSize(5);
  glVertexPointer(3, GL_FLOAT, 0, object_->vertices.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  glLineWidth(2);
  glDisable(GL_POINT_SMOOTH);
  glEnable(GL_POINT_SPRITE);
  glDisable(GL_LINE_STIPPLE);
  glDrawElements(GL_LINES, object_->facets.size(), GL_UNSIGNED_INT,
                 object_->facets.data());
  glDisableClientState(GL_VERTEX_ARRAY);
}

}  // namespace s21
