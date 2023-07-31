#ifndef SRC_DATA_OBJECTS_H_
#define SRC_DATA_OBJECTS_H_

#include <string>
#include <vector>

namespace s21 {

struct GLObject {
 public:
  std::vector<double> vertices{};
  std::vector<unsigned> facets{};
};

struct TransformParams {
 public:
  /**
   * 'm' - move
   * 'r' - rotate
   * 's' - scale
   */
  char pos_type{};
  /**
   * x, y, z
   */
  char axis{};
  double value{};
};



}  // namespace s21

#endif  // SRC_DATA_OBJECTS_H_
