#include "ogl_render.h"

namespace s21 {

void OpenGLMod::updateObject() {
  object_ = &controller_.getObject();
  if (object_ && object_->vertices.size()) {
    update();
  }
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
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClearColor(conf_->color_bg.redF(), conf_->color_bg.greenF(),
               conf_->color_bg.blueF(), conf_->color_bg.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (object_ == nullptr) {
    return;
  }

  glVertexPointer(3, GL_FLOAT, 0, object_->vertices.data());
  glEnableClientState(GL_VERTEX_ARRAY);

  if (conf_->vertex_style != 0) {
    if (conf_->vertex_style == 1) {
      glEnable(GL_POINT_SMOOTH);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    } else {
      glDisable(GL_POINT_SMOOTH);
      glDisable(GL_BLEND);
    }
    glPointSize(static_cast<float>(conf_->vertex_size));
    glColor4f(conf_->color_vertex.redF(), conf_->color_vertex.greenF(),
              conf_->color_vertex.blueF(), conf_->color_vertex.alphaF());
    glDrawArrays(GL_POINTS, 0, object_->getVertices());
  }

  glColor4f(conf_->color_line.redF(), conf_->color_line.greenF(),
            conf_->color_line.blueF(), conf_->color_line.alphaF());

  glLineWidth(static_cast<float>(conf_->line_width));

  if (conf_->line_dashed) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  int size = 3;
  float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
  float heapHeight = size / (2 * tan(fov / 2));
  glTranslatef(0, 0, -3 * heapHeight);

  glDrawElements(GL_LINES, object_->facets.size(), GL_UNSIGNED_INT,
                 object_->facets.data());
  glDisableClientState(GL_VERTEX_ARRAY);
  emit saveSettings();
}


//  int size = 3;
//  float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
//  float heapHeight = size / (2 * tan(fov / 2));
//  glTranslatef(0, 0, -3 * heapHeight);
//  drawObject();
//  emit saveSettings();
//}
//
//void OpenGLMod::drawObject() {
//  if (object_ == nullptr) {
//    return;
//  }
//
//    glVertexPointer(3, GL_FLOAT, 0, object_->vertices.data());
//  glEnableClientState(GL_VERTEX_ARRAY);
//  glDisable(GL_POINT_SMOOTH);
//  glEnable(GL_POINT_SPRITE);
//
//  // Отрисовка точек
//  glDrawArrays(GL_POINTS, 0, object_->getVertices());
//
//  glDrawElements(GL_LINES, object_->facets.size(), GL_UNSIGNED_INT,
//                 object_->facets.data());
//  glDisableClientState(GL_VERTEX_ARRAY);
//  glDisableVertexAttribArray(0);
//  glUseProgram(0);
//}

//void OpenGLMod::paintGL() {
//  glClearColor(conf_->color_bg.redF(), conf_->color_bg.greenF(),
//               conf_->color_bg.blueF(), conf_->color_bg.alphaF());
//  glColor4f(conf_->color_line.redF(), conf_->color_line.greenF(),
//            conf_->color_line.blueF(), conf_->color_line.alphaF());
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//  glLineWidth(static_cast<float>(conf_->line_width));
//
//  if (conf_->line_dashed) {
//    glEnable(GL_LINE_STIPPLE);
//    glLineStipple(10, 0x00FF);
//  } else {
//    glDisable(GL_LINE_STIPPLE);
//  }
//
//  glPointSize(conf_->vertex_size);
//
//  glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//  int size = 3;
//  float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
//  float heapHeight = size / (2 * tan(fov / 2));
//  glLoadIdentity();
//  glTranslatef(0, 0, -3 * heapHeight);
//  drawObject();
//  emit saveSettings();
//}


}  // namespace s21
