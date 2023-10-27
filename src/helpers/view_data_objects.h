#ifndef SRC_VIEW_DATA_OBJECTS_H_
#define SRC_VIEW_DATA_OBJECTS_H_

#include <QColor>

namespace s21 {

struct PaintConfig {
 public:
  QColor color_bg;
  QColor color_line;
  QColor color_vertex;
  double line_width;
  bool line_dashed;
  int vertex_size;
  int vertex_style;         // 0 - none, 1 - ball, 2 - cube
  bool central_projection;  // false - parallel projection
};

}  // namespace s21

#endif  // SRC_VIEW_DATA_OBJECTS_H_
