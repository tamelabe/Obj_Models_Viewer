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

struct BaseData {
 public:
  int x{};
  int y{};
  int z{};
};

struct ModelStateData {
 public:
  BaseData move;
  BaseData rotate;
  int scale{};
};

struct Edges {
 public:
  double x_min{};
  double y_min{};
  double z_min{};
  double x_max{};
  double y_max{};
  double z_max{};
};




}  // namespace s21

#endif  // SRC_DATA_OBJECTS_H_
