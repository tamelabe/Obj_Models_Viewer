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

void OpenGLMod::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void OpenGLMod::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (conf_->central_projection) {
    glFrustum(-0.74, 0.74, -0.55, 0.55, 1.0, 100.0);

  } else {
    glOrtho(-13.33, 13.33, -10.0, 10.0, 1.0, 100.0);
  }

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
  glTranslatef(0, 0, -20);

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

  glDrawElements(GL_LINES, object_->facets.size(), GL_UNSIGNED_INT,
                 object_->facets.data());
  glDisableClientState(GL_VERTEX_ARRAY);
  emit saveSettings();
}

}  // namespace s21
